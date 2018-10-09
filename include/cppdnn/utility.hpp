#ifndef CPPDNN_HEADER_UTILITY_HPP
#define CPPDNN_HEADER_UTILITY_HPP

#include <type_traits>

namespace cppdnn
{
	template<typename Ty1_, typename Ty2_>
	bool instance_of(Ty2_* value) noexcept;
}

#include "details/utility.hpp"
#endif