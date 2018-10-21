#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_LINEAR_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_LINEAR_LAYER_HPP

namespace cppdnn
{
	template<typename Ty_>
	void basic_linear_layer<Ty_>::function(Ty_&) const
	{}

	template<typename Ty_>
	basic_layer_ptr<Ty_> linear()
	{
		return std::make_shared<basic_linear_layer<Ty_>>();
	}
}

#endif