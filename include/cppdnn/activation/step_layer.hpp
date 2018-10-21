#ifndef CPPDNN_HEADER_ACTIVATION_STEP_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_STEP_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_step_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_step_layer() noexcept = default;
		basic_step_layer(const Ty_& threshold) noexcept;
		basic_step_layer(const basic_step_layer& step) = delete;
		basic_step_layer(basic_step_layer&& step) = delete;
		virtual ~basic_step_layer() override = default;

	public:
		basic_step_layer& operator=(const basic_step_layer& step) = delete;
		basic_step_layer& operator=(basic_step_layer&& step) = delete;
		bool operator==(const basic_step_layer& step) = delete;
		bool operator!=(const basic_step_layer& step) = delete;

	protected:
		virtual void function(Ty_& value) const override;

	private:
		Ty_ threshold_ = 0;
	};

	using step_layer = basic_step_layer<double>;

	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> step();
	template<typename Ty_ = double>
	basic_layer_ptr<Ty_> step(const Ty_& threshold);
}

#include "details/step_layer.hpp"
#endif