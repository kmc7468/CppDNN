#ifndef CPPDNN_HEADER_OBJECT_HPP
#define CPPDNN_HEADER_OBJECT_HPP

#include <memory>

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
	};

	using object = basic_object<double>;
	using object_ptr = std::shared_ptr<object>;
}

#include "details/object.hpp"
#endif