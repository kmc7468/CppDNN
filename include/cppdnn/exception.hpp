#ifndef CPPDNN_HEADER_EXCEPTION_HPP
#define CPPDNN_HEADER_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace cppdnn
{
	class invalid_type : public std::runtime_error
	{
	public:
		using std::runtime_error::runtime_error;
	};
	
	class not_impl : public std::runtime_error
	{
	public:
		using std::runtime_error::runtime_error;
	};
}

#endif