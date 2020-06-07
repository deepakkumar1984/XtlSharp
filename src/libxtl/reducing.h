#pragma once

#include "General.h"

enum ReduceFunc
{
    Sum = 0,
    Prod,
    Mean,
    Variance,
    StdDev,
    Diff,
    Amax,
    Amin,
    Trapz,
    NormL0,
    NormL1,
    NormSq,
    NormL2,
    NormLinf,
    NormLp2P,
    NormLp,
    NormInducedL1,
    NormInducedLinf,
    CumSum,
    CumProd,
    Nan2Num,
    NanSum,
    NanProd, 
    NanCumSum,
    NanCumProd
};

OPS_API int TS_Reduce(TensorRef* x, int* axes, int n, TensorRef* r, double p1, int p2, int p3, int op);

OPS_API int TS_ReduceAll(TensorRef* x, TensorRef* r, int op, double p1, int p2);

OPS_API int TS_Accumulating(TensorRef* x, int axis, TensorRef* r, int op);