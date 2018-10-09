#ifndef CPPDNN_HEADER_DETAILS_EXCEPTION_HPP
#define CPPDNN_HEADER_DETAILS_EXCEPTION_HPP

namespace cppdnn
{
	invalid_type::invalid_type(const std::string& message)
		: std::runtime_error(message)
	{}
	invalid_type::invalid_type(const char* message)
		: std::runtime_error(message)
	{}
}

#endif