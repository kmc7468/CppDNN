#ifndef CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP
#define CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP

#include <random>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_fully_connected_layer<Ty_>::basic_fully_connected_layer(std::size_t unit, std::size_t input)
	{
		weights_.reserve(unit);
		bias_.resize(input);

		std::random_device rd;
		std::mt19937_64 mt(rd());
		std::uniform_real_distribution<double> dist(-1, 1);

		for (std::size_t i = 0; i < unit; ++i)
		{
			std::vector<Ty_> vec;
			vec.resize(input);

			for (std::size_t j = 0; j < input; ++j)
			{
				vec[j] = dist(mt);
			}

			weights_.push_back(std::make_shared<basic_vector<Ty_>>(std::move(vec)));
		}

		for (std::size_t i = 0; i < input; ++i)
		{
			bias_[i] = dist(mt);
		}
	}

	template<typename Ty_>
	void basic_fully_connected_layer<Ty_>::forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const
	{
		const std::size_t unit = this->unit();
		std::shared_ptr<basic_vector<Ty_>> output_vec = std::make_shared<basic_vector<Ty_>>(unit);
		output = output_vec;

		for (std::size_t i = 0; i < unit; ++i)
		{
			basic_object_ptr<Ty_> unit_output = *input * *weights_[i];
			*unit_output += basic_value<Ty_>(bias_[i]);
		
			(*output_vec)[i] = to_value_ref(unit_output)->data();
		}
	}

	template<typename Ty_>
	std::size_t basic_fully_connected_layer<Ty_>::unit() const noexcept
	{
		return weights_.size();
	}
	template<typename Ty_>
	std::size_t basic_fully_connected_layer<Ty_>::input() const noexcept
	{
		return bias_.size();
	}

	template<typename Ty_>
	basic_layer_ptr<Ty_> fc(std::size_t unit, std::size_t input)
	{
		return std::make_shared<basic_fully_connected_layer<Ty_>>(unit, input);
	}
}

#endif