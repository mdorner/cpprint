#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <mdorner/sprint.h>

TEST_CASE("sprint function", "[print]")
{
	std::string s;
	SECTION("Trival string literal works")
	{
		REQUIRE(mdorner::print::sprint("hello world") == "hello world");
	}
	SECTION("Compsoing string literals works")
	{
		REQUIRE(mdorner::print::sprint("this", "is", "a", "test") == "this is a test");
	}

	SECTION("Conversion of numbers works as expected")
	{
		REQUIRE(mdorner::print::sprint( "The number", 1, "is 1 and", 1.5, "is 1.5")
				=="The number 1 is 1 and 1.5 is 1.5");
	}
}
