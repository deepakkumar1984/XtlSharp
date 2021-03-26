
#include "initializers.h"
#include "xtensor/xbuilder.hpp"

template<typename T>
INLINE_FUNC void Initializer_Apply(T& r, std::vector<size_t> shape, double a, double b, int c, int d, int e, InitializersFunc op)
{
	switch (op)
	{
		case InitializersFunc::Arange: r = xt::arange(c, d, e); break;
		case InitializersFunc::Eye: r = xt::eye(shape, c); break;
		case InitializersFunc::Linspace: r = xt::linspace(a, b, c); break;
		case InitializersFunc::Logspace: r = xt::logspace(a, b, c); break;
		default:
			break;
	}
}

OPS_API int TS_Initializer(TensorRef* r, double a, double b, int c, int d, int e, int op)
{
	auto r_t = xt::adapt((float*)r->buffer, r->ElementCount(), xt::no_ownership(), r->getShape());
	Initializer_Apply(r_t, r->getShape(), a, b, c, d, e, static_cast<InitializersFunc>(op));
	//SWITCH_TENSOR_TYPE_ALL_CPU(r->elementType, Initializer_Apply, r_t, a, b, c, d, e, static_cast<InitializersFunc>(op))
	return 0;
}
