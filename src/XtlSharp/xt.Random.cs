using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class Random
    {
        public static void Seed(int seed)
        {
            NativeHelper.RandomSeed(seed);
        }

        public static XArray Rand(Shape shape, double low, double high, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomRand(shape, low, high, dtype);
        }

    }
}
