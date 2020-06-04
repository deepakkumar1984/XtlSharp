using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Ceil(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Ceil);

        public static XArray Floor(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Floor);

        public static XArray Trunc(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Trunc);

        public static XArray Round(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Round);

        public static XArray NearByInt(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.NearByInt);

        public static XArray RInt(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.RInt);
    }
}
