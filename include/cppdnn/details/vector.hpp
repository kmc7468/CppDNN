#ifndef CPPDNN_HEADER_DETAILS_VECTOR_HPP
#define CPPDNN_HEADER_DETAILS_VECTOR_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/utility.hpp>

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
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator=(dynamic_cast<const basic_vector&>(object));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator=(dynamic_cast<basic_vector&&>(object));
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator==(dynamic_cast<const basic_vector&>(object));
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");

		return operator!=(dynamic_cast<const basic_vector&>(object));
	}

	template<typename Ty_>
	basic_value<Ty_> basic_vector<Ty_>::operator*(const basic_vector<Ty_>& vector) const
	{
		if (size() != vector.size())
			throw incompatible_argument("The size of argument 'vector' isn't compatible with it.");

		Ty_ result = 0;

		for (std::size_t i = 0; i < size(); ++i)
		{
			result += data_[i] * vector.data_[i];
		}

		return result;
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_vector<Ty_>::operator+(const basic_object<Ty_>&) const
	{
		throw not_impl("cppdnn::basic_vector::operator+ isn't implemented.");
	}
	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_vector<Ty_>::operator*(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return std::make_shared<basic_value<Ty_>>(operator*(dynamic_cast<const basic_vector&>(object)));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator+=(const basic_object<Ty_>&)
	{
		throw not_impl("cppdnn::basic_vector::operator+= isn't implemented.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator*=(const basic_object<Ty_>&)
	{
		throw not_impl("cppdnn::basic_vector::operator*= isn't implemented.");
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_vector<Ty_>::copy() const
	{
		return std::make_shared<basic_vector<Ty_>>(data_);
	}
	template<typename Ty_>
	void basic_vector<Ty_>::for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const
	{
		for_each_<Ty_>(func);
	}
	template<typename Ty_>
	void basic_vector<Ty_>::apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func)
	{
		apply_<Ty_>(func);
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
	template<typename Ty2_>
	typename std::enable_if<details::is_object_ptr<Ty2_>::value>::type basic_vector<Ty_>::for_each_(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const
	{
		std::shared_ptr<basic_value_ref<Ty_>> data = std::make_shared<basic_value_ref<Ty_>>();

		for (const Ty_& value : data_)
		{
			*data = basic_value_ref<Ty_>(const_cast<Ty_&>(value));
			func(data);
		}
	}
	template<typename Ty_>
	template<typename Ty2_>
	typename std::enable_if<!details::is_object_ptr<Ty2_>::value>::type basic_vector<Ty_>::for_each_(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const
	{
		std::shared_ptr<basic_value_ref<Ty_>> data = std::make_shared<basic_value_ref<Ty_>>();

		for (const Ty_& value : data_)
		{
			*data = basic_value_ref<Ty_>(const_cast<Ty_&>(value));
			func(data);
		}
	}
	template<typename Ty_>
	template<typename Ty2_>
	typename std::enable_if<details::is_object_ptr<Ty2_>::value>::type basic_vector<Ty_>::apply_(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) const
	{
		std::shared_ptr<basic_value_ref<Ty_>> data = std::make_shared<basic_value_ref<Ty_>>();

		for (const Ty_& value : data_)
		{
			*data = basic_value_ref<Ty_>(const_cast<Ty_&>(value));
			func(data);
		}
	}
	template<typename Ty_>
	template<typename Ty2_>
	typename std::enable_if<!details::is_object_ptr<Ty2_>::value>::type basic_vector<Ty_>::apply_(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) const
	{
		std::shared_ptr<basic_value_ref<Ty_>> data = std::make_shared<basic_value_ref<Ty_>>();

		for (Ty_& value : data_)
		{
			*data = value;
			func(data);
		}
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

	template<typename Ty_, typename... Args_>
	std::shared_ptr<basic_vector<Ty_>> make_vector(Args_&&... args)
	{
		return std::make_shared<basic_vector<Ty_>>(std::vector<Ty_>{ static_cast<Ty_>(std::forward<Args_>(args))... });
	}
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_arithmetic_vector(Ty_&& first, Ty_&& last)
	{
		return make_arithmetic_vector<Ty_>(std::forward<Ty_>(first), std::forward<Ty_>(last), 1);
	}
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_arithmetic_vector(Ty_&& first, Ty_&& last, Ty_&& diff)
	{
		std::vector<Ty_> vector;

		if (first > last)
		{
			for (Ty_ i = first; i >= last; i -= diff)
			{
				vector.push_back(i);
			}
		}
		else
		{
			for (Ty_ i = first; i <= last; i += diff)
			{
				vector.push_back(i);
			}
		}

		return std::make_shared<basic_vector<Ty_>>(std::move(vector));
	}
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_geometric_vector(Ty_&& first, Ty_&& last, Ty_&& ratio)
	{
		std::vector<Ty_> vector;

		if (first > last)
		{
			for (Ty_ i = first; i >= last; i /= ratio)
			{
				vector.push_back(i);
			}
		}
		else
		{
			for (Ty_ i = first; i <= last; i *= ratio)
			{
				vector.push_back(i);
			}
		}

		return std::make_shared<basic_vector<Ty_>>(std::move(vector));
	}
}

#endif