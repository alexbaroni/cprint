#include <vector>
#include <sstream>
#include <string>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing vector of streamable types on char stream", "[vector][char]" ) {
  using namespace std::string_literals;
  std::ostringstream os;

  SECTION("printing an empty vector") {
    std::vector<int> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing a vector with some elements") {
    std::vector v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
  SECTION("printing a vector of strings") {
    std::vector v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
}

TEST_CASE( "printing vector of streamable types on wchar_t stream", "[vector][wchar_t]" ) {
  std::wostringstream wos;

  SECTION("printing an empty vector") {
    std::vector<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a vector with some elements") {
    std::vector<int> v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
//  SECTION("printing a vector of strings") {
//    std::vector<std::wstring> v{"hello"s, "world"s};
//    print(v, wos);
//    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
//  }
}
