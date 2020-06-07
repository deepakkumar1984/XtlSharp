using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace XtlSharp.Native
{
    internal class NativeHelper
    {
        public static void Fill(XArray x, double value)
        {
            NativeWrapper.TS_Fill(x.GetRef(), value);
        }

        public static XArray Cast(XArray a, DType dtype)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_Cast(a.GetRef(), (int)dtype, r.GetRef());
            return r;
        }

        public static XArray ElementwiseOps(XArray a, ElementwiseFunc op)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_Elementwise_1(a.GetRef(), r.GetRef(), (int)op);
            return r;
        }

        public static XArray ElementwiseOps(XArray a, XArray b, ElementwiseFunc op)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_Elementwise_2(a.GetRef(), b.GetRef(), r.GetRef(), (int)op);
            return r;
        }

        public static XArray ElementwiseOps(XArray a, XArray b, XArray c, ElementwiseFunc op)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_Elementwise_3(a.GetRef(), b.GetRef(), c.GetRef(), r.GetRef(), (int)op);
            return r;
        }

        public static XArray BitwiseOps(XArray a, XArray b, ElementwiseFunc op)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_Elementwise_2_Bitwise(a.GetRef(), b.GetRef(), r.GetRef(), (int)op);
            return r;
        }

        public static XArray Pow(XArray x, double value)
        {
            XArray r = new XArray(x.Shape, x.DataType);
            NativeWrapper.TS_Pow(x.GetRef(), value, r.GetRef());
            return r;
        }

        public static XArray Clip(XArray x, double min, double max)
        {
            XArray r = new XArray(x.Shape, x.DataType);
            NativeWrapper.TS_Clip(x.GetRef(), min, max, r.GetRef());
            return r;
        }

        public static XArray IsClose(XArray a, XArray b, double rtol = 1e-5, double atol = 1e-8, bool equal_nan = false)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_IsClose(a.GetRef(), b.GetRef(), rtol, atol, equal_nan, r.GetRef());
            return r;
        }

        public static XArray AllClose(XArray a, XArray b, double rtol = 1e-5, double atol = 1e-8)
        {
            XArray r = new XArray(a.Shape, a.DataType);
            NativeWrapper.TS_AllClose(a.GetRef(), b.GetRef(), rtol, atol, r.GetRef());
            return r;
        }

        public static XArray Reduce(XArray x, int[] axes, double p1, int p2, int p3, ReduceFunc op)
        {
            unsafe 
            {
                List<long> newshape = new List<long>();
                for(int i = 0; i< x.Shape.Data.Length;i++)
                {
                    if (!axes.Contains(i))
                        newshape.Add(x.Shape[i]);
                    else
                        newshape.Add(1);
                }

                fixed (int* axes_ptr = axes)
                {
                    XArray r = new XArray(new Shape(newshape.ToArray()), x.DataType);
                    NativeWrapper.TS_Reduce(x.GetRef(), axes_ptr, axes.Length, r.GetRef(), p1, p2, p3, (int)op);
                    return r;
                }
                
            }
        }

        public static XArray ReduceAll(XArray x, ReduceFunc op, double p1 = 0, int p2 = 0)
        {
            XArray r = new XArray(new Shape(1), x.DataType);
            NativeWrapper.TS_ReduceAll(x.GetRef(), r.GetRef(), (int)op, p1, p2);
            return r;
        }

        public static XArray Accumulating(XArray x, int axis, ReduceFunc op)
        {
            List<long> newshape = new List<long>();
            for (int i = 0; i < x.Shape.Data.Length; i++)
            {
                if (i != axis)
                    newshape.Add(x.Shape[i]);
                else
                    newshape.Add(1);
            }

            XArray r = new XArray(new Shape(newshape.ToArray()), x.DataType);
            NativeWrapper.TS_Accumulating(x.GetRef(), axis, r.GetRef(), (int)op);
            return r;
        }
    }
}
