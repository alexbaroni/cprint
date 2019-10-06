#include <list>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing list of streamable types on char stream", "[list][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty list") {
    std::list<int> v{};
    print(v, os);
    REQUIRE(os.str() == "()");
  }
  SECTION("printing a list with some elements") {
    std::list v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "(1, 2, 3, 4, 5)");
  }
  SECTION("printing a list of strings") {
    std::list v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a list of string_views") {
    std::list v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a list of c strings") {
    std::list v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a list of char") {
    std::list v{'x', 'y', 'w', 'z'};
    print(v, os);
    REQUIRE(os.str() == "(x, y, w, z)");
  }
  SECTION("printing a list[ of pairs") {
    std::list v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "((1, 2), (3, 4))");
  }
  SECTION("printing a list of tuples") {
    SECTION("starting with a fundamental type") {
      std::list v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "((1, \"Hello\", 2.9), (3, \"world\", 4.1))");
    }
    SECTION("not starting with a fundamental type") {
      std::list v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "((\"Hello\", 1, 2.9), (\"world\", 3, 4.1))");
    }
  }
}

TEST_CASE( "printing list of streamable types on wchar_t stream", "[list][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty list") {
    std::list<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"()");
  }
  SECTION("printing a list with some elements") {
    std::list v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"(1, 2, 3, 4, 5)");
  }
  SECTION("printing a list of strings") {
    std::list v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a list of string_views") {
    std::list v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a list of c strings") {
    std::list v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a list of char") {
    std::list v{L'x', L'y', L'w', L'z'};
    print(v, wos);
    REQUIRE(wos.str() == L"(x, y, w, z)");
  }
  SECTION("printing a list of pairs") {
    std::list v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"((1, 2), (3, 4))");
  }
  SECTION("printing a list of tuples") {
    SECTION("starting with a fundamental type") {
      std::list v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"((1, \"Hello\", 2.9), (3, \"world\", 4.1))");
    }
    SECTION("not starting with a fundamental type") {
      std::list v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"((\"Hello\", 1, 2.9), (\"world\", 3, 4.1))");
    }
  }
}
