//
// Created by deepak on 31/05/2020.
//
#include "fillcopy.h"

template<typename T>
INLINE_FUNC void Fill_Apply(TensorRef* result, double value)
{
    auto a = xt::adapt((T*)result->buffer, result->ElementCount(), xt::no_ownership(), result->getShape());
    a.fill(value);
}

int TS_Fill(TensorRef* result, double value)
{
    API_BEGIN()
    SWITCH_TENSOR_TYPE_ALL_CPU(result->elementType, Fill_Apply, result, value)
    API_END()
}

