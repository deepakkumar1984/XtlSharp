using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Sinh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Sinh);

        public static XArray Cosh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Cosh);

        public static XArray Tanh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.Tanh);

        public static XArray ASinh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ASinh);

        public static XArray ACosh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ACosh);

        public static XArray ATanh(XArray x) => NativeHelper.ElementwiseOps(x, ElementwiseFunc.ATanh);
    }
}
