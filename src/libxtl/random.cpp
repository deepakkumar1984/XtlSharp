
#include "random.h"
#include <type_traits>

#if !defined(ARRAY_SIZE)
    #define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#endif

template<typename T>
INLINE_FUNC void RandApply(TensorRef* r, double lower, double upper)
{
	auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
	r_t = xt::random::rand(r->getShape(), lower, upper);
}

template<typename T>
INLINE_FUNC void RandNApply(TensorRef* r, double mean, double std_dev)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::randn(r->getShape(), mean, std_dev);
}

template<typename T>
INLINE_FUNC void BinomialApply(TensorRef* r, int trials, double prob)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::binomial(r->getShape(), trials, prob);
}

template<typename T>
INLINE_FUNC void GeometricApply(TensorRef* r, double prob)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::geometric<T>(r->getShape(), prob);
}

template<typename T>
INLINE_FUNC void NegativeBinomialApply(TensorRef* r, int k, double prob)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::negative_binomial(r->getShape(), k, prob);
}

template<typename T>
INLINE_FUNC void PoissonApply(TensorRef* r, double rate)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::poisson<T>(r->getShape(), rate);
}

template<typename T>
INLINE_FUNC void CauchyApply(TensorRef* r, double alpha, double beta)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::cauchy(r->getShape(), alpha, beta);
}

template<typename T>
INLINE_FUNC void ChiSquaredApply(TensorRef* r,  double deg)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::chi_squared(r->getShape(), deg);
}

template<typename T>
INLINE_FUNC void ChoiceApply(TensorRef* r, int n, bool replace = true)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::choice(r_t, n, replace);
}

template<typename T>
INLINE_FUNC void ExponentialApply(TensorRef* r, double rate)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::exponential(r->getShape(), rate);
}

template<typename T>
INLINE_FUNC void GammaApply(TensorRef* r, double alpha, double beta)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::gamma(r->getShape(), alpha, beta);
}

template<typename T>
INLINE_FUNC void WeibullApply(TensorRef* r, double a, double b)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::weibull(r->getShape(), a, b);
}

template<typename T>
INLINE_FUNC void ExtremeValueApply(TensorRef* r, double a, double b)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::extreme_value(r->getShape(), a, b);
}

template<typename T>
INLINE_FUNC void LogNormalApply(TensorRef* r, double mean, double std_dev)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::lognormal(r->getShape(), mean, std_dev);
}

template<typename T>
INLINE_FUNC void FisherFApply(TensorRef* r, double m, double n)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::fisher_f(r->getShape(), m, n);
}

template<typename T>
INLINE_FUNC void StudentTApply(TensorRef* r, double n)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::student_t(r->getShape(), n);
}

template<typename T>
INLINE_FUNC void ShuffleApply(TensorRef* r)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    xt::random::shuffle(r_t);
}

template<typename T>
INLINE_FUNC void PermutationApply(TensorRef* r)
{
    auto r_t = xt::adapt((T*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
    r_t = xt::random::permutation(r_t);
}

OPS_API int TS_RandomSeed(int seed)
{
	xt::random::seed(seed);
	return 0;
}

OPS_API int TS_Random_Rand(TensorRef* result, double lower, double upper)
{
	API_BEGIN()
	SWITCH_TENSOR_TYPE_ALL_CPU(result->elementType, RandApply, result, lower, upper)
	API_END()
}

OPS_API int TS_Random_RandInt(TensorRef* result, double lower, double upper)
{
	API_BEGIN()
    SWITCH_TENSOR_TYPE_ALL_CPU(result->elementType, RandApply, result, lower, upper)
    API_END()
}

OPS_API int TS_Random_Randn(TensorRef* r, double mean, double std_dev)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, RandNApply, r, mean, std_dev)
    API_END()
}

OPS_API int TS_Random_Binomial(TensorRef* r, int trials, double prob)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, BinomialApply, r, trials, prob)
    API_END()
}

OPS_API int TS_Random_Geometric(TensorRef* r, double prob)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_NUM_CPU(r->elementType, GeometricApply, r, prob)
    API_END()
}

OPS_API int TS_Random_NegativeBinomial(TensorRef* r, int k, double prob)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, NegativeBinomialApply, r, k, prob)
    API_END()
}

OPS_API int TS_Random_Poisson(TensorRef* r, double rate)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_NUM_CPU(r->elementType, PoissonApply, r, rate)
    API_END()
}

OPS_API int TS_Random_Exponential(TensorRef* r, double rate)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, ExponentialApply, r, rate)
    API_END()
}

OPS_API int TS_Random_Gamma(TensorRef* r, double alpha, double beta)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, GammaApply, r, alpha, beta)
    API_END()
}

OPS_API int TS_Random_Weibull(TensorRef* r, double a, double b)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, WeibullApply, r, a, b)
    API_END()
}

OPS_API int TS_Random_ExtremeValue(TensorRef* r, double a, double b)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, ExtremeValueApply, r, a, b)
    API_END()
}

OPS_API int TS_Random_LogNormal(TensorRef* r, double mean, double std_dev)
{
    API_BEGIN()
        SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, LogNormalApply, r, mean, std_dev)
    API_END()
}
