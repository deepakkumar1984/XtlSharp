using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Pow(XArray x, double scalar) => NativeHelper.Pow(x, scalar);

        public static XArray Sqrt(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Sqrt);

        public static XArray Cbrt(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Cbrt);

        public static XArray Hypot(XArray a, XArray b) => NativeHelper.ElementwiseOps(a, b, ElementwiseFunc.Hypot);
    }
}
