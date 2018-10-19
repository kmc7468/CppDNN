#ifndef CPPDNN_HEADER_EXCEPTION_HPP
#define CPPDNN_HEADER_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace cppdnn
{
#define ERROR(base, name)										\
	class name : public std:: base								\
	{															\
	public:														\
		using std:: base :: base;								\
	}
#define RUNTIME_ERROR(name) ERROR(runtime_error, name)

	RUNTIME_ERROR(invalid_type);
	RUNTIME_ERROR(not_impl);
	RUNTIME_ERROR(incompatible_argument);
}

#endif