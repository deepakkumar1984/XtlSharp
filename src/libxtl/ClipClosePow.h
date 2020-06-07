#pragma once

#include "general.h"

OPS_API int TS_Cast(TensorRef* x, int type, TensorRef* r);
OPS_API int TS_Clip(TensorRef* x, double min, double max, TensorRef* r);
//OPS_API int TS_Pow(TensorRef* x, double value, TensorRef* r);
//OPS_API int TS_IsClose(TensorRef* a, TensorRef* b, double rtol, double atol, bool equal_nan, TensorRef* r);
//OPS_API int TS_AllClose(TensorRef* a, TensorRef* b, double rtol, double atol, bool equal_nan, TensorRef* r);