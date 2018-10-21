#ifndef CPPDNN_HEADER_ACTIVATION_RELU_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_RELU_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_relu_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_relu_layer() noexcept = default;
		basic_relu_layer(const basic_relu_layer& relu) = delete;
		basic_relu_layer(basic_relu_layer&& relu) = delete;
		virtual ~basic_relu_layer() override = default;

	public:
		basic_relu_layer& operator=(const basic_relu_layer& relu) = delete;
		basic_relu_layer& operator=(basic_relu_layer&& relu) = delete;
		bool operator==(const basic_relu_layer& relu) = delete;
		bool operator!=(const basic_relu_layer& relu) = delete;

	protected:
		virtual void function(Ty_& value) const override;
	};

	using relu_layer = basic_relu_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> relu();
}

#include "details/relu_layer.hpp"
#endif