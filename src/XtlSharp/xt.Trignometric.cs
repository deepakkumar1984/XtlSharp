using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Sin(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Sin);

        public static XArray Cos(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Cos);

        public static XArray Tan(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Tan);

        public static XArray ASin(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ASin);

        public static XArray ACos(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ACos);

        public static XArray ATan(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ATan);

        public static XArray ATan2(XArray x, XArray y) => NativeHelper.ElementwiseOps(x, y, ElementwiseFunc.ATan2);
    }
}
