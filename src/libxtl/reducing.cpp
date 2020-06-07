//
// Created by deepak on 4/06/2020.
//

#include "reducing.h"
#include "xtensor/xreducer.hpp"
#include "xtensor/xnorm.hpp"


template<typename T>
void Reduce(T& x, std::vector<int> axes, T& r, ReduceFunc op, double p1, int p2, int p3)
{
    switch(op)
    {
        case ReduceFunc::Sum : r = xt::sum(x, axes); break;
        case ReduceFunc::Prod : r = xt::prod(x, axes); break;
        case ReduceFunc::Mean : r = xt::mean(x, axes); break;
        case ReduceFunc::Variance : r = xt::variance(x, axes); break;  
        case ReduceFunc::StdDev : r = xt::stddev(x, axes); break;
        case ReduceFunc::Diff : r = xt::diff(x, p2, p3); break;
        case ReduceFunc::Amax : r = xt::amax(x, axes); break;
        case ReduceFunc::Amin : r = xt::amin(x, axes); break;
        case ReduceFunc::Trapz : r = xt::trapz(x, p1, p2); break;
        case ReduceFunc::NormL0 : r = xt::norm_l0(x, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormL1 : r = xt::norm_l1(x, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormSq : r = xt::norm_sq(x, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormL2 : r = xt::norm_l2(x, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormLinf : r = xt::norm_linf(x, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormLp2P : r = xt::norm_lp_to_p(x, p1, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormLp : r = xt::norm_lp(x, p1, axes, xt::evaluation_strategy::immediate); break;
        case ReduceFunc::NormInducedL1 : r = xt::norm_induced_l1(x); break;
        case ReduceFunc::NormInducedLinf : r = xt::norm_induced_linf(x); break;
        case ReduceFunc::NanSum : r = xt::nansum(x, axes); break;
        case ReduceFunc::NanProd : r = xt::nanprod(x, axes); break;
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

template<typename T>
void ReduceAll(T& x, T& r, ReduceFunc op, double p1, int p2)
{
    switch(op)
    {
        case ReduceFunc::Sum : r = xt::sum(x); break;
        case ReduceFunc::Prod : r = xt::prod(x); break;
        case ReduceFunc::Mean : r = xt::mean(x); break;
        case ReduceFunc::Variance : r = xt::variance(x); break;
        case ReduceFunc::StdDev : r = xt::stddev(x); break;
        case ReduceFunc::Amax : r = xt::amax(x); break;
        case ReduceFunc::Amin : r = xt::amin(x); break;
        case ReduceFunc::Nan2Num : r = xt::nan_to_num(x); break;
        case ReduceFunc::NormL0 : r = xt::norm_l0(x); break;
        case ReduceFunc::NormLp2P : r = xt::norm_lp_to_p(x, p1); break;
        case ReduceFunc::NormLp : r = xt::norm_lp(x, p1); break;
        default:
            throw TSError("Unsupported Op");
            break;
    }

    std::cout << r;
}

template<typename T>
void Accumulating(T& x, int axis, T& r, ReduceFunc op)
{
    switch(op)
    {
        case ReduceFunc::CumSum :
        {
            if(axis != -9999)
            {
                r = xt::cumsum(x, axis); break;
            }
            else
            {
                r = xt::cumsum(x); break;
            }
            
        } 
        case ReduceFunc::CumProd : 
        {
            if(axis != -9999)
            {
                r = xt::cumprod(x, axis); break;
            }
            else
            {
                r = xt::cumprod(x); break;
            }
            
        } 
        case ReduceFunc::NanCumSum : 
        {
            if(axis != -9999)
            {
                r = xt::nancumsum(x, axis); break;
            }
            else
            {
                r = xt::nancumsum(x); break;
            }
            
        } 
        case ReduceFunc::NanCumProd : 
        {
            if(axis != -9999)
            {
                r = xt::nancumprod(x, axis); break;
            }
            else
            {
                r = xt::nancumprod(x); break;
            }
            
        } 
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

int TS_Reduce(TensorRef* x, int* axes, int n, TensorRef* r, double p1, int p2, int p3, int op)
{
    API_BEGIN()
    std::vector<int> shape;
    shape.assign(axes, axes + n);
    switch(x->elementType)
    {
        case DType::Float32: {
            auto x_t = xt::adapt((float *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::Float64: {
            auto x_t = xt::adapt((double *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::Int16: {
            auto x_t = xt::adapt((short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::Int32: {
            auto x_t = xt::adapt((int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::Int64: {
            auto x_t = xt::adapt((long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::UInt8: {
            auto x_t = xt::adapt((uint8 *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::UInt16: {
            auto x_t = xt::adapt((unsigned short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::UInt32: {
            auto x_t = xt::adapt((unsigned int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        case DType::UInt64: {
            auto x_t = xt::adapt((unsigned long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Reduce(x_t, shape, r_t, static_cast<ReduceFunc>(op), p1, p2, p3);
            break;
        }
        default:
            break;
    }

    API_END()
}

int TS_ReduceAll(TensorRef* x, TensorRef* r, int op, double p1, int p2)
{
    API_BEGIN()
    switch(x->elementType)
    {
        case DType::Float32: {
            auto x_t = xt::adapt((float *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            
            break;
        }
        case DType::Float64: {
            auto x_t = xt::adapt((double *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::Int16: {
            auto x_t = xt::adapt((short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::Int32: {
            auto x_t = xt::adapt((int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::Int64: {
            auto x_t = xt::adapt((long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::UInt8: {
            auto x_t = xt::adapt((uint8 *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::UInt16: {
            auto x_t = xt::adapt((unsigned short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::UInt32: {
            auto x_t = xt::adapt((unsigned int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        case DType::UInt64: {
            auto x_t = xt::adapt((unsigned long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            ReduceAll(x_t, r_t, static_cast<ReduceFunc>(op), p1, p2);
            break;
        }
        default:
            break;
    }

    API_END()
}

int TS_Accumulating(TensorRef* x, int axis, TensorRef* r, int op)
{
    API_BEGIN()
    switch(x->elementType)
    {
        case DType::Float32: {
            auto x_t = xt::adapt((float *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            
            break;
        }
        case DType::Float64: {
            auto x_t = xt::adapt((double *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::Int16: {
            auto x_t = xt::adapt((short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::Int32: {
            auto x_t = xt::adapt((int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::Int64: {
            auto x_t = xt::adapt((long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::UInt8: {
            auto x_t = xt::adapt((uint8 *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::UInt16: {
            auto x_t = xt::adapt((unsigned short *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::UInt32: {
            auto x_t = xt::adapt((unsigned int *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        case DType::UInt64: {
            auto x_t = xt::adapt((unsigned long *) x->buffer, x->ElementCount(), xt::no_ownership(), x->getShape());
            auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
            Accumulating(x_t, axis, r_t, static_cast<ReduceFunc>(op));
            break;
        }
        default:
            break;
    }

    API_END()
}