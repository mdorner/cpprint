#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <sstream>
#include <mdorner/print.h>

using mdorner::print::print;

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
	}
	oss.clear();
	SECTION("Compsoing string literals works")
	{
		print(os, "this", "is", "a", "test");
		REQUIRE(os.good());
		REQUIRE(oss.good());
		REQUIRE(oss.str() == "this is a test");
	}
	oss.clear();
}
