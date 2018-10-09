#ifndef CPPDNN_HEADER_EXCEPTION_HPP
#define CPPDNN_HEADER_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace cppdnn
{
	class invalid_type : public std::runtime_error
	{
	public:
		explicit invalid_type(const std::string& message);
		explicit invalid_type(const char* message);
	};
}

#include "details/exception.hpp"
#endif