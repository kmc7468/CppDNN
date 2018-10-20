#ifndef CPPDNN_HEADER_DETAILS_OBJECT_HPP
#define CPPDNN_HEADER_DETAILS_OBJECT_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/utility.hpp>

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

	template<typename Ty_>
	std::string basic_object<Ty_>::to_string() const
	{
		return to_string(true);
	}
	template<typename Ty_>
	std::string basic_object<Ty_>::to_string(bool detail) const
	{
		return to_string_priv(detail);
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
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<basic_value&&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator==(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator!=(dynamic_cast<const basic_value&>(object));
	}

	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator+(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value(data_ + value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator+(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value(data_ + value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator-(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value(data_ - value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator-(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value(data_ - value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator*(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{
		return basic_value(data_ * value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator*(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{
		return basic_value(data_ * value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator/(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()))
	{
		return basic_value(data_ / value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator/(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()))
	{
		return basic_value(data_ / value.data());
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value<Ty_>::operator+(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value>(&object))
		{
			return std::make_shared<basic_value>(operator+(dynamic_cast<const basic_value&>(object)));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return std::make_shared<basic_value>(operator+(dynamic_cast<const basic_value_ref<Ty_>&>(object)));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");
	}
	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value<Ty_>::operator*(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value>(&object))
		{
			return std::make_shared<basic_value>(operator*(dynamic_cast<const basic_value&>(object)));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return std::make_shared<basic_value>(operator*(dynamic_cast<const basic_value_ref<Ty_>&>(object)));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator+=(const basic_object<Ty_>& object)
	{
		if (instance_of<basic_value>(&object))
		{
			return operator+=(dynamic_cast<const basic_value&>(object));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return operator+=(dynamic_cast<const basic_value_ref<Ty_>&>(object));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator*=(const basic_object<Ty_>& object)
	{
		if (instance_of<basic_value>(&object))
		{
			return operator*=(dynamic_cast<const basic_value&>(object));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return operator*=(dynamic_cast<const basic_value_ref<Ty_>&>(object));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");
	}

	template<typename Ty_>
	bool basic_value<Ty_>::is_value() const noexcept
	{
		return true;
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value<Ty_>::copy() const
	{
		return std::make_shared<basic_value<Ty_>>(data_);
	}
	template<typename Ty_>
	void basic_value<Ty_>::for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>&) const
	{
		throw not_impl("cppdnn::basic_value::for_each isn't implemented.");
	}
	template<typename Ty_>
	void basic_value<Ty_>::apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>&)
	{
		throw not_impl("cppdnn::basic_value::apply isn't implemented.");
	}

	template<typename Ty_>
	std::string basic_value<Ty_>::to_string_priv(bool detail) const
	{
		std::string result;

		if (detail)
		{
			result = "value(";
		}

		result += std::to_string(data_);

		if (detail)
		{
			result += ')';
		}

		return result;
	}

	template<typename Ty_>
	const Ty_& basic_value<Ty_>::data() const noexcept
	{
		return data_;
	}
	template<typename Ty_>
	Ty_& basic_value<Ty_>::data() noexcept
	{
		return data_;
	}
}

namespace cppdnn
{
	template<typename Ty_>
	basic_value_ref<Ty_>::basic_value_ref(Ty_& value) noexcept
		: data_(&value)
	{}
	template<typename Ty_>
	basic_value_ref<Ty_>::basic_value_ref(basic_value<Ty_>& value) noexcept
		: data_(value.data())
	{}
	template<typename Ty_>
	basic_value_ref<Ty_>::basic_value_ref(const basic_value_ref& value) noexcept
		: data_(value.data_)
	{}

	template<typename Ty_>
	basic_value_ref<Ty_>& basic_value_ref<Ty_>::operator=(const basic_value<Ty_>& value) noexcept
	{
		*data_ = value.data();
		return *this;
	}
	template<typename Ty_>
	basic_value_ref<Ty_>& basic_value_ref<Ty_>::operator=(const basic_value_ref& value) noexcept
	{
		data_ = value.data_;
		return *this;
	}
	template<typename Ty_>
	bool basic_value_ref<Ty_>::operator==(const basic_value_ref& value) const noexcept
	{
		return data_ == value.data_;
	}
	template<typename Ty_>
	bool basic_value_ref<Ty_>::operator!=(const basic_value_ref& value) const noexcept
	{
		return data_ != value.data_;
	}

	template<typename Ty_>
	basic_object<Ty_>& basic_value_ref<Ty_>::operator=(const basic_object<Ty_>& object)
	{
		if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return operator=(dynamic_cast<const basic_value_ref<Ty_>&>(object));
		}
		else if (instance_of<basic_value<Ty_>>(&object))
		{
			data_ = const_cast<Ty_*>(&dynamic_cast<const basic_value<Ty_>&>(object).data());
			return *this;
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value_ref<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		return operator=(object);
	}
	template<typename Ty_>
	bool basic_value_ref<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return data_ == dynamic_cast<const basic_value_ref<Ty_>&>(object).data_;
		}
		else if (instance_of<basic_value<Ty_>>(&object))
		{
			return data_ == &dynamic_cast<const basic_value<Ty_>&>(object).data();
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
	template<typename Ty_>
	bool basic_value_ref<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return data_ != dynamic_cast<const basic_value_ref<Ty_>&>(object).data_;
		}
		else if (instance_of<basic_value<Ty_>>(&object))
		{
			return data_ != &dynamic_cast<const basic_value<Ty_>&>(object).data();
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
		
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator+(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ + *value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator+(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ + value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator-(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ - *value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator-(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ - value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator*(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ * *value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator*(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ * value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator/(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ / *value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value_ref<Ty_>::operator/(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()))
	{
		return basic_value<Ty_>(*data_ / value.data());
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value_ref<Ty_>::operator+(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value<Ty_>>(&object))
		{
			return std::make_shared<basic_value<Ty_>>(operator+(dynamic_cast<const basic_value<Ty_>&>(object)));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return std::make_shared<basic_value<Ty_>>(operator+(dynamic_cast<const basic_value_ref&>(object)));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value_ref<Ty_>::operator*(const basic_object<Ty_>& object) const
	{
		if (instance_of<basic_value<Ty_>>(&object))
		{
			return std::make_shared<basic_value<Ty_>>(operator*(dynamic_cast<const basic_value<Ty_>&>(object)));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return std::make_shared<basic_value<Ty_>>(operator*(dynamic_cast<const basic_value_ref&>(object)));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value_ref<Ty_>::operator+=(const basic_object<Ty_>& object)
	{
		if (instance_of<basic_value<Ty_>>(&object))
		{
			return operator+=(dynamic_cast<const basic_value<Ty_>&>(object));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return operator+=(dynamic_cast<const basic_value_ref&>(object));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value_ref<Ty_>::operator*=(const basic_object<Ty_>& object)
	{
		if (instance_of<basic_value<Ty_>>(&object))
		{
			return operator*=(dynamic_cast<const basic_value<Ty_>&>(object));
		}
		else if (instance_of<basic_value_ref<Ty_>>(&object))
		{
			return operator*=(dynamic_cast<const basic_value_ref&>(object));
		}
		else
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value_ref.");
	}

	template<typename Ty_>
	bool basic_value_ref<Ty_>::is_value() const noexcept
	{
		return true;
	}

	template<typename Ty_>
	std::shared_ptr<basic_object<Ty_>> basic_value_ref<Ty_>::copy() const
	{
		return std::make_shared<basic_value_ref<Ty_>>(*data_);
	}
	template<typename Ty_>
	void basic_value_ref<Ty_>::for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>&) const
	{
		throw not_impl("cppdnn::basic_value_ref::for_each isn't implemented.");
	}
	template<typename Ty_>
	void basic_value_ref<Ty_>::apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>&)
	{
		throw not_impl("cppdnn::basic_value_ref::apply isn't implemented.");
	}

	template<typename Ty_>
	std::string basic_value_ref<Ty_>::to_string_priv(bool detail) const
	{
		std::string result;

		if (detail)
		{
			result = "value(ref: ";
		}

		result += std::to_string(*data_);

		if (detail)
		{
			result += ')';
		}

		return result;
	}

	template<typename Ty_>
	const Ty_& basic_value_ref<Ty_>::data() const noexcept
	{
		return *data_;
	}
	template<typename Ty_>
	Ty_& basic_value_ref<Ty_>::data() noexcept
	{
		return *data_;
	}

	template<typename Ty_>
	std::shared_ptr<basic_value_ref<Ty_>> to_value_ref(const basic_object_ptr<Ty_>& object)
	{
		if (instance_of<basic_value<Ty_>>(object.get()))
		{
			return std::make_shared<basic_value_ref<Ty_>>(*const_cast<Ty_*>(&dynamic_cast<basic_value<Ty_>*>(object.get())->data()));
		}
		else if (instance_of<basic_value_ref<Ty_>>(object.get()))
		{
			return std::dynamic_pointer_cast<basic_value_ref<Ty_>>(object);
		}
		else
			throw invalid_type("");
	}
}

#endif