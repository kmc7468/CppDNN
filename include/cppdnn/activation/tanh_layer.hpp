#ifndef CPPDNN_HEADER_ACTIVATION_TANH_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_TANH_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_tanh_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_tanh_layer() noexcept = default;
		basic_tanh_layer(const basic_tanh_layer& tanh) = delete;
		basic_tanh_layer(basic_tanh_layer&& tanh) = delete;
		virtual ~basic_tanh_layer() override = default;

	public:
		basic_tanh_layer& operator=(const basic_tanh_layer& tanh) = delete;
		basic_tanh_layer& operator=(basic_tanh_layer&& tanh) = delete;
		bool operator==(const basic_tanh_layer& tanh) = delete;
		bool operator!=(const basic_tanh_layer& tanh) = delete;

	protected:
		virtual void function(const basic_object_ptr<Ty_>& input) const override;
	};

	using tanh_layer = basic_tanh_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> tanh();
}

#include "details/tanh_layer.hpp"
#endif