#pragma once
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "xtensor/xadapt.hpp"
#include "xtensor/xexpression.hpp"
#include "TensorRef.h"
#define uint8 unsigned __int8

#ifdef _WIN32

#define OPS_API extern "C" __declspec(dllexport)
#define INLINE_FUNC __inline

#else

#define OPS_API extern "C"
#define INLINE_FUNC inline

#endif

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

OPS_API const char* TS_GetLastError();
OPS_API void TS_SetLastError(char* message);

#define RESULT_OK 0
#define RESULT_ERROR -1

class TSError
{
public:
    char* message;

    TSError(char* message) { this->message = message; }
};

#define API_BEGIN() try {
#define API_END() } catch(TSError &_except_) { TS_SetLastError(_except_.message); return -1; } return 0;
#define API_BEGIN_TS() TensorRef* ret = new TensorRef(); try {
#define API_END_TS() } catch(TSError &_except_) { TS_SetLastError(_except_.message); return ret; } return ret;

INLINE_FUNC void Assert(bool condition, char* message) {
    if (!condition) { throw TSError(message); }
}

template<typename T>
xt::xarray<T> Ref2Array(TensorRef* x)
{
    return xt::adapt((T*)x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
}


#define SWITCH_TENSOR_TYPE_ALL_CPU(ELEMENTTYPE, FUNCTION, ...)\
	switch (ELEMENTTYPE)\
	{\
	case DType::Float32: FUNCTION<float>(__VA_ARGS__); break;\
	case DType::Float64: FUNCTION<double>(__VA_ARGS__); break;\
	case DType::Int32: FUNCTION<__int32>(__VA_ARGS__); break;\
	case DType::UInt8: FUNCTION<uint8>(__VA_ARGS__); break;\
	default:\
		throw TSError("Tensor type not supported");\
		break;\
	}

#define SWITCH_TENSOR_TYPE_ALL_CPU_RETURN(ELEMENTTYPE, FUNCTION, ...)\
	switch (ELEMENTTYPE)\
	{\
	case DType::Float32: FUNCTION<float>(__VA_ARGS__); break;\
	case DType::Float64: FUNCTION<double>(__VA_ARGS__); break;\
	case DType::Int32: FUNCTION<__int32>(__VA_ARGS__); break;\
	case DType::UInt8: FUNCTION<uint8>(__VA_ARGS__); break;\
	default:\
		throw TSError("Tensor type not supported");\
		break;\
	}

#define SWITCH_TENSOR_TYPE_FLOAT(ELEMENTTYPE, FUNCTION, ...)\
	switch (ELEMENTTYPE)\
	{\
	case DType::Float32: FUNCTION<float>(__VA_ARGS__); break;\
	case DType::Float64: FUNCTION<double>(__VA_ARGS__); break;\
	default:\
		throw TSError("Tensor type not supported");\
		break;\
	}