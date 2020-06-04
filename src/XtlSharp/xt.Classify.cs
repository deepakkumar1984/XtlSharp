using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray IsFinite(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.IsFinite);

        public static XArray IsInf(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.IsInf);

        public static XArray IsNan(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.IsNan);

        public static XArray IsClose(XArray a, XArray b, double rtol = 1e-5, double atol = 1e-8, bool equal_nan = false)
            => NativeHelper.IsClose(a, b, rtol, atol, equal_nan);

        public static XArray AllClose(XArray a, XArray b, double rtol = 1e-5, double atol = 1e-8)
            => NativeHelper.AllClose(a, b, rtol, atol);
    }
}
