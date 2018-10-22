#include <vector>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing vector of streamable types on char stream", "[vector][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

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
  SECTION("printing a vector of string_views") {
    std::vector v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing a vector of c strings") {
    std::vector v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing a vector of pairs") {
    std::vector v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "[(1, 2), (3, 4)]");
  }
  SECTION("printing a vector of tuples") {
    std::vector v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
    print(v, os);
    REQUIRE(os.str() == "[(1, \"Hello\", 2.9), (3, \"world\", 4.1)]");
  }
}

TEST_CASE( "printing vector of streamable types on wchar_t stream", "[vector][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty vector") {
    std::vector<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a vector with some elements") {
    std::vector v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
  SECTION("printing a vector of strings") {
    std::vector v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing a vector of string_views") {
    std::vector v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing a vector of c strings") {
    std::vector v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing a vector of pairs") {
    std::vector v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, 2), (3, 4)]");
  }
}
