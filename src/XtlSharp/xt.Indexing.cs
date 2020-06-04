using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Where(XArray cond, XArray x, XArray y)
        {
            return NativeHelper.ElementwiseOps(cond, x, y, ElementwiseFunc.Where);
        }

        public static XArray Any(XArray x)
        {
            return NativeHelper.ElementwiseOps(x, ElementwiseFunc.Any);
        }

        public static XArray All(XArray x)
        {
            return NativeHelper.ElementwiseOps(x, ElementwiseFunc.All);
        }
    }
}
