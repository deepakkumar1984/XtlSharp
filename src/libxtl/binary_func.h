#pragma once

#include "General.h"

enum BinaryOpCode
{
    Add = 0,
    Sub = 1,
    Mul = 2,
    Div = 3,
};

OPS_API int TS_Binary(TensorRef* a, TensorRef* b, TensorRef* r, int op);