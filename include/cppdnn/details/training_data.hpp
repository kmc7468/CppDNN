#ifndef CPPDNN_HEADER_DETAILS_TRAINING_DATA_HPP
#define CPPDNN_HEADER_DETAILS_TRAINING_DATA_HPP

#include <cppdnn/vector.hpp>

#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(const std::vector<basic_training_set_base_ptr<Ty_>>& vector)
		: data_(vector)
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(std::vector<basic_training_set_base_ptr<Ty_>>&& vector) noexcept
		: data_(std::move(vector))
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(const basic_training_data& data)
		: data_(data.data_)
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(basic_training_data&& data) noexcept
		: data_(std::move(data.data_))
	{}

	template<typename Ty_>
	const basic_training_set_base_ptr<Ty_>& basic_training_data<Ty_>::operator[](std::size_t index) const noexcept
	{
		return data_[index];
	}
	template<typename Ty_>
	basic_training_set_base_ptr<Ty_>& basic_training_data<Ty_>::operator[](std::size_t index) noexcept
	{
		return data_[index];
	}

	template<typename Ty_>
	const Ty_& basic_training_data<Ty_>::at(std::size_t index) const noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	Ty_& basic_training_data<Ty_>::at(std::size_t index) noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::iterator basic_training_data<Ty_>::begin() noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::begin() const noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::cbegin() const noexcept
	{
		return data_.cbegin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::iterator basic_training_data<Ty_>::end() noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::end() const noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::cend() const noexcept
	{
		return data_.cend();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::reverse_iterator basic_training_data<Ty_>::rbegin() noexcept
	{
		return data_.rbegin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_reverse_iterator basic_training_data<Ty_>::rbegin() const noexcept
	{
		return data_.rbegin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_reverse_iterator basic_training_data<Ty_>::crbegin() const noexcept
	{
		return data_.crbegin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::reverse_iterator basic_training_data<Ty_>::rend() noexcept
	{
		return data_.rend();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_reverse_iterator basic_training_data<Ty_>::rend() const noexcept
	{
		return data_.rend();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_reverse_iterator basic_training_data<Ty_>::crend() const noexcept
	{
		return data_.crend();
	}

	template<typename Ty_>
	bool basic_training_data<Ty_>::empty() const noexcept
	{
		return data_.empty();
	}
	template<typename Ty_>
	std::size_t basic_training_data<Ty_>::size() const noexcept
	{
		return data_.size();
	}

	template<typename Ty_>
	void basic_training_data<Ty_>::push_back(const basic_training_set_base_ptr<Ty_>& set)
	{
		data_.push_back(set);
	}
	template<typename Ty_>
	void basic_training_data<Ty_>::push_back(basic_training_set_base_ptr<Ty_>&& set)
	{
		data_.push_back(std::move(set));
	}
	template<typename Ty_>
	void basic_training_data<Ty_>::erase(const_iterator pos)
	{
		data_.erase(pos);
	}
}

namespace cppdnn
{
	template<typename Ty_>
	basic_training_set<Ty_>::basic_training_set(const basic_object_ptr<Ty_>& input, const basic_object_ptr<Ty_>& output)
		: input_(input), output_(output)
	{}
	template<typename Ty_>
	basic_training_set<Ty_>::basic_training_set(basic_object_ptr<Ty_>&& input, const basic_object_ptr<Ty_>& output)
		: input_(std::move(input)), output_(output)
	{}
	template<typename Ty_>
	basic_training_set<Ty_>::basic_training_set(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>&& output)
		: input_(input), output_(std::move(output))
	{}
	template<typename Ty_>
	basic_training_set<Ty_>::basic_training_set(basic_object_ptr<Ty_>&& input, basic_object_ptr<Ty_>&& output) noexcept
		: input_(std::move(input)), output_(std::move(output))
	{}

	template<typename Ty_>
	basic_object_ptr<Ty_> basic_training_set<Ty_>::input() const
	{
		return input_;
	}
	template<typename Ty_>
	basic_object_ptr<Ty_> basic_training_set<Ty_>::output() const
	{
		return output_;
	}

	template<typename Ty_>
	basic_training_set_base_ptr<Ty_> make_training_set(const basic_object_ptr<Ty_>& input, const basic_object_ptr<Ty_>& output)
	{
		return std::make_shared<basic_training_set<Ty_>>(input, output);
	}

	template<typename Ty_>
	basic_training_data_ptr<Ty_> make_training_data(const std::vector<std::pair<std::vector<Ty_>, std::vector<Ty_>>>& data)
	{
		basic_training_data_ptr<Ty_> result = std::make_shared<basic_training_data<Ty_>>();

		for (const std::pair<std::vector<Ty_>, std::vector<Ty_>>& set : data)
		{
			result->push_back(std::make_shared<basic_training_set<Ty_>>(
				std::make_shared<basic_vector<Ty_>>(set.first),
				std::make_shared<basic_vector<Ty_>>(set.second)));
		}

		return result;
	}
}

#endif