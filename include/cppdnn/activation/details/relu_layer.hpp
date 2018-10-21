#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_RELU_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_RELU_LAYER_HPP

#include <algorithm>

namespace cppdnn
{
	template<typename Ty_>
	void basic_relu_layer<Ty_>::function(Ty_& value) const
	{
		value = std::max(Ty_(0), value);
	}

	template<typename Ty_>
	basic_layer_ptr<Ty_> relu()
	{
		return std::make_shared<basic_relu_layer<Ty_>>();
	}
}

#endif