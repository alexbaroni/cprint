#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <tuple>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing map of streamable types on char stream", "[map][char]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty map") {
    std::map<int, int> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing a map with some elements") {
    std::map<int, char> v{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    print(v, os);
    REQUIRE(os.str() == "[(1, a), (2, b), (3, c), (4, d), (5, e)]");
  }
  SECTION("printing a map of string values") {
    std::map<int, std::string> v{{1, "hello"s},  {2, "world"s}};
    print(v, os);
    REQUIRE(os.str() == "[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of string keys") {
    std::map<std::string, int> v{{"hello"s, 1},  {"world"s, 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of string_view values") {
    std::map<int, std::string_view> v{{1, "hello"sv}, {2, "world"sv}};
    print(v, os);
    REQUIRE(os.str() == "[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of string_view keys") {
    std::map<std::string_view, int> v{{"hello"sv, 1}, {"world"sv, 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of c string keys") {
    std::map<const char*, int> v{{"hello", 1}, {"world", 2}};
    print(v, os);
    REQUIRE(os.str() == "[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of c string values") {
    std::map<int, const char*> v{{1, "hello"}, {2, "world"}};
    print(v, os);
    REQUIRE(os.str() == "[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of char keys") {
    std::map<char, int> v{{'x', 1}, {'y', 2}, {'w', 3}, {'z', 3}};
    print(v, os);
    REQUIRE(os.str() == "[(w, 3), (x, 1), (y, 2), (z, 3)]");
  }
  SECTION("printing a map of char values") {
    std::map<int, char> v{{1, 'x'}, {2, 'y'}, {3, 'w'}, {4, 'z'}};
    print(v, os);
    REQUIRE(os.str() == "[(1, x), (2, y), (3, w), (4, z)]");
  }
  SECTION("printing a map of pair values") {
    std::map<int, std::pair<int, int>> v{{1, std::pair{1, 2}}, {2, std::pair{3, 4}}};
    print(v, os);
    REQUIRE(os.str() == "[(1, (1, 2)), (2, (3, 4))]");
  }
  SECTION("printing a map of pair keys") {
    std::map<std::pair<int, int>, int> v{{std::pair{1, 2}, 1}, {std::pair{3, 4}, 2}};
    print(v, os);
    REQUIRE(os.str() == "[((1, 2), 1), ((3, 4), 2)]");
  }
  SECTION("printing a map of tuple values") {
    SECTION("starting with a fundamental type") {
      std::map<int, std::tuple<int, const char*, double>>
        v{{1, std::tuple{1, "Hello", 2.9}}, {2, std::tuple{3, "world", 4.1}}};
      print(v, os);
      REQUIRE(os.str() == "[(1, (1, \"Hello\", 2.9)), (2, (3, \"world\", 4.1))]");
    }
    SECTION("not starting with a fundamental type") {
      std::map<int, std::tuple<const char*, int, double>>
        v{{1, std::tuple{"Hello", 1, 2.9}}, {2, std::tuple{"world", 3, 4.1}}};
      print(v, os);
      REQUIRE(os.str() == "[(1, (\"Hello\", 1, 2.9)), (2, (\"world\", 3, 4.1))]");
    }
  }
  SECTION("printing a map of tuple keys") {
    SECTION("starting with a fundamental type") {
      std::map<std::tuple<int, const char*, double>, int>
          v{{std::tuple{1, "Hello", 2.9}, 1}, {std::tuple{3, "world", 4.1}, 2}};
      print(v, os);
      REQUIRE(os.str() == "[((1, \"Hello\", 2.9), 1), ((3, \"world\", 4.1), 2)]");
    }
    SECTION("not starting with a fundamental type") {
      std::map<std::tuple<const char*, int, double>, int>
          v{{std::tuple{"Hello", 1, 2.9}, 1}, {std::tuple{"world", 3, 4.1}, 2}};
      print(v, os);
      REQUIRE(os.str() == "[((\"world\", 3, 4.1), 2), ((\"Hello\", 1, 2.9), 1)]");
    }
  }
}

TEST_CASE( "printing map of streamable types on wchar_t stream", "[map][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty map") {
    std::map<int, int> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a map with some elements") {
    std::map<int, wchar_t> v{{1, L'a'}, {2, L'b'}, {3, L'c'}, {4, L'd'}, {5, L'e'}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, a), (2, b), (3, c), (4, d), (5, e)]");
  }
  SECTION("printing a map of string value") {
    std::map<int, std::wstring> v{{1, L"hello"s},  {2, L"world"s}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of string keys") {
    std::map<std::wstring, int> v{{L"hello"s, 1},  {L"world"s, 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of string_view values") {
    std::map<int, std::wstring_view> v{{1, L"hello"sv}, {2, L"world"sv}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of string_view keys") {
    std::map<std::wstring_view, int> v{{L"hello"sv, 1}, {L"world"sv, 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of c string keys") {
    std::map<const wchar_t*, int> v{{L"hello", 1}, {L"world", 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(\"hello\", 1), (\"world\", 2)]");
  }
  SECTION("printing a map of c string values") {
    std::map<int, const wchar_t*> v{{1, L"hello"}, {2, L"world"}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, \"hello\"), (2, \"world\")]");
  }
  SECTION("printing a map of wchar_t keys") {
    std::map<wchar_t, int> v{{L'x', 1}, {L'y', 2}, {L'w', 3}, {L'z', 3}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(w, 3), (x, 1), (y, 2), (z, 3)]");
  }
  SECTION("printing a map of wchar_t values") {
    std::map<int, wchar_t> v{{1, L'x'}, {2, L'y'}, {3, L'w'}, {4, L'z'}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, x), (2, y), (3, w), (4, z)]");
  }
  SECTION("printing a map of pair values") {
    std::map<int, std::pair<int, int>> v{{1, std::pair{1, 2}}, {2, std::pair{3, 4}}};
    print(v, wos);
    REQUIRE(wos.str() == L"[(1, (1, 2)), (2, (3, 4))]");
  }
  SECTION("printing a map of pair keys") {
    std::map<std::pair<int, int>, int> v{{std::pair{1, 2}, 1}, {std::pair{3, 4}, 2}};
    print(v, wos);
    REQUIRE(wos.str() == L"[((1, 2), 1), ((3, 4), 2)]");
  }
  SECTION("printing a map of tuple values") {
    SECTION("starting with a fundamental type") {
      std::map<int, std::tuple<int, const wchar_t*, double>>
          v{{1, std::tuple{1, L"Hello", 2.9}}, {2, std::tuple{3, L"world", 4.1}}};
      print(v, wos);
      REQUIRE(wos.str() == L"[(1, (1, \"Hello\", 2.9)), (2, (3, \"world\", 4.1))]");
    }
    SECTION("not starting with a fundamental type") {
      std::map<int, std::tuple<const wchar_t*, int, double>>
          v{{1, std::tuple{L"Hello", 1, 2.9}}, {2, std::tuple{L"world", 3, 4.1}}};
      print(v, wos);
      REQUIRE(wos.str() == L"[(1, (\"Hello\", 1, 2.9)), (2, (\"world\", 3, 4.1))]");
    }
  }
  SECTION("printing a map of tuple keys") {
    SECTION("starting with a fundamental type") {
      std::map<std::tuple<int, const wchar_t*, double>, int>
          v{{std::tuple{1, L"Hello", 2.9}, 1}, {std::tuple{3, L"world", 4.1}, 2}};
      print(v, wos);
      REQUIRE(wos.str() == L"[((1, \"Hello\", 2.9), 1), ((3, \"world\", 4.1), 2)]");
    }
    SECTION("not starting with a fundamental type") {
      std::map<std::tuple<const wchar_t*, int, double>, int>
          v{{std::tuple{L"Hello", 1, 2.9}, 1}, {std::tuple{L"world", 3, 4.1}, 2}};
      print(v, wos);
      REQUIRE(wos.str() == L"[((\"world\", 3, 4.1), 2), ((\"Hello\", 1, 2.9), 1)]");
    }
  }
}
