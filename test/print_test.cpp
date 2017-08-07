#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <sstream>
#include <mdorner/print.h>

using mdorner::print::print;

namespace
{
	// cf stream can be bound
	std::ostringstream static_oss;
	template<typename ...Args>
	void print_to_bound_stream(Args&& ...args)
	{
		print(static_oss, std::forward<Args>(args)...);
	}

	template<typename ...Args>
	void print_to_cout(Args&& ...args)
	{
		print(std::cout, std::forward<Args>(args)...);
	}

}

TEST_CASE("string_style_t works", "[print::detail::string_style_t]")
{
	const auto style = mdorner::print::detail::string_style_t("a", "b", "c");
	std::ostringstream oss;
	std::ostream& os = oss;
	style.visitTerminator(style.visitSeparator(style.visitSentinel(oss)));
	REQUIRE( oss.str() == "abc");
}

TEST_CASE("Print simple strings", "[print]")
{
	std::ostringstream oss;
	std::ostream& os = oss;
	SECTION("Trival string literal works")
	{
		print(os, "hello world");
		REQUIRE(os.good());
		REQUIRE(oss.good());
		REQUIRE(oss.str() == "hello world");
		oss.str("");
	}
	SECTION("Compsoing string literals works")
	{
		print(os, "this", "is", "a", "test");
		REQUIRE(os.good());
		REQUIRE(oss.good());
		REQUIRE(oss.str() == "this is a test");
		oss.str("");
	}

	SECTION("A stream can be bound to the first argument in a template function")
	{
		auto test_string = "Usually you would use cout here, but that is harder "
											 "to test, so we use a static string";
		print_to_bound_stream(test_string);
		REQUIRE(static_oss.good());
		REQUIRE(static_oss.str() == test_string);
		static_oss.str("");
	}

	SECTION("Composing to a bound stream")
	{
		print_to_bound_stream("this", "is", "a", "test");
		REQUIRE(static_oss.good());
		REQUIRE(static_oss.str() == "this is a test");
		static_oss.str("");
		print_to_cout("this", "test", "uses", "std::cout");
	}
}
