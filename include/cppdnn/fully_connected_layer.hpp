#ifndef CPPDNN_HEADER_FULLY_CONNECTED_LAYER_HPP
#define CPPDNN_HEADER_FULLY_CONNECTED_LAYER_HPP

#include <cppdnn/layer.hpp>
#include <cppdnn/object.hpp>
#include <cppdnn/vector.hpp>

#include <cstddef>
#include <vector>

namespace cppdnn
{
	template<typename Ty_>
	class basic_fully_connected_layer : public basic_layer<Ty_>
	{
	public:
		basic_fully_connected_layer(std::size_t unit, std::size_t input);
		basic_fully_connected_layer(const basic_fully_connected_layer& layer) = delete;
		basic_fully_connected_layer(basic_fully_connected_layer&& layer) = delete;
		virtual ~basic_fully_connected_layer() override = default;

	public:
		basic_fully_connected_layer& operator=(const basic_fully_connected_layer& layer) = delete;
		basic_fully_connected_layer& operator=(basic_fully_connected_layer&& layer) = delete;
		bool operator==(const basic_fully_connected_layer& layer) = delete;
		bool operator!=(const basic_fully_connected_layer& layer) = delete;

	public:
		virtual void forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const override;

	public:
		std::size_t unit() const noexcept;
		std::size_t input() const noexcept;

	private:
		std::vector<std::shared_ptr<basic_vector<Ty_>>> weights_;
		std::vector<Ty_> bias_;
	};

	using fully_connected_layer = basic_fully_connected_layer<double>;
}

#include "details/fully_connected_layer.hpp"
#endif