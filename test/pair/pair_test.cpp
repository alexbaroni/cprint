#include <string>
#include <utility>
#include <sstream>
#include "stl2/detail/span.hpp"
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing pair of streamable types on char stream", "[pair][char]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing an int pair") {
    std::pair p{1, 2};
    print(p, os);
    REQUIRE(os.str() == "(1, 2)");
  }
  SECTION("printing a float pair") {
    std::pair p{1.2, 2.2};
    print(p, os);
    REQUIRE(os.str() == "(1.2, 2.2)");
  }
  SECTION("printing a pair with a string") {
    std::pair p{1, "Hello"s};
    print(p, os);
    REQUIRE(os.str() == "(1, \"Hello\")");
  }
  SECTION("printing a pair with a string_view") {
    std::pair p{1, "World"sv};
    print(p, os);
    REQUIRE(os.str() == "(1, \"World\")");
  }
  SECTION("printing a pair with a c string") {
    std::pair p{1, "World"};
    print(p, os);
    REQUIRE(os.str() == "(1, \"World\")");
  }

// gcc crash on template limits
//  SECTION("printing a pair with a char span") {
//    std::experimental::ranges::v1::ext::span sp{"World"};
//    std::pair p{1, sp};
//    print(p, os);
//    REQUIRE(os.str() == "(1, \"World\")");
//  }
}

TEST_CASE( "printing pair of streamable types on wchar_t stream", "[pair][wchar_t]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing an int pair") {
    std::pair p{1, 2};
    print(p, wos);
    REQUIRE(wos.str() == L"(1, 2)");
  }
  SECTION("printing a float pair") {
    std::pair p{1.2, 2.2};
    print(p, wos);
    REQUIRE(wos.str() == L"(1.2, 2.2)");
  }
  SECTION("printing a pair with a string") {
    std::pair p{1, L"Hello"s};
    print(p, wos);
    REQUIRE(wos.str() == L"(1, \"Hello\")");
  }
  SECTION("printing a pair with a string_view") {
    std::pair p{1, L"World"sv};
    print(p, wos);
    REQUIRE(wos.str() == L"(1, \"World\")");
  }
  SECTION("printing a pair with a c string") {
    std::pair p{1, L"World"};
    print(p, wos);
    REQUIRE(wos.str() == L"(1, \"World\")");
  }
}