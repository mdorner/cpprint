#ifndef MDORNER_PRINT_SPRINT_H
#define MDORNER_PRINT_SPRINT_H

#include <mdorner/print.h>

#include <string>
#include <sstream>

namespace mdorner
{
	namespace print
	{
		template <typename ...Args>
		std::string sprint(Args&& ...args)
		{
			std::ostringstream oss;
			mdorner::print::print(oss, std::forward<Args>(args)...);
			return oss.str();
		}
	}
}

#endif
