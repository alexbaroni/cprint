#include <forward_list>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing forward_list of streamable types on char stream", "[forward_list][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty forward_list") {
    std::forward_list<int> v{};
    print(v, os);
    REQUIRE(os.str() == "()");
  }
  SECTION("printing a forward_list with some elements") {
    std::forward_list v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "(1, 2, 3, 4, 5)");
  }
  SECTION("printing a forward_list of strings") {
    std::forward_list v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of string_views") {
    std::forward_list v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of c strings") {
    std::forward_list v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of char") {
    std::forward_list v{'x', 'y', 'w', 'z'};
    print(v, os);
    REQUIRE(os.str() == "(x, y, w, z)");
  }
  SECTION("printing a forward_list[ of pairs") {
    std::forward_list v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "((1, 2), (3, 4))");
  }
  SECTION("printing a forward_list of tuples") {
    SECTION("starting with a fundamental type") {
      std::forward_list v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "((1, \"Hello\", 2.9), (3, \"world\", 4.1))");
    }
    SECTION("not starting with a fundamental type") {
      std::forward_list v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "((\"Hello\", 1, 2.9), (\"world\", 3, 4.1))");
    }
  }
}

TEST_CASE( "printing forward_list of streamable types on wchar_t stream", "[forward_list][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty forward_list") {
    std::forward_list<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"()");
  }
  SECTION("printing a forward_list with some elements") {
    std::forward_list v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"(1, 2, 3, 4, 5)");
  }
  SECTION("printing a forward_list of strings") {
    std::forward_list v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of string_views") {
    std::forward_list v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of c strings") {
    std::forward_list v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"(\"hello\", \"world\")");
  }
  SECTION("printing a forward_list of char") {
    std::forward_list v{L'x', L'y', L'w', L'z'};
    print(v, wos);
    REQUIRE(wos.str() == L"(x, y, w, z)");
  }
  SECTION("printing a forward_list of pairs") {
    std::forward_list v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"((1, 2), (3, 4))");
  }
  SECTION("printing a forward_list of tuples") {
    SECTION("starting with a fundamental type") {
      std::forward_list v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"((1, \"Hello\", 2.9), (3, \"world\", 4.1))");
    }
    SECTION("not starting with a fundamental type") {
      std::forward_list v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"((\"Hello\", 1, 2.9), (\"world\", 3, 4.1))");
    }
  }
}
