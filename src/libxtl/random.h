#pragma once

#include "general.h"
#include "xtensor/xrandom.hpp"

OPS_API int TS_RandomSeed(int seed);
OPS_API int TS_Random_Rand(TensorRef* r, double lower, double upper);
OPS_API int TS_Random_RandInt(TensorRef* r, double lower, double upper);
OPS_API int TS_Random_Randn(TensorRef* r, double mean, double std_dev);
OPS_API int TS_Random_Binomial(TensorRef* r, int trials, double prob);
OPS_API int TS_Random_Geometric(TensorRef* r, double prob);
OPS_API int TS_Random_NegativeBinomial(TensorRef* r, int k, double prob);
OPS_API int TS_Random_Poisson(TensorRef* r, double rate);
OPS_API int TS_Random_Exponential(TensorRef* r, double rate);
OPS_API int TS_Random_Gamma(TensorRef* r, double alpha, double beta);
OPS_API int TS_Random_Weibull(TensorRef* r, double a, double b);
OPS_API int TS_Random_ExtremeValue(TensorRef* r, double a, double b);
OPS_API int TS_Random_LogNormal(TensorRef* r, double mean, double std_dev);
OPS_API int TS_Random_Cauchy(TensorRef* r, double a, double b);
OPS_API int TS_Random_FisherF(TensorRef* r, double m, double n);
OPS_API int TS_Random_StudentT(TensorRef* r, double n);
OPS_API int TS_Random_Choice(TensorRef* r, int n, bool replace);
OPS_API int TS_Random_ChoiceWithWeight(TensorRef* r, int n, TensorRef* w, bool replace);
OPS_API int TS_Random_Shuffle(TensorRef* r);
OPS_API int TS_Random_Permutation(TensorRef* r);