#ifndef CPPDNN_HEADER_ACTIVATION_LINEAR_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_LINEAR_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_linear_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_linear_layer() noexcept = default;
		basic_linear_layer(const basic_linear_layer& linear) = delete;
		basic_linear_layer(basic_linear_layer&& linear) = delete;
		virtual ~basic_linear_layer() override = default;

	public:
		basic_linear_layer& operator=(const basic_linear_layer& linear) = delete;
		basic_linear_layer& operator=(basic_linear_layer&& linear) = delete;
		bool operator==(const basic_linear_layer& linear) = delete;
		bool operator!=(const basic_linear_layer& linear) = delete;

	protected:
		virtual void function(Ty_& value) const override;
	};

	using linear_layer = basic_linear_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> linear();
}

#include "details/linear_layer.hpp"
#endif