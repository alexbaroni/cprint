#include <sstream>
#include "stl2/detail/span.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing span on char stream", "[span][char]" )
{
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing an empty span") {
    std::experimental::ranges::v1::ext::span<int> sp{};
    print(sp, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing a span with one element") {
    int a[] = {0};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, os);
    REQUIRE(os.str() == "[0]");
  }
  SECTION("printing a span with some elements") {
    int a[] = {1,2,3,4,5};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
  SECTION("printing a span with some char") {
    char a[] = {'h','e','l','l','o','\0'};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, os);
    REQUIRE(os.str() == "\"hello\"");
  }
}

TEST_CASE( "printing span on wchar_t stream", "[span][wchar_t]" )
{
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing an empty span") {
    std::experimental::ranges::v1::ext::span<int> sp{};
    print(sp, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a span with one element") {
    int a[] = {0};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, wos);
    REQUIRE(wos.str() == L"[0]");
  }
  SECTION("printing a span with some elements") {
    int a[] = {1, 2, 3, 4, 5};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
  SECTION("printing a span with some wchar_t") {
    wchar_t a[] = {L'h', L'e', L'l', L'l', L'o', L'\0'};
    std::experimental::ranges::v1::ext::span sp{a};
    print(sp, wos);
    REQUIRE(wos.str() == L"\"hello\"");
  }
}