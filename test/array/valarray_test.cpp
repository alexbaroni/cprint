#include <valarray>
#include <sstream>
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing valarray of streamable types on char stream", "[array][char]" )
{
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing an empty valarray") {
    std::array<int, 0> v{};
    print(v, os);
    REQUIRE(os.str() == "[]");
  }
  SECTION("printing an valarray with some int elements") {
    std::array v{1, 2, 3, 4, 5};
    print(v, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
  SECTION("printing an valarray with some float elements") {
    std::array v{1.0, 2.0, 3.0, 4.0, 5.0};
    print(v, os);
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
  }
}

TEST_CASE( "printing valarray of streamable types on wchar_t stream", "[array][wchar_t]" )
{
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing an empty valarray") {
    std::array<int, 0> v{};
    print(v, wos);
    REQUIRE(wos.str() == L"[]");
  }
  SECTION("printing an valarray with some int elements") {
    std::array v{1, 2, 3, 4, 5};
    print(v, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
  SECTION("printing an valarray with some float elements") {
    std::array v{1.0, 2.0, 3.0, 4.0, 5.0};
    print(v, wos);
    REQUIRE(wos.str() == L"[1, 2, 3, 4, 5]");
  }
}