#ifndef CPPDNN_HEADER_DETAILS_VECTOR_HPP
#define CPPDNN_HEADER_DETAILS_VECTOR_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/details/utility.hpp>

#include <algorithm>
#include <type_traits>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::size_t size)
	{
		data_.resize(size);
	}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(const std::vector<Ty_>& vector)
		: data_(vector)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::vector<Ty_>&& vector) noexcept
		: data_(std::move(vector))
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(const basic_vector& vector)
		: data_(vector.data_)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(basic_vector&& vector) noexcept
		: data_(vector.data_)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::initializer_list<Ty_> list)
		: data_(list)
	{}

	template<typename Ty_>
	basic_vector<Ty_>& basic_vector<Ty_>::operator=(const basic_vector& vector)
	{
		data_ = vector.data_;
		return *this;
	}
	template<typename Ty_>
	basic_vector<Ty_>& basic_vector<Ty_>::operator=(basic_vector&& vector) noexcept
	{
		data_ = std::move(vector.data_);
		return *this;
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator==(const basic_vector& vector) const
	{
		if (data_.size() != vector.data_.size()) return false;

		return std::equal(data_.begin(), data_.end(), vector.data_.begin(), vector.data_.end());
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator!=(const basic_vector& vector) const
	{
		if (data_.size() != vector.data_.size()) return true;

		return !std::equal(data_.begin(), data_.end(), vector.data_.begin(), vector.data_.end());
	}
	template<typename Ty_>
	const Ty_& basic_vector<Ty_>::operator[](std::size_t index) const noexcept
	{
		return data_[index];
	}
	template<typename Ty_>
	Ty_& basic_vector<Ty_>::operator[](std::size_t index) noexcept
	{
		return data_[index];
	}

	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator=(const basic_object<Ty_>& object)
	{
		if (!details::instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator=(dynamic_cast<const basic_vector&>(object));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		if (!details::instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator=(dynamic_cast<basic_vector&&>(object));
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (!details::instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator==(dynamic_cast<const basic_vector&>(object));
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (!details::instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator!=(dynamic_cast<const basic_vector&>(object));
	}

	template<typename Ty_>
	void basic_vector<Ty_>::for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const
	{
		for (const Ty_& value : data_)
		{
			func(std::make_shared<basic_value<Ty_>>(value));
		}
	}

	template<typename Ty_>
	const Ty_& basic_vector<Ty_>::at(std::size_t index) const noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	Ty_& basic_vector<Ty_>::at(std::size_t index) noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::iterator basic_vector<Ty_>::begin() noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_iterator basic_vector<Ty_>::begin() const noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_iterator basic_vector<Ty_>::cbegin() const noexcept
	{
		return data_.cbegin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::iterator basic_vector<Ty_>::end() noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_iterator basic_vector<Ty_>::end() const noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_iterator basic_vector<Ty_>::cend() const noexcept
	{
		return data_.cend();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::reverse_iterator basic_vector<Ty_>::rbegin() noexcept
	{
		return data_.rbegin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_reverse_iterator basic_vector<Ty_>::rbegin() const noexcept
	{
		return data_.rbegin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_reverse_iterator basic_vector<Ty_>::crbegin() const noexcept
	{
		return data_.crbegin();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::reverse_iterator basic_vector<Ty_>::rend() noexcept
	{
		return data_.rend();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_reverse_iterator basic_vector<Ty_>::rend() const noexcept
	{
		return data_.rend();
	}
	template<typename Ty_>
	typename basic_vector<Ty_>::const_reverse_iterator basic_vector<Ty_>::crend() const noexcept
	{
		return data_.crend();
	}

	template<typename Ty_>
	bool basic_vector<Ty_>::empty() const noexcept
	{
		return data_.empty();
	}
	template<typename Ty_>
	std::size_t basic_vector<Ty_>::size() const noexcept
	{
		return data_.size();
	}
}

#endif