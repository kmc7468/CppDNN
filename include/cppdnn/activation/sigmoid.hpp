#ifndef CPPDNN_HEADER_ACTIVATION_SIGMOID_HPP
#define CPPDNN_HEADER_ACTIVATION_SIGMOID_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_sigmoid : public basic_activation_layer<Ty_>
	{
	public:
		basic_sigmoid() noexcept = default;
		basic_sigmoid(const basic_sigmoid& sigmoid) = delete;
		basic_sigmoid(basic_sigmoid&& sigmoid) = delete;
		virtual ~basic_sigmoid() override = default;

	public:
		basic_sigmoid& operator=(const basic_sigmoid& sigmoid) = delete;
		basic_sigmoid& operator=(basic_sigmoid&& sigmoid) = delete;
		bool operator==(const basic_sigmoid& sigmoid) = delete;
		bool operator!=(const basic_sigmoid& sigmoid) = delete;

	protected:
		virtual void function(Ty_& value) const override;
	};

	using sigmoid = basic_sigmoid<double>;
}

#include "details/sigmoid.hpp"
#endif