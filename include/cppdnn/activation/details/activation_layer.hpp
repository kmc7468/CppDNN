#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_ACTIVATION_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_ACTIVATION_LAYER_HPP

namespace cppdnn
{
	template<typename Ty_>
	void basic_activation_layer<Ty_>::forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const
	{
		output = input->copy();
		output->apply([this](const basic_object_ptr<Ty_>& value)
		{
			std::shared_ptr<basic_value_ref<Ty_>> value_ref = to_value_ref(value);
			function(value_ref->data());
		});
	}
}

#endif