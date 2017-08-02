#ifndef MDORNER_PRINT_PRINT_H
#define MDORNER_PRINT_PRINT_H

#include <string>
#include <ostream>

namespace mdorner
{
	namespace print
	{
		namespace detail
		{
			class style_t
			{
				public:
					virtual std::ostream& visitSentinel(std::ostream& os) const = 0;
					virtual std::ostream& visitSeparator(std::ostream& os) const = 0;
					virtual std::ostream& visitTerminator(std::ostream& os) const = 0;
			};

			class string_style_t : public style_t
			{
				std::string sentinel_;
				std::string separator_;
				std::string terminator_;
				public:
				string_style_t(
						std::string sentinel, std::string separator, std::string terminator):
					sentinel_(std::move(sentinel)),
					separator_(std::move(separator)),
					terminator_(std::move(terminator))
				{}
				std::ostream& visitSentinel(std::ostream& os) const override
				{
					return os << sentinel_;
				}
				std::ostream& visitSeparator(std::ostream& os) const override
				{
					return os << sentinel_;
				}
				std::ostream& visitTerminator(std::ostream& os) const override
				{
					return os << sentinel_;
				}
			};

			template <typename T, typename ...Args>
				std::ostream& __print(const style_t& style, std::ostream& os, T&& val, Args&&... args)
				{
					return __print(style.visitSeparator(os << std::forward<T>(val)), std::forward<Args>(args)...);
				}

			template <typename T>
				std::ostream& __print(const style_t& style, std::ostream& os, T&& val)
				{
					return style.visitTerminator(os << std::forward<T>(val));
				}
		} // end detail namespace

		template <typename ...Args>
			void print(std::ostream& os, Args&&... args)
			{
				const auto style = detail::string_style_t("", " ", "");
				detail::__print(style, style.visitSentinel(os), std::forward<Args>(args)...);
			}
	}
}

#endif
