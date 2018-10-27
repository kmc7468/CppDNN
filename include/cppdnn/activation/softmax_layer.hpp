#ifndef CPPDNN_HEADER_ACTIVATION_SOFTMAX_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_SOFTMAX_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_softmax_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_softmax_layer() noexcept = default;
		basic_softmax_layer(const basic_softmax_layer& softmax) = delete;
		basic_softmax_layer(basic_softmax_layer&& softmax) = delete;
		virtual ~basic_softmax_layer() override = default;

	public:
		basic_softmax_layer& operator=(const basic_softmax_layer& softmax) = delete;
		basic_softmax_layer& operator=(basic_softmax_layer&& softmax) = delete;
		bool operator==(const basic_softmax_layer& softmax) = delete;
		bool operator!=(const basic_softmax_layer& softmax) = delete;

	public:
		virtual void forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const override;
		
	protected:
		virtual void function(const basic_object_ptr<Ty_>&) const override;
	};

	using softmax_layer = basic_softmax_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> softmax();
}

#include "details/softmax_layer.hpp"
#endif