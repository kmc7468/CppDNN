#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_SIGMOID_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_SIGMOID_HPP

#include <cmath>

namespace cppdnn
{
	template<typename Ty_>
	void basic_sigmoid<Ty_>::function(Ty_& value) const
	{
		value = Ty_(1) / (Ty_(1) + std::exp(-value));
	}
}

#endif