#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing set of streamable types on char stream", "[set][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty set") {
    std::set<int> v{};
    print(v, os);
    REQUIRE(os.str() == "{}");
  }
  SECTION("printing a set with some elements") {
    std::set v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "{1, 2, 3, 4, 5}");
  }
  SECTION("printing a set of strings") {
    std::set v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"world\"}");
  }
  SECTION("printing a set of string_views") {
    std::set v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"world\"}");
  }
  SECTION("printing a set of c strings") {
    std::set v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"world\"}");
  }
  SECTION("printing a set of char") {
    std::set v{'x', 'y', 'w', 'z'};
    print(v, os);
    REQUIRE(os.str() == "{w, x, y, z}");
  }
  SECTION("printing a set of pairs") {
    std::set v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "{(1, 2), (3, 4)}");
  }
  SECTION("printing a set of tuples") {
    SECTION("starting with a fundamental type") {
      std::set v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::set v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }
}

TEST_CASE( "printing set of streamable types on wchar_t stream", "[set][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty set") {
    std::set<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"{}");
  }
  SECTION("printing a set with some elements") {
    std::set v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"{1, 2, 3, 4, 5}");
  }
  SECTION("printing a set of strings") {
    std::set v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"world\"}");
  }
  SECTION("printing a set of string_views") {
    std::set v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"world\"}");
  }
  SECTION("printing a set of c strings") {
    std::set v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"world\"}");
  }
  SECTION("printing a set of char") {
    std::set v{L'x', L'y', L'w', L'z'};
    print(v, wos);
    REQUIRE(wos.str() == L"{w, x, y, z}");
  }
  SECTION("printing a set of pairs") {
    std::set v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"{(1, 2), (3, 4)}");
  }
  SECTION("printing a set of tuples") {
    SECTION("starting with a fundamental type") {
      std::set v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::set v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }
}
