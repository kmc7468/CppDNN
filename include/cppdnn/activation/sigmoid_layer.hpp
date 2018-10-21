#ifndef CPPDNN_HEADER_ACTIVATION_SIGMOID_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_SIGMOID_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_sigmoid_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_sigmoid_layer() noexcept = default;
		basic_sigmoid_layer(const basic_sigmoid_layer& sigmoid) = delete;
		basic_sigmoid_layer(basic_sigmoid_layer&& sigmoid) = delete;
		virtual ~basic_sigmoid_layer() override = default;

	public:
		basic_sigmoid_layer& operator=(const basic_sigmoid_layer& sigmoid) = delete;
		basic_sigmoid_layer& operator=(basic_sigmoid_layer&& sigmoid) = delete;
		bool operator==(const basic_sigmoid_layer& sigmoid) = delete;
		bool operator!=(const basic_sigmoid_layer& sigmoid) = delete;

	protected:
		virtual void function(Ty_& value) const override;
	};

	using sigmoid_layer = basic_sigmoid_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> sigmoid();
}

#include "details/sigmoid_layer.hpp"
#endif