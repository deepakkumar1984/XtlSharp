using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class xt
    {
        public static XArray Sum(XArray x, params int[] axes)
        {
            if(axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Sum);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Sum);
        }

        public static XArray Prod(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Prod);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Prod);
        }

        public static XArray Mean(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Mean);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Mean);
        }

        public static XArray Variance(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Variance);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Variance);
        }

        public static XArray StdDev(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.StdDev);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.StdDev);
        }

        public static XArray Diff(XArray x, int n, int axis = -1)
        {
            return NativeHelper.Reduce(x, new int[1] { 0 }, 0, n, axis, ReduceFunc.Diff);
        }

        public static XArray Amax(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Amax);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Amax);
        }

        public static XArray Amin(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.Amin);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.Amin);
        }

        public static XArray Trapz(XArray x, double dx = 1, int axis = -1)
        {
            return NativeHelper.Reduce(x, new int[1] { 0 }, dx, 0, axis, ReduceFunc.Trapz);
        }

        public static XArray NormL0(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.NormL0);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormL0);
        }

        public static XArray NormL1(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.NormL1);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormL1);
        }

        public static XArray NormL2(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.NormL2);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormL2);
        }

        public static XArray NormLinf(XArray x, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, 0, 0, 0, ReduceFunc.NormLinf);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormLinf);
        }

        public static XArray NormLp2P(XArray x, double p, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, p, 0, 0, ReduceFunc.NormLp2P);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormLp2P, p);
        }

        public static XArray NormLp(XArray x, double p, params int[] axes)
        {
            if (axes.Length > 0)
            {
                return NativeHelper.Reduce(x, axes, p, 0, 0, ReduceFunc.NormLp);
            }

            return NativeHelper.ReduceAll(x, ReduceFunc.NormLp, p);
        }

        public static XArray CumSum(XArray x, int? axis = null)
        {
            if (axis.HasValue)
            {
                return NativeHelper.Accumulating(x, axis.Value, ReduceFunc.CumSum);
            }

            return NativeHelper.Accumulating(x, -9999, ReduceFunc.CumSum);
        }

        public static XArray CumProd(XArray x, int? axis = null)
        {
            if (axis.HasValue)
            {
                return NativeHelper.Accumulating(x, axis.Value, ReduceFunc.CumProd);
            }

            return NativeHelper.Accumulating(x, -9999, ReduceFunc.CumProd);
        }

        public static XArray NanCumSum(XArray x, int? axis = null)
        {
            if (axis.HasValue)
            {
                return NativeHelper.Accumulating(x, axis.Value, ReduceFunc.NanCumSum);
            }

            return NativeHelper.Accumulating(x, -9999, ReduceFunc.NanCumSum);
        }

        public static XArray NanCumProd(XArray x, int? axis = null)
        {
            if (axis.HasValue)
            {
                return NativeHelper.Accumulating(x, axis.Value, ReduceFunc.NanCumProd);
            }

            return NativeHelper.Accumulating(x, -9999, ReduceFunc.NanCumProd);
        }

        public static XArray Nan2Num(XArray x, int? axis = null)
        {
            return NativeHelper.ReduceAll(x, ReduceFunc.Nan2Num);
        }
    }
}
