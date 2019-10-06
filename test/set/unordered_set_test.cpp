#include <unordered_set>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing unordered_set of streamable types on char stream", "[unordered_set][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty unordered_set") {
    std::unordered_set<int> v{};
    print(v, os);
    REQUIRE(os.str() == "{}");
  }
  SECTION("printing a unordered_set with some elements") {
    std::unordered_set v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "{5, 4, 3, 2, 1}");
  }
  SECTION("printing a unordered_set of strings") {
    std::unordered_set v{"hello"s, "world"s};
    print(v, os);
    REQUIRE(os.str() == "{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of string_views") {
    std::unordered_set v{"hello"sv, "world"sv};
    print(v, os);
    REQUIRE(os.str() == "{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of c strings") {
    std::unordered_set v{"hello", "world"};
    print(v, os);
    REQUIRE(os.str() == "{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of char") {
    std::unordered_set v{'x', 'y', 'w', 'z'};
    print(v, os);
    REQUIRE(os.str() == "{z, w, y, x}");
  }
  /* Requires hash infrastructure
   SECTION("printing a unordered_set of pairs") {
    std::unordered_set<std::pair<int, int>> v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "{(1, 2), (3, 4)}");
  }
  SECTION("printing a unordered_set of tuples") {
    SECTION("starting with a fundamental type") {
      std::unordered_set v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::unordered_set v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }*/
}

TEST_CASE( "printing unordered_set of streamable types on wchar_t stream", "[unordered_set][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty unordered_set") {
    std::unordered_set<int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"{}");
  }
  SECTION("printing a unordered_set with some elements") {
    std::unordered_set v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"{5, 4, 3, 2, 1}");
  }
  SECTION("printing a unordered_set of strings") {
    std::unordered_set v{L"hello"s, L"world"s};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of string_views") {
    std::unordered_set v{L"hello"sv, L"world"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of c strings") {
    std::unordered_set v{L"hello", L"world"};
    print(v, wos);
    REQUIRE(wos.str() == L"{\"world\", \"hello\"}");
  }
  SECTION("printing a unordered_set of char") {
    std::unordered_set v{L'x', L'y', L'w', L'z'};
    print(v, wos);
    REQUIRE(wos.str() == L"{z, w, y, x}");
  }
  /* Requires hash infrastructure
   SECTION("printing a unordered_set of pairs") {
    std::unordered_set v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"{(1, 2), (3, 4)}");
  }
  SECTION("printing a unordered_set of tuples") {
    SECTION("starting with a fundamental type") {
      std::unordered_set v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::unordered_set v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }*/
}
