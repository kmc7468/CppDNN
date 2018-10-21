#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_SIGMOID_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_SIGMOID_LAYER_HPP

#include <cmath>

namespace cppdnn
{
	template<typename Ty_>
	void basic_sigmoid_layer<Ty_>::function(Ty_& value) const
	{
		value = Ty_(1) / (Ty_(1) + std::exp(-value));
	}

	template<typename Ty_>
	basic_layer_ptr<Ty_> sigmoid()
	{
		return std::make_shared<basic_sigmoid_layer<Ty_>>();
	}
}

#endif