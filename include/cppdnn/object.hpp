#ifndef CPPDNN_HEADER_OBJECT_HPP
#define CPPDNN_HEADER_OBJECT_HPP

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>

namespace cppdnn
{
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

	public:
		virtual bool is_value() const noexcept;

		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const = 0;
	};

	using object = basic_object<double>;
	template<typename Ty_>
	using basic_object_ptr = std::shared_ptr<basic_object<Ty_>>;
	using object_ptr = basic_object_ptr<double>;

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

	public:
		virtual bool is_value() const noexcept override;

		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const override;

	private:
		Ty_ data_;
	};

	using value = basic_value<double>;
}

#include "details/object.hpp"
#endif