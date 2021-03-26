#pragma once

#include "general.h"

enum InitializersFunc
{
    Linspace = 0,
    Logspace,
    Arange,
    Eye,
    Zeros,
    Ones,
    Empty
};


OPS_API int TS_Initializer(TensorRef* r, double a, double b, int c, int d, int e, int op);
OPS_API int TS_Meshgrid(TensorRef* x0, TensorRef* x1, TensorRef* x2, TensorRef* x3, TensorRef* r);