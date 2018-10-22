#include <vector>
#include <sstream>
#include <string>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing vector of vector of streamable types on char stream", "[vector][char]" ) {
  using namespace std::string_literals;
  using namespace cprint;

  std::ostringstream os;

  SECTION("printing an empty vector of vector") {
    std::vector<std::vector<int>> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing a vector of vector with some elements") {
    std::vector<std::vector<int>> v{{1, 2, 3}, {4, 5}};
    print(v, os);
    REQUIRE(os.str() == "[[1, 2, 3], [4, 5]]");
  }
  SECTION("printing a vector of vector of strings") {
    std::vector<std::vector<std::string>> v{{"hello"s, "world"s},{"world"s, "hello"s}};
    print(v, os);
    REQUIRE(os.str() == "[[\"hello\", \"world\"], [\"world\", \"hello\"]]");
  }
  SECTION("printing a vector of vector of c strings") {
    std::vector<std::vector<const char*>> v{{"hello", "world"}, {"world", "hello"}};
    print(v, os);
    REQUIRE(os.str() == "[[\"hello\", \"world\"], [\"world\", \"hello\"]]");
  }
}

TEST_CASE( "printing vector of vector of streamable types on wchar_t stream", "[vector][wchar_t]" ) {
  using namespace std::string_literals;
  using namespace cprint;

  std::wostringstream wos;

  SECTION("printing an empty vector of vector") {
    std::vector<std::vector<int>> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing a vector of vector with some elements") {
    std::vector<std::vector<int>> v{{1, 2, 3}, {4, 5}};
    print(v, wos);
    REQUIRE(wos.str() == L"[[1, 2, 3], [4, 5]]");
  }
  SECTION("printing a vector of vector of strings") {
    std::vector<std::vector<std::wstring>> v{{L"hello"s, L"world"s},{L"world"s, L"hello"s}};
    print(v, wos);
    REQUIRE(wos.str() == L"[[\"hello\", \"world\"], [\"world\", \"hello\"]]");
  }
  SECTION("printing a vector of vector of c strings") {
    std::vector<std::vector<const wchar_t*>> v{{L"hello", L"world"}, {L"world", L"hello"}};
    print(v, wos);
    REQUIRE(wos.str() == L"[[\"hello\", \"world\"], [\"world\", \"hello\"]]");
  }
}

