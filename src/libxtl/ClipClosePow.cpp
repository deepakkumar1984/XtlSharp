//
// Created by deepak on 4/06/2020.
//

#include "ClipClosePow.h"



int TS_Cast(TensorRef* x, int type, TensorRef* r)
{
    API_BEGIN()
        switch(x->elementType)
        {
            case DType::Float32: {
                auto x_t = xt::adapt((float *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::Float64: {
                auto x_t = xt::adapt((double *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::Int16: {
                auto x_t = xt::adapt((short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::Int32: {
                auto x_t = xt::adapt((int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::Int64: {
                auto x_t = xt::adapt((long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::UInt8: {
                auto x_t = xt::adapt((uint8 *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::UInt16: {
                auto x_t = xt::adapt((unsigned short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::UInt32: {
                auto x_t = xt::adapt((unsigned int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            case DType::UInt64: {
                auto x_t = xt::adapt((unsigned long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                SWITCH_CAST_TYPE(type)
                break;
            }
            default:
                break;
        }

    API_END()
}

int TS_Clip(TensorRef* x, double min, double max, TensorRef* r)
{
    API_BEGIN()
        switch(x->elementType)
        {
            case DType::Float32: {
                auto x_t = xt::adapt((float *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((float *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::Float64: {
                auto x_t = xt::adapt((double *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((double *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::Int16: {
                auto x_t = xt::adapt((short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((short *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::Int32: {
                auto x_t = xt::adapt((int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((int *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::Int64: {
                auto x_t = xt::adapt((long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((long *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::UInt8: {
                auto x_t = xt::adapt((uint8 *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((uint8 *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::UInt16: {
                auto x_t = xt::adapt((unsigned short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((unsigned short *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::UInt32: {
                auto x_t = xt::adapt((unsigned int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((unsigned int *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            case DType::UInt64: {
                auto x_t = xt::adapt((unsigned long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
                auto r_t = xt::adapt((unsigned long *) x->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                r_t = xt::clip(x_t, min, max);
                break;
            }
            default:
                break;
        }

    API_END()
}