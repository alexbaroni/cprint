#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing multiset of streamable types on char stream", "[multiset][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty multiset") {
    std::multiset<int> v{};
    print(v, os);
    REQUIRE(os.str() == "{}");
  }
  SECTION("printing a multiset with some elements") {
    std::multiset v{1, 2, 2, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "{1, 2, 2, 4, 5}");
  }
  SECTION("printing a multiset of strings") {
    std::multiset v{"hello"s, "world"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"world\", \"world\"}");
  }
  SECTION("printing a multiset of string_views") {
    std::multiset v{"hello"sv, "hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"hello\", \"world\"}");
  }
  SECTION("printing a multiset of c strings") {
    std::multiset v{"hello", "hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "{\"hello\", \"hello\", \"world\"}");
  }
  SECTION("printing a multiset of char") {
    std::multiset v{'x', 'y', 'w', 'x'};
    print(v, os);
    REQUIRE(os.str() == "{w, x, x, y}");
  }
  SECTION("printing a multiset of pairs") {
    std::multiset v{std::pair{1, 2}, std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "{(1, 2), (1, 2), (3, 4)}");
  }
  SECTION("printing a multiset of tuples") {
    SECTION("starting with a fundamental type") {
      std::multiset v{std::tuple{1, "Hello", 2.9}, std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(1, \"Hello\", 2.9), (1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::multiset v{std::tuple{"Hello", 1, 2.9}, std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9), (\"Hello\", 1, 2.9)}");
    }
  }
}

TEST_CASE( "printing multiset of streamable types on wchar_t stream", "[multiset][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty multiset") {
    std::multiset<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"{}");
  }
  SECTION("printing a multiset with some elements") {
    std::multiset v{1, 2, 2, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"{1, 2, 2, 4, 5}");
  }
  SECTION("printing a multiset of strings") {
    std::multiset v{L"hello"s, L"world"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"world\", \"world\"}");
  }
  SECTION("printing a multiset of string_views") {
    std::multiset v{L"hello"sv, L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"hello\", \"world\"}");
  }
  SECTION("printing a multiset of c strings") {
    std::multiset v{L"hello", L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"hello\", \"hello\", \"world\"}");
  }
  SECTION("printing a multiset of char") {
    std::multiset v{L'x', L'y', L'w', L'x'};
    print(v, wos);
    REQUIRE(wos.str() == L"{w, x, x, y}");
  }
  SECTION("printing a multiset of pairs") {
    std::multiset v{std::pair{1, 2}, std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"{(1, 2), (1, 2), (3, 4)}");
  }
  SECTION("printing a multiset of tuples") {
    SECTION("starting with a fundamental type") {
      std::multiset v{std::tuple{1, L"Hello", 2.9}, std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(1, \"Hello\", 2.9), (1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::multiset v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9), (\"Hello\", 1, 2.9)}");
    }
  }
}
