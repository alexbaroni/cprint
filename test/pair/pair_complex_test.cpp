#include <array>
#include <vector>
#include <utility>
#include <sstream>
#include "stl2/detail/span.hpp"
#include "catch.hpp"
#include "cprint/cprint.hpp"

TEST_CASE( "printing pair of complex types on char stream", "[pair][char]" )
{
  using namespace cprint;

  std::ostringstream os;
  SECTION("printing a pair with an array") {
    std::pair p { 1, std::array{1,2,3,4} };
    print(p, os);
    REQUIRE(os.str() == "(1, [1, 2, 3, 4])");
  }
  SECTION("printing a pair with a vector") {
    std::pair p { 1, std::vector{1,2,3,4} };
    print(p, os);
    REQUIRE(os.str() == "(1, [1, 2, 3, 4])");
  }
}

TEST_CASE( "printing pair of complex types on wchar_t stream", "[pair][wchar_t]" )
{
  using namespace cprint;

  std::wostringstream wos;
  SECTION("printing a pair with an array") {
    std::pair p { 1, std::array{1,2,3,4} };
    print(p, wos);
    REQUIRE(wos.str() == L"(1, [1, 2, 3, 4])");
  }
  SECTION("printing a pair with a vector") {
    std::pair p { 1, std::vector{1,2,3,4} };
    print(p, wos);
    REQUIRE(wos.str() == L"(1, [1, 2, 3, 4])");
  }
}
