#include <array>
#include <string>
#include <sstream>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing array of streamable types on char stream", "[array][char]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing an empty array") {
    std::array<int, 0> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing an array with some elements") {
    std::array v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
  SECTION("printing an array of strings") {
    std::array v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing an array of string_views") {
    std::array v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing an array of c strings") {
    std::array v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing an array of char") {
    std::array v{'x', 'y', 'w', 'z'};
    print(v, os);
    REQUIRE(os.str() == "[x, y, w, z]");
  }
  SECTION("printing an array of pairs") {
    std::array v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "[(1, 2), (3, 4)]");
  }
  SECTION("printing an array of tuples") {
    SECTION("starting with a fundamental type") {
      std::array v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "[(1, \"Hello\", 2.9), (3, \"world\", 4.1)]");
    }
    SECTION("not starting with a fundamental type") {
      std::array v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "[(\"Hello\", 1, 2.9), (\"world\", 3, 4.1)]");
    }
    SECTION("starting with a std::string") {
      std::array v{std::tuple{"Hello"s, 1, 2.9}, std::tuple{"world"s, 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "[(\"Hello\", 1, 2.9), (\"world\", 3, 4.1)]");
    }
  }
}

TEST_CASE( "printing array of streamable types on wchar_t stream", "[array][wchar_t]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing an empty array") {
    std::array<int, 0> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing an array with some elements") {
    std::array v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
  SECTION("printing an array of strings") {
    std::array v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing an array of string_views") {
    std::array v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing an array of c strings") {
    std::array v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing an array of char") {
    std::array v{L'x', L'y', L'w', L'z'};
    print(v, wos);
    REQUIRE(wos.str() == L"[x, y, w, z]");
  }
  SECTION("printing an array of pairs") {
    std::array v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, 2), (3, 4)]");
  }
  SECTION("printing an array of tuples") {
    SECTION("starting with a fundamental type") {
      std::array v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"[(1, \"Hello\", 2.9), (3, \"world\", 4.1)]");
    }
    SECTION("not starting with a fundamental type") {
      std::array v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"[(\"Hello\", 1, 2.9), (\"world\", 3, 4.1)]");
    }
    SECTION("starting with a std::string") {
      std::array v{std::tuple{L"Hello"s, 1, 2.9}, std::tuple{L"world"s, 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"[(\"Hello\", 1, 2.9), (\"world\", 3, 4.1)]");
    }
  }
}