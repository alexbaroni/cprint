#include <string>
#include <sstream>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing string on char stream", "[string][char]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing an empty string") {
    std::string v{};
    print(v, os);
    REQUIRE(os.str() == "\"\"");
  }

  SECTION("printing a string") {
    std::string v{"hello world!"s};
    print(v, os);
    REQUIRE(os.str() == "\"hello world!\"");
  }

  SECTION("printing a string_view") {
    std::string_view v{"hello world!"sv};
    print(v, os);
    REQUIRE(os.str() == "\"hello world!\"");
  }
}

TEST_CASE( "printing string on wchar_t stream", "[string][wchar_t]" )
{
  using namespace std::string_literals;
  using namespace std::string_view_literals;
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing an empty string") {
    std::wstring v{};
    print(v, wos);
    REQUIRE(wos.str() == L"\"\"");
  }

  SECTION("printing a string") {
    std::wstring v{L"hello world!"s};
    print(v, wos);
    REQUIRE(wos.str() == L"\"hello world!\"");
  }

  SECTION("printing a string_view") {
    std::wstring_view v{L"hello world!"sv};
    print(v, wos);
    REQUIRE(wos.str() == L"\"hello world!\"");
  }
}
