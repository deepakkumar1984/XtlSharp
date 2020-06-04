using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Exp(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Exp);

        public static XArray Exp2(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Exp2);

        public static XArray Expm1(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Expm1);

        public static XArray Log(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Log);

        public static XArray Log2(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Log2);

        public static XArray Log10(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Log10);

        public static XArray Log1p(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Log1p);
    }
}
