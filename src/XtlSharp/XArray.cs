using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class XArray : IDisposable
    {
        /// <summary>
        /// The sizes
        /// </summary>
        public Shape Shape { get; set; }

        public DType DataType
        {
            get
            {
                return dtype;
            }
        }

        /// <summary>
        /// The strides
        /// </summary> 
        private long[] strides;
       
        /// <summary>
        /// The storage offset
        /// </summary>
        private long storageOffset;

        /// <summary>
        /// The is disposed
        /// </summary>
        private bool isDisposed = false;

        private readonly DType dtype;

        public IntPtr NativePtr
        {
            get;
            set;

        }

        public XArray(Array data)
        {
            GCHandle gch = GCHandle.Alloc(data, GCHandleType.Pinned);
            NativePtr = gch.AddrOfPinnedObject();
            gch.Free();

            long[] shape = new long[data.Rank];
            for (int i = 0; i < shape.Length; i++)
                shape[i] = data.GetLength(i);

            dtype = DTypeBuilder.FromCLRType(data.GetType());
            Shape = new Shape(shape);
            strides = GetContiguousStride(Shape.Data);
        }

        public XArray(Shape shape, DType dtype = DType.Float32)
        {
            Shape = shape;
            this.dtype = dtype;
            strides = GetContiguousStride(Shape.Data);
            long byteSize = dtype.Size() * shape.Size;
            NativePtr = Marshal.AllocHGlobal(new IntPtr(byteSize));
        }

        internal XArray(long[] sizes, long[] strides, IntPtr ptr, DType dtype)
        {
            this.Shape = new Shape(sizes);
            this.strides = strides;
            this.NativePtr = ptr;
            this.dtype = dtype;
        }

        private static long[] GetContiguousStride(long[] dims)
        {
            long acc = 1;
            var stride = new long[dims.Length];
            for (int i = dims.Length - 1; i >= 0; --i)
            {
                stride[i] = acc;
                acc *= dims[i];
            }

            return stride;
        }

        public Array ToArray()
        {
            long arraySize = Shape.Size;

            Array result = Array.CreateInstance(DataType.ToCLRType(), Shape.Data);
            var bytecount = DataType.Size() * arraySize;
            var datagch = GCHandle.Alloc(result, GCHandleType.Pinned);
            unsafe
            {
                Buffer.MemoryCopy(NativePtr.ToPointer(), datagch.AddrOfPinnedObject().ToPointer(), bytecount, bytecount);
            }

            datagch.Free();

            return result;
        }

        public bool IsContiguous()
        {
            long z = 1;
            for (int d = Shape.Dimension - 1; d >= 0; d--)
            {
                if (Shape[d] != 1)
                {
                    if (strides[d] == z)
                        z *= Shape[d];
                    else
                        return false;
                }
            }
            return true;
        }

        public void Dispose()
        {
            Marshal.FreeHGlobal(NativePtr);
        }

        

        public object this[long index]
        {
            get
            {
                return GetValue(index);
            }
            set
            {
                SetValue(index, value);
            }
        }

        public XArray this[params object[] items]
        {
            get
            {
                return this;
            }
            //set
            //{
            //    this = value;
            //}
        }

        internal static XArray FromRef(XArrayRef tensorRef)
        {
            long[] shape_data = new long[tensorRef.dimCount];
            Marshal.Copy(tensorRef.sizes, shape_data, 0, shape_data.Length);
            Shape shape = new Shape(shape_data);
            XArray result = new XArray(shape, tensorRef.elementType);
            result.NativePtr = tensorRef.buffer;

            return result;
        }

        public IntPtr GetRef()
        {
            var tensorRef = AllocTensorRef(this);
            var tensorPtr = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(XArrayRef)));
            Marshal.StructureToPtr(tensorRef, tensorPtr, false);

            return tensorPtr;
        }

        internal XArrayRef AllocTensorRef(XArray tensor)
        {
            var tensorRef = new XArrayRef();
            tensorRef.buffer = GetBufferStart(tensor);
            tensorRef.dimCount = tensor.Shape.Length;
            tensorRef.sizes = AllocArray(tensor.Shape.Data);
            tensorRef.strides = AllocArray(tensor.strides);
            tensorRef.elementType = tensor.DataType;
            return tensorRef;
        }

        private IntPtr AllocArray(long[] data)
        {
            var result = Marshal.AllocHGlobal(sizeof(long) * data.Length);
            Marshal.Copy(data, 0, result, data.Length);
            return result;
        }

        /// <summary>
        /// Frees the tensor reference.
        /// </summary>
        /// <param name="tensorRef">The tensor reference.</param>
        internal void FreeTensorRef(XArrayRef tensorRef)
        {
            Marshal.FreeHGlobal(tensorRef.sizes);
            Marshal.FreeHGlobal(tensorRef.strides);
        }

        public IntPtr GetBufferStart(XArray tensor)
        {
            return PtrAdd(NativePtr, tensor.storageOffset * tensor.DataType.Size());
        }

        /// <summary>
        /// PTRs the add.
        /// </summary>
        /// <param name="ptr">The PTR.</param>
        /// <param name="offset">The offset.</param>
        /// <returns>IntPtr.</returns>
        private IntPtr PtrAdd(IntPtr ptr, long offset)
        {
            return new IntPtr(ptr.ToInt64() + offset);
        }


        private XArray View(params long[] sizes)
        {
            if (!this.IsContiguous()) throw new InvalidOperationException("Cannot use View on a non-contiguous tensor");

            Shape new_shape = new Shape(sizes);
            if (this.Shape.Size != new_shape.Size)
            {
                throw new InvalidOperationException("Output tensor must have the same number of elements as the input");
            }

            return new XArray(sizes, GetContiguousStride(sizes), this.NativePtr, this.dtype);
        }

        public XArray Reshape(params long[] sizes)
        {
            if (!this.IsContiguous()) throw new InvalidOperationException("Cannot use View on a non-contiguous tensor");

            Shape new_shape = new Shape(sizes);
            long prod = -1 * new_shape.Size;
            for (int i = 0; i < sizes.Length; i++)
            {
                if (sizes[i] == -1)
                {
                    sizes[i] = Shape.Size / prod;
                    break;
                }
            }

            return View(sizes);
        }

        public XArray Ravel()
        {
            return View(Shape.Size);
        }

        public void Fill(double value)
        {
            NativeHelper.Fill(this, value);
        }

        public XArray Slice(int dimension, long startIndex, long size)
        {
            if (dimension < 0 || dimension >= Shape.Dimension) throw new ArgumentOutOfRangeException("dimension");
            if (startIndex < 0 || startIndex >= Shape[dimension]) throw new ArgumentOutOfRangeException("startIndex");
            if (size <= 0 || startIndex + size > Shape[dimension]) throw new ArgumentOutOfRangeException("size");

            var newOffset = (storageOffset + startIndex * strides[dimension]) * DataType.Size();
            var newSizes = Shape.Data;
            newSizes[dimension] = size;
            var n = new IntPtr(NativePtr.ToInt64() + newOffset);
            return new XArray(newSizes, strides, n, this.dtype);
        }

        private T GetValue<T>(long index)
        {
            return (T)GetValue(index);
        }

        private object GetValue(long index)
        {
            unsafe
            {
                if (DataType == DType.Float32) return ((float*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Float64) return ((double*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Float128) return ((decimal*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Int8) return ((sbyte*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Int16) return ((short*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Int32) return ((int*)NativePtr.ToPointer())[index];
                else if (DataType == DType.Int64) return ((long*)NativePtr.ToPointer())[index];
                else if (DataType == DType.UInt8) return ((byte*)NativePtr.ToPointer())[index];
                else if (DataType == DType.UInt16) return ((ushort*)NativePtr.ToPointer())[index];
                else if (DataType == DType.UInt32) return ((uint*)NativePtr.ToPointer())[index];
                else if (DataType == DType.UInt64) return ((ulong*)NativePtr.ToPointer())[index];
                else
                    throw new NotSupportedException("Element type " + DataType + " not supported");
            }
        }

        private void SetValue(long index, object value)
        {
            unsafe
            {
                if (DataType == DType.Float32) ((float*)NativePtr.ToPointer())[index] = (float)value;
                else if (DataType == DType.Float64) ((double*)NativePtr.ToPointer())[index] = (double)value;
                else if (DataType == DType.Float128) ((decimal*)NativePtr.ToPointer())[index] = (decimal)value;
                else if (DataType == DType.Int8) ((sbyte*)NativePtr.ToPointer())[index] = (sbyte)value;
                else if (DataType == DType.Int16) ((short*)NativePtr.ToPointer())[index] = (short)value;
                else if (DataType == DType.Int32) ((int*)NativePtr.ToPointer())[index] = (int)value;
                else if (DataType == DType.Int64) ((long*)NativePtr.ToPointer())[index] = (long)value;
                else if (DataType == DType.UInt8) ((byte*)NativePtr.ToPointer())[index] = (byte)value;
                else if (DataType == DType.Int16) ((ushort*)NativePtr.ToPointer())[index] = (ushort)value;
                else if (DataType == DType.Int32) ((uint*)NativePtr.ToPointer())[index] = (uint)value;
                else if (DataType == DType.Int64) ((ulong*)NativePtr.ToPointer())[index] = (ulong)value;
                else
                    throw new NotSupportedException("Element type " + DataType + " not supported");
            }
        }

        public List<T> ToList<T>()
        {
            throw new NotImplementedException();
        }

        public byte[] ToBytes()
        {
            throw new NotImplementedException();
        }

        public void ToFile(string file, string sep = "")
        {
            throw new NotImplementedException();
        }

        public void Dump(string file)
        {
            throw new NotImplementedException();
        }

        public string Dumps()
        {
            throw new NotImplementedException();
        }

        public XArray Astype(DType dtype)
        {
            throw new NotImplementedException();
        }

        public XArray Copy()
        {
            throw new NotImplementedException();
        }

        public void Resize(Shape new_shape)
        {
            throw new NotImplementedException();
        }

        public XArray Transpose(params int[] axes)
        {
            throw new NotImplementedException();
        }

        public XArray SwapAxes(int axis1, int axis2)
        {
            throw new NotImplementedException();
        }

        public XArray Flatten()
        {
            throw new NotImplementedException();
        }

        public XArray Squeeze(int axis)
        {
            throw new NotImplementedException();
        }

        public XArray Take(XArray indices, int axis = -1, string mode = "raise")
        {
            throw new NotImplementedException();
        }

        public XArray Put(XArray indices, XArray v, string mode = "raise")
        {
            throw new NotImplementedException();
        }

        public XArray Repeat(int repeats, int axis = -1)
        {
            throw new NotImplementedException();
        }

        public XArray Choose(XArray choices, string mode = "raise")
        {
            throw new NotImplementedException();
        }

        public XArray Sort(int axis = -1)
        {
            throw new NotImplementedException();
        }

        public XArray ArgSort(int axis = -1)
        {
            throw new NotImplementedException();
        }

        public XArray Partition(XArray kth, int axis = -1)
        {
            throw new NotImplementedException();
        }

        public XArray ArgPartition(XArray kth, int axis = -1)
        {
            throw new NotImplementedException();
        }

        public XArray SearchSorted(XArray v, string side = "")
        {
            throw new NotImplementedException();
        }

        public XArray NonZero()
        {
            throw new NotImplementedException();
        }

        public XArray Diagonal(int offset = 0, int axis1 = 0, int axis2 = 1)
        {
            throw new NotImplementedException();
        }

        public XArray Compress(int axis)
        {
            throw new NotImplementedException();
        }

        public XArray Max(int axis, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray Min(int axis, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray Argmax(int axis)
        {
            throw new NotImplementedException();
        }

        public XArray Argmin(int axis)
        {
            throw new NotImplementedException();
        }

        public XArray Clip(double min, double max)
        {
            throw new NotImplementedException();
        }

        public XArray Conj()
        {
            throw new NotImplementedException();
        }

        public XArray Round(int decimals = 0)
        {
            throw new NotImplementedException();
        }

        public XArray Sum(int axis = -1, DType dtype = DType.Float32, bool  keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray CumSum(int axis = -1, DType dtype = DType.Float32)
        {
            throw new NotImplementedException();
        }

        public XArray Mean(int axis = -1, DType dtype = DType.Float32, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray Var(int axis = -1, DType dtype = DType.Float32, double ddof = 0, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray Std(int axis = -1, DType dtype = DType.Float32, double ddof = 0, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray Prod(int axis = -1, DType dtype = DType.Float32, bool keepdims = true)
        {
            throw new NotImplementedException();
        }

        public XArray CumProd(int axis = -1, DType dtype = DType.Float32)
        {
            throw new NotImplementedException();
        }

        public bool All(int axis = -1, bool keepdims = true, XArray where = null)
        {
            throw new NotImplementedException();
        }

        public bool Any(int axis = -1, bool keepdims = true, XArray where = null)
        {
            throw new NotImplementedException();
        }

        #region Operators
        public static XArray operator +(XArray lhs, XArray rhs)
        {
            return xt.Add(lhs, rhs);
        }

        public static XArray operator +(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return lhs + rhs_t;
        }

        public static XArray operator +(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return lhs_t + rhs;
        }

        public static XArray operator -(XArray lhs, XArray rhs)
        {
            return xt.Sub(lhs, rhs);
        }

        public static XArray operator -(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return lhs - rhs_t;
        }

        public static XArray operator -(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return lhs_t - rhs;
        }

        public static XArray operator *(XArray lhs, XArray rhs)
        {
            return xt.Mul(lhs, rhs);
        }

        public static XArray operator *(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return lhs * rhs_t;
        }

        public static XArray operator *(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return lhs_t * rhs;
        }

        public static XArray operator /(XArray lhs, XArray rhs)
        {
            return xt.Div(lhs, rhs);
        }

        public static XArray operator /(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return lhs / rhs_t;
        }

        public static XArray operator /(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return lhs_t / rhs;
        }

        public static XArray operator -(XArray x)
        {
            return x * -1;
        }

        public static XArray operator %(XArray lhs, XArray rhs)
        {
            return xt.FMod(lhs, rhs);
        }

        public static XArray operator %(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.FMod(lhs, rhs_t);
        }

        public static XArray operator %(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return xt.FMod(lhs_t, rhs);
        }

        public static XArray operator <<(XArray lhs, int rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.BitwiseLeftShift(lhs, rhs_t);
        }

        public static XArray operator >>(XArray lhs, int rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.BitwiseRightShift(lhs, rhs_t);
        }

        public static XArray operator &(XArray lhs, XArray rhs)
        {
            return xt.BitwiseAnd(lhs, rhs);
        }

        public static XArray operator &(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.BitwiseAnd(lhs, rhs_t);
        }

        public static XArray operator &(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return xt.BitwiseAnd(lhs_t, rhs);
        }

        public static XArray operator |(XArray lhs, XArray rhs)
        {
            return xt.BitwiseOr(lhs, rhs);
        }

        public static XArray operator |(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.BitwiseOr(lhs, rhs_t);
        }

        public static XArray operator |(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return xt.BitwiseOr(lhs_t, rhs);
        }

        public static XArray operator ^(XArray lhs, XArray rhs)
        {
            return xt.BitwiseXor(lhs, rhs);
        }

        public static XArray operator ^(XArray lhs, double rhs)
        {
            XArray rhs_t = new XArray(lhs.Shape, lhs.DataType);
            rhs_t.Fill(rhs);
            return xt.BitwiseXor(lhs, rhs_t);
        }

        public static XArray operator ^(double lhs, XArray rhs)
        {
            XArray lhs_t = new XArray(rhs.Shape, rhs.DataType);
            lhs_t.Fill(lhs);
            return xt.BitwiseXor(lhs_t, rhs);
        }
        #endregion
    }
}
