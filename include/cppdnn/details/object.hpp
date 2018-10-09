#ifndef CPPDNN_HEADER_DETAILS_OBJECT_HPP
#define CPPDNN_HEADER_DETAILS_OBJECT_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/details/utility.hpp>

namespace cppdnn
{
	template<typename Ty_>
	bool basic_object<Ty_>::operator!=(const basic_object& object) const
	{
		return !operator==(object);
	}

	template<typename Ty_>
	bool basic_object<Ty_>::is_value() const noexcept
	{
		return false;
	}
}

namespace cppdnn
{
	template<typename Ty_>
	basic_value<Ty_>::basic_value(const Ty_& value) noexcept(std::is_nothrow_copy_constructible<Ty_>::value)
		: data_(value)
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(Ty_ && value) noexcept(std::is_nothrow_move_constructible<Ty_>::value)
		: data_(std::move(value))
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(const basic_value& value)noexcept(std::is_nothrow_copy_constructible<Ty_>::value)
		: data_(value.data_)
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(basic_value&& value) noexcept(std::is_nothrow_move_constructible<Ty_>::value)
		: data_(std::move(value.data_))
	{}

	template<typename Ty_>
	basic_value<Ty_>& basic_value<Ty_>::operator=(const basic_value& value) noexcept(std::is_nothrow_copy_assignable<Ty_>::value)
	{
		data_ = value.data_;
		return *this;
	}
	template<typename Ty_>
	basic_value<Ty_>& basic_value<Ty_>::operator=(basic_value&& value) noexcept(std::is_nothrow_move_assignable<Ty_>::value)
	{
		data_ = std::move(value.data_);
		return *this;
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator==(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() == std::declval<Ty_>()))
	{
		return data_ == value.data_;
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator!=(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() != std::declval<Ty_>()))
	{
		return data_ != value.data_;
	}

	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator=(const basic_object<Ty_>& object)
	{
		if (!details::instance_of<basic_value<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		if (!details::instance_of<basic_value<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<basic_value&&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (!details::instance_of<basic_value<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator==(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (!details::instance_of<basic_value<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator!=(dynamic_cast<const basic_value&>(object));
	}

	template<typename Ty_>
	bool basic_value<Ty_>::is_value() const noexcept
	{
		return true;
	}

	template<typename Ty_>
	void basic_value<Ty_>::for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>&) const
	{
		throw not_impl("cppdnn::basic_value::for_each isn't implemented.");
	}
}

#endif