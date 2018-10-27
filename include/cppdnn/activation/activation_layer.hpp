#ifndef CPPDNN_HEADER_ACTIVATION_ACTIVATION_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_ACTIVATION_LAYER_HPP

#include <cppdnn/layer.hpp>
#include <cppdnn/object.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_activation_layer : public basic_layer<Ty_>
	{
	public:
		basic_activation_layer(const basic_activation_layer& layer) = delete;
		basic_activation_layer(basic_activation_layer&& layer) = delete;
		virtual ~basic_activation_layer() override = default;

	protected:
		basic_activation_layer() noexcept = default;

	public:
		basic_activation_layer& operator=(const basic_activation_layer& layer) = delete;
		basic_activation_layer& operator=(basic_activation_layer&& layer) = delete;
		bool operator==(const basic_activation_layer& layer) = delete;
		bool operator!=(const basic_activation_layer& layer) = delete;

	public:
		virtual void forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const override;
		
	protected:
		virtual void function(const basic_object_ptr<Ty_>& input) const = 0;
	};

	using activation_layer = basic_activation_layer<double>;
}

#include "details/activation_layer.hpp"
#endif