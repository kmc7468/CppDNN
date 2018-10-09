#ifndef CPPDNN_HEADER_DETAILS_UTILITY_HPP
#define CPPDNN_HEADER_DETAILS_UTILITY_HPP

#include <type_traits>

namespace cppdnn
{
	template<typename Ty1_, typename Ty2_>
	bool instance_of(Ty2_* value) noexcept
	{
		return dynamic_cast<Ty1_*>(const_cast<typename std::remove_cv<Ty2_>::type*>(value)) != nullptr;
	}
}

#endif