//
// Created by deepak on 31/05/2020.
//
#include "fillcopy.h"

template<typename T>
INLINE_FUNC void Fill_Apply(TensorRef* result, float value)
{
    auto a = xt::adapt((T*)result->buffer, result->ElementCount(), xt::no_ownership(), result->getShape());
    a.fill(value);
}

int TS_Fill(TensorRef* result, float value)
{
    API_BEGIN()
    SWITCH_TENSOR_TYPE_ALL_CPU(result->elementType, Fill_Apply, result, value)
    API_END()
}

template<typename T>
void Add_Apply(TensorRef* a, TensorRef* b, TensorRef* r)
{
    auto a_t = Ref2Array<T>(a);
    auto b_t = Ref2Array<T>(b);
    auto r_t = Ref2Array<T>(r);
    r_t = a_t + b_t;
}

template<typename T>
void UrinayOp(T& x, T& r, std::string opname)
{
    switch(opname)
    {
        case "SIN": r = xt::sin(x);
    }
}

template<typename T>
void BinaryOp(T& a, T& b, T& r, BinaryOpCode op)
{
    switch(op)
    {
        case BinaryOpCode::Add : r = a + b; break;
        case BinaryOpCode::Sub : r = a - b; break;
        case BinaryOpCode::Mul : r = a * b; break;
        case BinaryOpCode::Div : r = a / b; break;
        default:
            throw TSError("Tensor type not supported");
		    break;
    }
}

int TS_Binary(TensorRef* a, TensorRef* b, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Float32: {
                auto a_t = xt::adapt((float *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((float *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::Float64: {
                auto a_t = xt::adapt((double *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((double *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::Int8: {
                auto a_t = xt::adapt((short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::Int16: {
                auto a_t = xt::adapt((int16_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int16_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int16_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint8 *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}
