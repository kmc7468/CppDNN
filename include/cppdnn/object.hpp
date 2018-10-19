#ifndef CPPDNN_HEADER_OBJECT_HPP
#define CPPDNN_HEADER_OBJECT_HPP

#include <cstddef>
#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	class basic_value;

	template<typename Ty_>
	class basic_object
	{
	public:
		basic_object(const basic_object& object) = delete;
		basic_object(basic_object&& object) = delete;
		virtual ~basic_object() = default;
		
	protected:
		basic_object() = default;

	public:
		virtual basic_object& operator=(const basic_object& object) = 0;
		virtual basic_object& operator=(basic_object&& object) = 0;
		virtual bool operator==(const basic_object& object) const = 0;
		virtual bool operator!=(const basic_object& object) const;

		virtual std::shared_ptr<basic_object<Ty_>> operator+(const basic_object& object) const = 0;
		virtual std::shared_ptr<basic_object<Ty_>> operator*(const basic_object& object) const = 0;
		virtual basic_object& operator+=(const basic_object& object) = 0;
		virtual basic_object& operator*=(const basic_object& object) = 0;

	public:
		virtual bool is_value() const noexcept;

		virtual std::shared_ptr<basic_object<Ty_>> copy() const = 0;
		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const = 0;
		virtual void apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) = 0;
	};

	using object = basic_object<double>;
	template<typename Ty_>
	using basic_object_ptr = std::shared_ptr<basic_object<Ty_>>;
	using object_ptr = basic_object_ptr<double>;

	template<typename Ty_>
	class basic_value_ref;

	template<typename Ty_>
	class basic_value : public basic_object<Ty_>
	{
	public:
		basic_value() noexcept(std::is_nothrow_default_constructible<Ty_>::value) = default;
		basic_value(const Ty_& value) noexcept(std::is_nothrow_copy_constructible<Ty_>::value);
		basic_value(Ty_&& value) noexcept(std::is_nothrow_move_constructible<Ty_>::value);
		basic_value(const basic_value& value) noexcept(std::is_nothrow_copy_constructible<Ty_>::value);
		basic_value(basic_value&& value) noexcept(std::is_nothrow_move_constructible<Ty_>::value);
		virtual ~basic_value() override = default;
	
	public:
		basic_value& operator=(const basic_value& value) noexcept(std::is_nothrow_copy_assignable<Ty_>::value);
		basic_value& operator=(basic_value&& value) noexcept(std::is_nothrow_move_assignable<Ty_>::value);
		bool operator==(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() == std::declval<Ty_>()));
		bool operator!=(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() != std::declval<Ty_>()));
		
		virtual basic_object<Ty_>& operator=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator=(basic_object<Ty_>&& object) override;
		virtual bool operator==(const basic_object<Ty_>& object) const override;
		virtual bool operator!=(const basic_object<Ty_>& object) const override;
		
		basic_value operator+(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()));
		basic_value operator+(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()));
		basic_value operator-(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()));
		basic_value operator-(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()));
		basic_value operator*(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()));
		basic_value operator*(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()));
		basic_value operator/(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()));
		basic_value operator/(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()));
		basic_value& operator+=(const basic_value& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator+(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator+(value));
		}
		basic_value& operator+=(const basic_value_ref<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator+(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator+(value));
		}
		basic_value& operator-=(const basic_value& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator-(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator-(value));
		}
		basic_value& operator-=(const basic_value_ref<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator-(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator-(value));
		}
		basic_value& operator*=(const basic_value& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator*(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator*(value));
		}
		basic_value& operator*=(const basic_value_ref<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator*(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator*(value));
		}
		basic_value& operator/=(const basic_value& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator/(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator/(value));
		}
		basic_value& operator/=(const basic_value_ref<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator/(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator/(value));
		}

		virtual std::shared_ptr<basic_object<Ty_>> operator+(const basic_object<Ty_>& object) const override;
		virtual std::shared_ptr<basic_object<Ty_>> operator*(const basic_object<Ty_>& object) const override;
		virtual basic_object<Ty_>& operator+=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator*=(const basic_object<Ty_>& object) override;

	public:
		virtual bool is_value() const noexcept override;

		virtual std::shared_ptr<basic_object<Ty_>> copy() const override;
		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const override;
		virtual void apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) override;

	public:
		const Ty_& data() const noexcept;
		Ty_& data() noexcept;

	private:
		Ty_ data_;
	};

	using value = basic_value<double>;

	template<typename Ty_>
	class basic_value_ref : public basic_object<Ty_>
	{
	public:
		basic_value_ref() noexcept = default;
		basic_value_ref(Ty_& value) noexcept;
		basic_value_ref(basic_value<Ty_>& value) noexcept;
		basic_value_ref(const basic_value_ref& value) noexcept;
		virtual ~basic_value_ref() override = default;

	public:
		basic_value_ref& operator=(const basic_value<Ty_>& value) noexcept;
		basic_value_ref& operator=(const basic_value_ref& value) noexcept;
		bool operator==(const basic_value_ref& value) const noexcept;
		bool operator!=(const basic_value_ref& value) const noexcept;

		virtual basic_object<Ty_>& operator=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator=(basic_object<Ty_>&& object) override;
		virtual bool operator==(const basic_object<Ty_>& object) const override;
		virtual bool operator!=(const basic_object<Ty_>& object) const override;

		basic_value<Ty_> operator+(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()));
		basic_value<Ty_> operator+(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()));
		basic_value<Ty_> operator-(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()));
		basic_value<Ty_> operator-(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()));
		basic_value<Ty_> operator*(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()));
		basic_value<Ty_> operator*(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()));
		basic_value<Ty_> operator/(const basic_value_ref& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()));
		basic_value<Ty_> operator/(const basic_value<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() / std::declval<Ty_>()));
		basic_value_ref& operator+=(const basic_value_ref& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator+(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator+(value));
		}
		basic_value_ref& operator+=(const basic_value<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator+(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator+(value));
		}
		basic_value_ref& operator-=(const basic_value_ref& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator-(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator-(value));
		}
		basic_value_ref& operator-=(const basic_value<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator-(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator-(value));
		}
		basic_value_ref& operator*=(const basic_value_ref& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator*(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator*(value));
		}
		basic_value_ref& operator*=(const basic_value<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator*(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator*(value));
		}
		basic_value_ref& operator/=(const basic_value_ref& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator/(std::declval<basic_value_ref<Ty_>>())))
		{
			return operator=(operator/(value));
		}
		basic_value_ref& operator/=(const basic_value<Ty_>& value) noexcept(std::is_nothrow_move_assignable<basic_value<Ty_>>::value && noexcept(operator/(std::declval<basic_value<Ty_>>())))
		{
			return operator=(operator/(value));
		}

		virtual std::shared_ptr<basic_object<Ty_>> operator+(const basic_object<Ty_>& object) const override;
		virtual std::shared_ptr<basic_object<Ty_>> operator*(const basic_object<Ty_>& object) const override;
		virtual basic_object<Ty_>& operator+=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator*=(const basic_object<Ty_>& object) override;

	public:
		virtual bool is_value() const noexcept override;
		
		virtual std::shared_ptr<basic_object<Ty_>> copy() const override;
		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const override;
		virtual void apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) override;

	public:
		const Ty_& data() const noexcept;
		Ty_& data() noexcept;

	private:
		Ty_* data_ = nullptr;
	};

	template<typename Ty_>
	std::shared_ptr<basic_value_ref<Ty_>> to_value_ref(const basic_object_ptr<Ty_>& object);
}

#include "details/object.hpp"
#endif