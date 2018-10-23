#include <sstream>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing c array of streamable types on char stream", "[array][char]" )
{
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing a c array with one element") {
    int a[] = {0};
    print(a, os);
    REQUIRE(os.str() == "[0]");
  }
  SECTION("printing a c array with some elements") {
    int a[] = {1, 2, 3, 4, 5};
    print(a, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
  SECTION("printing a c array of chars") {
    char a[] = {'h','e','l','l','o', '\0'};
    print(a, os);
    REQUIRE(os.str() == "\"hello\"");
  }
  SECTION("printing a bidimensional c array of chars") {
    char a[2][6]={{'h','e','l','l','o', '\0'}, {'w','o','r','l','d','\0'}};
    print(a, os);
    REQUIRE(os.str() == "[\"hello\", \"world\"]");
  }
  SECTION("printing a bidimensional c array of ints") {
    int a[3][5] = {
        { 71, 72, 73, 74, 75 },
        { 81, 82, 83, 84, 85 },
        { 91, 92, 93, 94, 95 }
    };
    print(a, os);
    REQUIRE(os.str() == "[[71, 72, 73, 74, 75], [81, 82, 83, 84, 85], [91, 92, 93, 94, 95]]");
  }
}

TEST_CASE( "printing c array of streamable types on wchar_t stream", "[array][wchar_t]" )
{
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing a c array with one element") {
    int a[] = {0};
    print(a, wos);
    REQUIRE(wos.str() == L"[0]");
  }
  SECTION("printing a c array with some elements") {
    int a[] = {1, 2, 3, 4, 5};
    print(a, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
  SECTION("printing a c array of wchars") {
    wchar_t a[] = {L'h',L'e',L'l',L'l',L'o',L'\0'};
    print(a, wos);
    REQUIRE(wos.str() == L"\"hello\"");
  }
  SECTION("printing a bidimensional c array of wchars") {
    wchar_t a[2][6]={{L'h',L'e',L'l',L'l',L'o',L'\0'}, {L'w',L'o',L'r',L'l',L'd',L'\0'}};
    print(a, wos);
    REQUIRE(wos.str() == L"[\"hello\", \"world\"]");
  }
  SECTION("printing a bidimensional c array of ints") {
    int a[3][5] = {
        { 71, 72, 73, 74, 75 },
        { 81, 82, 83, 84, 85 },
        { 91, 92, 93, 94, 95 }
    };
    print(a, wos);
    REQUIRE(wos.str() == L"[[71, 72, 73, 74, 75], [81, 82, 83, 84, 85], [91, 92, 93, 94, 95]]");
  }
}