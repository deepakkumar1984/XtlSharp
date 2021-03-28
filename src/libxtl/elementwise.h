#pragma once

#include "General.h"

enum ElementwiseFunc
{
    //Binary func
    Add = 0,
    Sub,
    Mul,
    Div,
    Eq,
    NotEq,
    Greater,
    GreaterEqual,
    Less,
    LessEqual,
    LogicalAnd,
    LogicalOr,
    BitwiseAnd,
    BitwiseOr,
    BitwiseXor,
    BitwiseLeftShift,
    BitwiseRightShift,
    FMod,
    Remainder,
    Maximum,
    Minimum,
    FDim,
    Hypot,
    ATan2,

    //Ternary func
    Where,
    ArgWhere,
    Fma,

    //Urinary func
    LogicalNot,
    BitwiseNot,
    Any,
    All,
    Abs,
    FAbs,
    Sign,
    Exp,
    Exp2,
    Expm1,
    Log,
    Log2,
    Log10,
    Log1p,
    Sqrt,
    Cbrt,
    Sin,
    Cos,
    Tan,
    ASin,
    ACos,
    ATan,
    Sinh,
    Cosh,
    Tanh,
    ASinh,
    ACosh,
    ATanh,
    Erf,
    Erfc,
    TGamma,
    LGamma,
    Ceil,
    Floor,
    Trunc,
    Round,
    NearByInt,
    RInt,
    IsFinite,
    IsInf,
    IsNan,
    NonZero,
    FlatNonZero,
    Pow
};

OPS_API int TS_Elementwise_2(TensorRef* a, TensorRef* b, TensorRef* r, int op);
OPS_API int TS_Elementwise_3(TensorRef* a, TensorRef* b, TensorRef* c, TensorRef* r, int op);
OPS_API int TS_Elementwise_1(TensorRef* a, TensorRef* r, int op);
OPS_API int TS_Elementwise_1_Cls(TensorRef* a, TensorRef* r, int op);
OPS_API int TS_Elementwise_2_Bitwise(TensorRef* a, TensorRef* b, TensorRef* r, int op);