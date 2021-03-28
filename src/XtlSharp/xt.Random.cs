using System;
using System.Collections.Generic;
using System.Text;
using XtlSharp.Native;

namespace XtlSharp
{
    public partial class Random
    {
        public void Seed(int seed)
        {
            NativeHelper.RandomSeed(seed);
        }

        public XArray Rand(Shape shape, DType dtype = DType.Float32)
        {
            return Uniform(shape, 0, 1, dtype);
        }

        public XArray Uniform(Shape shape, double low = 0, double high = 1, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomRand(shape, low, high, dtype);
        }

        public XArray RandInt(Shape shape, double low = 0, double high = 1, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomRandInt(shape, low, high, dtype);
        }

        public XArray Randn(Shape shape, double mean = 0, double std_dev = 1, DType dtype = DType.Float32)
        {
            XArray r = new XArray(shape, dtype);
            NativeWrapper.TS_Random_Randn(r.GetRef(), mean, std_dev);
            return r;
        }

        public XArray Binomial(Shape shape, int trials, double prob, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomBinomial(shape, trials, prob, dtype);
        }

        public XArray Geometric(Shape shape, double prob, DType dtype = DType.Int32)
        {
            return NativeHelper.RandomGeometric(shape, prob, dtype);
        }

        public XArray NegativeBinomial(Shape shape, int k, double prob, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomNegativeBinomial(shape, k, prob, dtype);
        }

        public XArray Poisson(Shape shape, double rate, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomPoisson(shape, rate, dtype);
        }

        public XArray Exponential(Shape shape, double rate, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomExponential(shape, rate, dtype);
        }

        public XArray Gamma(Shape shape, double alpha, double beta, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomGamma(shape, alpha, beta, dtype);
        }

        public XArray Weibull(Shape shape, double a, double b, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomWeibull(shape, a, b, dtype);
        }

        public XArray ExtremeValue(Shape shape, double a, double b, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomExtremeValue(shape, a, b, dtype);
        }

        public XArray LogNormal(Shape shape, double mean, double std_dev, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomLogNormal(shape, mean, std_dev, dtype);
        }

        public XArray Cauchy(Shape shape, double a, double b, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomCauchy(shape, a, b, dtype);
        }

        public XArray FisherF(Shape shape, double m, double n, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomFisherF(shape, m, n, dtype);
        }

        public XArray StudentT(Shape shape, double n, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomStudentT(shape, n, dtype);
        }

        public XArray Choice(Shape shape, int n, bool replace = true, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomChoice(shape, n, replace, dtype);
        }

        public XArray Choice(Shape shape, int n, XArray weight, bool replace = true, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomChoice(shape, n, weight, replace, dtype);
        }

        public XArray Shuffle(Shape shape, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomShuffle(shape, dtype);
        }

        public XArray Permutation(Shape shape, DType dtype = DType.Float32)
        {
            return NativeHelper.RandomPermutation(shape, dtype);
        }
    }
}
