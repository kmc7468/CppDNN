#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_TANH_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_TANH_LAYER_HPP

#include <cmath>

namespace cppdnn
{
	template<typename Ty_>
	void basic_tanh_layer<Ty_>::function(const basic_object_ptr<Ty_>& input) const
	{
		input->apply([](const basic_object_ptr<Ty_>& value)
		{
			Ty_& data = to_value_ref(value)->data();
			data = std::tanh(data);
		});
	}

	template<typename Ty_>
	basic_layer_ptr<Ty_> tanh()
	{
		return std::make_shared<basic_tanh_layer<Ty_>>();
	}
}

#endif