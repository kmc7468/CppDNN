#ifndef CPPDNN_HEADER_DETAILS_NETWORK_HPP
#define CPPDNN_HEADER_DETAILS_NETWORK_HPP

#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	template<typename Layer_, typename ...Args_>
	void basic_network<Ty_>::add_layer(Args_&&... args)
	{
		layers_.push_back(std::make_shared<Layer_>(std::forward<Args_>(args)...));
	}
	template<typename Ty_>
	void basic_network<Ty_>::add_layer(const basic_layer_ptr<Ty_>& layer)
	{
		layers_.push_back(layer);
	}

	template<typename Ty_>
	basic_object_ptr<Ty_> basic_network<Ty_>::compute(const basic_object_ptr<Ty_>& input) const
	{
		basic_object_ptr<Ty_> output_prev = input;
		basic_object_ptr<Ty_> output_cur = nullptr;

		for (const basic_layer_ptr<Ty_>& layer : layers_)
		{
			layer->forward(output_prev, output_cur);
			std::swap(output_prev, output_cur);
		}

		return output_prev;
	}

	template<typename Ty_>
	const std::vector<basic_layer_ptr<Ty_>>& basic_network<Ty_>::layers() const noexcept
	{
		return layers_;
	}
}

#endif