//
// Created by deepak on 31/05/2020.
//
#include "binary_func.h"

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
            case DType::Int64: {
                auto a_t = xt::adapt((int64_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int64_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int64_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
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
            case DType::UInt16: {
                auto a_t = xt::adapt((uint16_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint16_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint16_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((uint32_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint32_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint32_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((uint64_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint64_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint64_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                BinaryOp(a_t, b_t, r_t, static_cast<BinaryOpCode>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}
