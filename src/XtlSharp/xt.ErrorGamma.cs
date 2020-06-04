using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Erf(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Erf);

        public static XArray Erfc(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Erfc);

        public static XArray TGamma(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.TGamma);

        public static XArray LGamma(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.LGamma);
    }
}
