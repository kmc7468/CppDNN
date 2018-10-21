#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_STEP_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_STEP_LAYER_HPP

namespace cppdnn
{
	template<typename Ty_>
	basic_step_layer<Ty_>::basic_step_layer(const Ty_& threshold) noexcept
		: threshold_(threshold)
	{}

	template<typename Ty_>
	void basic_step_layer<Ty_>::function(Ty_& value) const
	{
		value = (value >= threshold_ ? 1 : 0);
	}

	template<typename Ty_>
	basic_layer_ptr<Ty_> step()
	{
		return std::make_shared<basic_step_layer<Ty_>>();
	}
	template<typename Ty_>
	basic_layer_ptr<Ty_> step(const Ty_& threshold)
	{
		return std::make_shared<basic_step_layer<Ty_>>(threshold);
	}
}

#endif