//
// Created by deepak on 31/05/2020.
//
#include "elementwise.h"

template<typename T>
void ElementwiseOp(T& a, T& b, T& r, ElementwiseFunc op)
{
    switch(op)
    {
        case ElementwiseFunc::Add : r = a + b; break;
        case ElementwiseFunc::Sub : r = a - b; break;
        case ElementwiseFunc::Mul : r = a * b; break;
        case ElementwiseFunc::Div : r = a / b; break;
        case ElementwiseFunc::Eq : r = xt::equal(a, b); break;
        case ElementwiseFunc::NotEq : r = xt::not_equal(a, b); break;
        case ElementwiseFunc::Greater : r = xt::greater(a, b); break;
        case ElementwiseFunc::GreaterEqual : r = xt::greater_equal(a, b); break;
        case ElementwiseFunc::Less : r = xt::less(a, b); break;
        case ElementwiseFunc::LessEqual : r = xt::less_equal(a, b); break;
        case ElementwiseFunc::LogicalAnd : r = a && b; break;
        case ElementwiseFunc::LogicalOr : r = a || b; break;
        case ElementwiseFunc::FMod : r = xt::fmod(a, b); break;
        case ElementwiseFunc::Remainder : r = xt::remainder(a, b); break;
        case ElementwiseFunc::Maximum : r = xt::maximum(a, b); break;
        case ElementwiseFunc::Minimum : r = xt::minimum(a, b); break;
        case ElementwiseFunc::FDim : r = xt::fdim(a, b); break;
        case ElementwiseFunc::Hypot : r = xt::hypot(a, b); break;
        case ElementwiseFunc::ATan2 : r = xt::atan2(a, b); break;
        default:
            throw TSError("Unsupported Op");
		    break;
    }
}

template<typename T>
void ElementwiseOp_Bitwise(T& a, T& b, T& r, ElementwiseFunc op)
{
    switch(op)
    {
        case ElementwiseFunc::BitwiseAnd : r = (a &  b); break;
        case ElementwiseFunc::BitwiseOr : r = a | b; break;
        case ElementwiseFunc::BitwiseXor : r = a ^ b; break;
        case ElementwiseFunc::BitwiseLeftShift : r = xt::left_shift(a, b); break;
        case ElementwiseFunc::BitwiseRightShift : r = xt::right_shift(a, b); break;
        case ElementwiseFunc::BitwiseNot : r = ~a; break;
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

template<typename T>
void ElementwiseOp(T& a, T& b, T& c, T& r, ElementwiseFunc op)
{
    switch(op)
    {
        case ElementwiseFunc::Where : r = xt::where(a, b, c); break;
        case ElementwiseFunc::Fma : r = xt::fma(a, b, c); break;
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

template<typename T>
void ElementwiseOp(T& a, T& r, ElementwiseFunc op)
{
    switch(op)
    {
        case ElementwiseFunc::LogicalNot : r = !a; break;
        case ElementwiseFunc::Any : r = xt::any(a); break;
        case ElementwiseFunc::All : r = xt::all(a); break;
        case ElementwiseFunc::Abs : r = xt::abs(a); break;
        case ElementwiseFunc::FAbs : r = xt::fabs(a); break;
        //case ElementwiseFunc::Sign : r = xt::sign(a); break;
        case ElementwiseFunc::Exp : r = xt::exp(a); break;
        case ElementwiseFunc::Exp2 : r = xt::exp2(a); break;
        case ElementwiseFunc::Expm1 : r = xt::expm1(a); break;
        case ElementwiseFunc::Log : r = xt::log(a); break;
        case ElementwiseFunc::Log2 : r = xt::log2(a); break;
        case ElementwiseFunc::Log10 : r = xt::log10(a); break;
        case ElementwiseFunc::Log1p : r = xt::log1p(a); break;
        case ElementwiseFunc::Sqrt : r = xt::sqrt(a); break;
        case ElementwiseFunc::Cbrt : r = xt::cbrt(a); break;
        case ElementwiseFunc::Sin : r = xt::sin(a); break;
        case ElementwiseFunc::Cos : r = xt::cos(a); break;
        case ElementwiseFunc::Tan : r = xt::tan(a); break;
        case ElementwiseFunc::ASin : r = xt::asin(a); break;
        case ElementwiseFunc::ACos : r = xt::acos(a); break;
        case ElementwiseFunc::ATan : r = xt::atan(a); break;
        case ElementwiseFunc::Sinh : r = xt::sinh(a); break;
        case ElementwiseFunc::Cosh : r = xt::cosh(a); break;
        case ElementwiseFunc::Tanh : r = xt::tanh(a); break;
        case ElementwiseFunc::ASinh : r = xt::asinh(a); break;
        case ElementwiseFunc::ACosh : r = xt::acosh(a); break;
        case ElementwiseFunc::ATanh : r = xt::atanh(a); break;
        case ElementwiseFunc::Erf : r = xt::erf(a); break;
        case ElementwiseFunc::Erfc : r = xt::erfc(a); break;
        case ElementwiseFunc::TGamma : r = xt::tgamma(a); break;
        case ElementwiseFunc::LGamma : r = xt::lgamma(a); break;
        case ElementwiseFunc::Ceil : r = xt::ceil(a); break;
        case ElementwiseFunc::Floor : r = xt::floor(a); break;
        case ElementwiseFunc::Trunc : r = xt::trunc(a); break;
        case ElementwiseFunc::Round : r = xt::round(a); break;
        case ElementwiseFunc::NearByInt : r = xt::nearbyint(a); break;
        case ElementwiseFunc::RInt : r = xt::rint(a); break;
        case ElementwiseFunc::Where : r = xt::where(a); break;
        case ElementwiseFunc::ArgWhere : r = xt::argwhere(a); break;
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

template<typename T>
void ElementwiseOpCls(T& a, T& r, ElementwiseFunc op)
{
    switch(op)
    {
        case ElementwiseFunc::IsFinite : r = xt::isfinite(a); break;
        case ElementwiseFunc::IsInf : r = xt::isinf(a); break;
        case ElementwiseFunc::IsNan : r = xt::isnan(a); break;
            //case ElementwiseFunc::NonZero : r = xt::nonzero(a); break;
            //case ElementwiseFunc::FlatNonZero : r = xt::flatnonzero(a); break;
        default:
            throw TSError("Unsupported Op");
            break;
    }
}

int TS_Elementwise_2(TensorRef* a, TensorRef* b, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Float32: {
                auto a_t = xt::adapt((float *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((float *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Float64: {
                auto a_t = xt::adapt((double *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((double *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int8: {
                auto a_t = xt::adapt((int8_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int8_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int8_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int16: {
                auto a_t = xt::adapt((short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int64: {
                auto a_t = xt::adapt((long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint8 *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt16: {
                auto a_t = xt::adapt((unsigned short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((unsigned int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((unsigned long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}

int TS_Elementwise_3(TensorRef* a, TensorRef* b, TensorRef* c, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Float32: {
                auto a_t = xt::adapt((float *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((float *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((float *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Float64: {
                auto a_t = xt::adapt((double *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((double *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((double *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int8: {
                auto a_t = xt::adapt((int8_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int8_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((int8_t *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((int8_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int16: {
                auto a_t = xt::adapt((short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((short *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((int *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int64: {
                auto a_t = xt::adapt((long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((long *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint8 *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((uint8 *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt16: {
                auto a_t = xt::adapt((unsigned short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((unsigned short *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t,r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((unsigned int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((unsigned int *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((unsigned long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto c_t = xt::adapt((unsigned long *) c->buffer, c->ElementCount(), xt::no_ownership(), c->getShape());
                auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, b_t, c_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}

int TS_Elementwise_1(TensorRef* a, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Float32: {
                auto a_t = xt::adapt((float *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Float64: {
                auto a_t = xt::adapt((double *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int8: {
                auto a_t = xt::adapt((int8_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((int8_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int16: {
                auto a_t = xt::adapt((short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int64: {
                auto a_t = xt::adapt((long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt16: {
                auto a_t = xt::adapt((unsigned short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((unsigned int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((unsigned long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}

int TS_Elementwise_1_Cls(TensorRef* a, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Float32: {
                auto a_t = xt::adapt((float *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((float *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Float64: {
                auto a_t = xt::adapt((double *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((double *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int64: {
                auto a_t = xt::adapt((long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt16: {
                auto a_t = xt::adapt((unsigned short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((unsigned int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((unsigned long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOpCls(a_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}

int TS_Elementwise_2_Bitwise(TensorRef* a, TensorRef* b, TensorRef* r, int op)
{
    API_BEGIN()
        switch(a->elementType)
        {
            case DType::Int8: {
                auto a_t = xt::adapt((int8_t *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int8_t *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int8_t *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int16: {
                auto a_t = xt::adapt((short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int32: {
                auto a_t = xt::adapt((int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::Int64: {
                auto a_t = xt::adapt((long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt8: {
                auto a_t = xt::adapt((uint8 *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((uint8 *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((uint8 *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt16: {
                auto a_t = xt::adapt((unsigned short *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned short *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned short *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt32: {
                auto a_t = xt::adapt((unsigned int *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned int *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned int *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            case DType::UInt64: {
                auto a_t = xt::adapt((unsigned long *) a->buffer, a->ElementCount(), xt::no_ownership(), a->getShape());
                auto b_t = xt::adapt((unsigned long *) b->buffer, b->ElementCount(), xt::no_ownership(), b->getShape());
                auto r_t = xt::adapt((unsigned long *) r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
                ElementwiseOp_Bitwise(a_t, b_t, r_t, static_cast<ElementwiseFunc>(op));
                break;
            }
            default:
                break;
        }

    API_END()
}