using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Abs(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Abs);

        public static XArray FAbs(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.FAbs);

        public static XArray FMod(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.FMod);

        public static XArray Remainder(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.Remainder);

        public static XArray Fma(XArray a, XArray b, XArray c) => NativeHelper.ElementwiseOps(a, b, c, ElementwiseFunc.Fma);

        public static XArray Minimum(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.Minimum);

        public static XArray Maximum(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.Maximum);

        public static XArray FDim(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.FDim);

        public static XArray Clip(XArray x, double min, double max) => NativeHelper.Clip(x, min, max);

        public static XArray Sign(XArray x) => throw new NotImplementedException();
    }
}
