using System;
using System.Collections.Generic;
using System.Text;

namespace XtlSharp.Native
{
    internal class NativeHelper
    {
        public static void Fill(XArray x, double value)
        {
            NativeWrapper.TS_Fill(x.GetRef(), value);
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
    }
}
