#ifndef CPPDNN_HEADER_DETAILS_LAYER_HPP
#define CPPDNN_HEADER_DETAILS_LAYER_HPP

namespace cppdnn
{
	template<typename Ty_>
	basic_object_ptr<Ty_> basic_layer<Ty_>::forward(const basic_object_ptr<Ty_>& input) const
	{
		basic_object_ptr<Ty_> output;
		forward(input, output);

		return output;
	}
}

#endif