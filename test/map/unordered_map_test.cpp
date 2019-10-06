#include <unordered_map>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing unordered_map of streamable types on char stream", "[unordered_map][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty unordered_map") {
    std::unordered_map<int, int> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing a unordered_map with some elements") {
    std::unordered_map<int, char> v{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    print(v, os);
    REQUIRE(os.str() == "[(5, e), (4, d), (3, c), (2, b), (1, a)]");
  }
  SECTION("printing a unordered_map of strings") {
    std::unordered_map<std::string, int> v{{"hello"s, 1}, {"world"s, 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of string_views") {
    std::unordered_map<std::string_view, int> v{{"hello"sv,1}, {"world"sv, 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of c strings") {
    std::unordered_map<const char*, int> v{{"hello", 1},  {"world", 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of char") {
    std::unordered_map<char, int> v{{'x', 1}, {'y', 2}, {'w', 3}, {'z', 4}};
    print(v, os);
    REQUIRE(os.str() == "[(z, 4), (w, 3), (y, 2), (x, 1)]");
  }
  /* Requires hash infrastructure
   SECTION("printing a unordered_map of pairs") {
    std::unordered_map<std::pair<int, int>> v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, os);
    REQUIRE(os.str() == "{(1, 2), (3, 4)}");
  }
  SECTION("printing a unordered_map of tuples") {
    SECTION("starting with a fundamental type") {
      std::unordered_map v{std::tuple{1, "Hello", 2.9}, std::tuple{3, "world", 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::unordered_map v{std::tuple{"Hello", 1, 2.9}, std::tuple{"world", 3, 4.1}};
      print(v, os);
      REQUIRE(os.str() == "{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }*/
}

TEST_CASE( "printing unordered_map of streamable types on wchar_t stream", "[unordered_map][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty unordered_map") {
    std::unordered_map<int, int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a unordered_map with some elements") {
    std::unordered_map<int, wchar_t> v{{1, L'a'}, {2, L'b'}, {3, L'c'}, {4, L'd'}, {5, L'e'}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(5, e), (4, d), (3, c), (2, b), (1, a)]");
  }
  SECTION("printing a unordered_map of strings") {
    std::unordered_map<std::wstring, int> v{{L"hello"s, 1}, {L"world"s, 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of string_views") {
    std::unordered_map<std::wstring_view, int> v{{L"hello"sv,1}, {L"world"sv, 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of c strings") {
    std::unordered_map<const wchar_t*, int> v{{L"hello", 1},  {L"world", 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"world\", 2), (\"hello\", 1)]");
  }
  SECTION("printing a unordered_map of char") {
    std::unordered_map<wchar_t, int> v{{L'x', 1}, {L'y', 2}, {L'w', 3}, {L'z', 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(z, 4), (w, 3), (y, 2), (x, 1)]");
  }
  /* Requires hash infrastructure
   SECTION("printing a unordered_map of pairs") {
    std::unordered_map v{std::pair{1, 2}, std::pair{3, 4}};
    print(v, wos);
    REQUIRE(wos.str() == L"{(1, 2), (3, 4)}");
  }
  SECTION("printing a unordered_map of tuples") {
    SECTION("starting with a fundamental type") {
      std::unordered_map v{std::tuple{1, L"Hello", 2.9}, std::tuple{3, L"world", 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(1, \"Hello\", 2.9), (3, \"world\", 4.1)}");
    }
    SECTION("not starting with a fundamental type") {
      std::unordered_map v{std::tuple{L"Hello", 1, 2.9}, std::tuple{L"world", 3, 4.1}};
      print(v, wos);
      REQUIRE(wos.str() == L"{(\"world\", 3, 4.1), (\"Hello\", 1, 2.9)}");
    }
  }*/
}
