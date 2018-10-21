#ifndef CPPDNN_HEADER_VECTOR_HPP
#define CPPDNN_HEADER_VECTOR_HPP

#include <cppdnn/object.hpp>

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <vector>

namespace cppdnn
{
	namespace details
	{
		template<typename Ty_>
		struct is_object_ptr
		{
			static constexpr bool value = true;
		};
		template<template<typename> typename Ty_, typename Elem_>
		struct is_object_ptr<std::shared_ptr<Ty_<Elem_>>>
		{
			static constexpr bool value = std::is_base_of<basic_object<Elem_>, Ty_<Elem_>>::value;
		};
	}

	template<typename Ty_>
	class basic_vector : public basic_object<Ty_>
	{
	public:
		using iterator = typename std::vector<Ty_>::iterator;
		using const_iterator = typename std::vector<Ty_>::const_iterator;
		using reverse_iterator = typename std::vector<Ty_>::reverse_iterator;
		using const_reverse_iterator = typename std::vector<Ty_>::const_reverse_iterator;

	public:
		basic_vector() = default;
		basic_vector(std::size_t size);
		basic_vector(const std::vector<Ty_>& vector);
		basic_vector(std::vector<Ty_>&& vector) noexcept;
		basic_vector(const basic_vector& vector);
		basic_vector(basic_vector&& vector) noexcept;
		basic_vector(std::initializer_list<Ty_> list);
		virtual ~basic_vector() override = default;
		
	public:
		basic_vector& operator=(const basic_vector& vector);
		basic_vector& operator=(basic_vector&& vector) noexcept;
		bool operator==(const basic_vector& vector) const;
		bool operator!=(const basic_vector& vector) const;
		const Ty_& operator[](std::size_t index) const noexcept;
		Ty_& operator[](std::size_t index) noexcept;

		virtual basic_object<Ty_>& operator=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator=(basic_object<Ty_>&& object) override;
		virtual bool operator==(const basic_object<Ty_>& object) const override;
		virtual bool operator!=(const basic_object<Ty_>& object) const override;

		basic_value<Ty_> operator*(const basic_vector<Ty_>& vector) const;

		virtual std::shared_ptr<basic_object<Ty_>> operator+(const basic_object<Ty_>& object) const override;
		virtual std::shared_ptr<basic_object<Ty_>> operator*(const basic_object<Ty_>& object) const override;
		virtual basic_object<Ty_>& operator+=(const basic_object<Ty_>& object) override;
		virtual basic_object<Ty_>& operator*=(const basic_object<Ty_>& object) override;

	public:
		virtual std::shared_ptr<basic_object<Ty_>> copy() const override;
		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const override;
		virtual void apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) override;

	protected:
		virtual std::string to_string_priv(bool detail) const override;

	public:
		const Ty_& at(std::size_t index) const noexcept;
		Ty_& at(std::size_t index) noexcept;
		iterator begin() noexcept;
		const_iterator begin() const noexcept;
		const_iterator cbegin() const noexcept;
		iterator end() noexcept;
		const_iterator end() const noexcept;
		const_iterator cend() const noexcept;
		reverse_iterator rbegin() noexcept;
		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator crbegin() const noexcept;
		reverse_iterator rend() noexcept;
		const_reverse_iterator rend() const noexcept;
		const_reverse_iterator crend() const noexcept;

		bool empty() const noexcept;
		std::size_t size() const noexcept;

	private:
		template<typename Ty2_>
		typename std::enable_if<details::is_object_ptr<Ty2_>::value>::type for_each_(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const;
		template<typename Ty2_>
		typename std::enable_if<!details::is_object_ptr<Ty2_>::value>::type for_each_(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const;
		template<typename Ty2_>
		typename std::enable_if<details::is_object_ptr<Ty2_>::value>::type apply_(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) const;
		template<typename Ty2_>
		typename std::enable_if<!details::is_object_ptr<Ty2_>::value>::type apply_(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) const;

	private:
		std::vector<Ty_> data_;
	};

	using vector = basic_vector<double>;

	template<typename Ty_ = double, typename... Args_>
	std::shared_ptr<basic_vector<Ty_>> make_vector(Args_&&... args);
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_arithmetic_vector(Ty_&& first, Ty_&& last);
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_arithmetic_vector(Ty_&& first, Ty_&& last, Ty_&& diff);
	template<typename Ty_>
	std::shared_ptr<basic_vector<Ty_>> make_geometric_vector(Ty_&& first, Ty_&& last, Ty_&& ratio);
}

#include "details/vector.hpp"
#endif