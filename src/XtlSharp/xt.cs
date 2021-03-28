using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static Random random = new Random();

        public static XArray Add(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Add);
        }

        public static XArray Sub(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Sub);
        }

        public static XArray Mul(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Mul);
        }

        public static XArray Div(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Div);
        }

        public static XArray LogicalAnd(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.LogicalAnd);
        }

        public static XArray LogicalOr(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.LogicalOr);
        }

        public static XArray LogicalNot(XArray x)
        {
            return NativeHelper.ElementwiseOps(x, ElementwiseFunc.LogicalNot);
        }

        public static XArray Greater(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Greater);
        }

        public static XArray GreaterEqual(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.GreaterEqual);
        }

        public static XArray Less(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Less);
        }

        public static XArray LessEqual(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.LessEqual);
        }

        public static XArray Eq(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.Eq);
        }

        public static XArray NotEq(XArray lhs, XArray rhs)
        {
            return NativeHelper.ElementwiseOps(lhs, rhs, ElementwiseFunc.NotEq);
        }

        public static XArray Cast(XArray x, DType dtype)
        {
            return NativeHelper.Cast(x, dtype);
        }

        public static XArray BitwiseAnd(XArray lhs, XArray rhs)
        {
            return NativeHelper.BitwiseOps(lhs, rhs, ElementwiseFunc.BitwiseAnd);
        }

        public static XArray BitwiseOr(XArray lhs, XArray rhs)
        {
            return NativeHelper.BitwiseOps(lhs, rhs, ElementwiseFunc.BitwiseOr);
        }

        public static XArray BitwiseXor(XArray lhs, XArray rhs)
        {
            return NativeHelper.BitwiseOps(lhs, rhs, ElementwiseFunc.BitwiseXor);
        }

        public static XArray BitwiseNot(XArray x)
        {
            return NativeHelper.BitwiseOps(x, new XArray(new Shape(1)), ElementwiseFunc.BitwiseNot);
        }

        public static XArray BitwiseLeftShift(XArray lhs, XArray rhs)
        {
            return NativeHelper.BitwiseOps(lhs, rhs, ElementwiseFunc.BitwiseLeftShift);
        }

        public static XArray BitwiseRightShift(XArray lhs, XArray rhs)
        {
            return NativeHelper.BitwiseOps(lhs, rhs, ElementwiseFunc.BitwiseRightShift);
        }
    }
}
