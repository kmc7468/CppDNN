#ifndef CPPDNN_HEADER_DETAILS_OBJECT_HPP
#define CPPDNN_HEADER_DETAILS_OBJECT_HPP

namespace cppdnn
{
	template<typename Ty_>
	bool basic_object<Ty_>::operator!=(const basic_object& object) const
	{
		return !operator==(object);
	}
}

#endif