#ifndef CPRINT_HPP
#define CPRINT_HPP

#include <string>
#include <ostream>
#include <string_view>
#include <tuple>
#include <algorithm>
#include <utility>
#include "stl2/concepts.hpp"
#include "concepts.hpp"
#include "formatter.hpp"

#include <iostream>

namespace cprint {
  namespace concepts = std::experimental::ranges;
  template <class T>
  constexpr
  std::string_view
  type_name()
  {
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
  }

  template <typename T,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<T, CharT>>
  requires concepts::StreamInsertable<T, CharT, Traits> && !CString<T> && !Array<T>
  void print(T const& t, std::basic_ostream<CharT, Traits>& os, [[maybe_unused]] Fmt fmt = formatter<T, CharT>{})
  {
    os << t;
  }

  template <CString T,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<T, CharT>>
  void print(T const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = formatter<T, CharT>{})
  {
    fmt.prefix(os);
    os << t;
    fmt.suffix(os);
  }

  template <Char CharT,
            CharTraits Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>,
            Formatter<CharT> Fmt = formatter<std::basic_string<CharT, Traits, Allocator>, CharT>>
  void print(std::basic_string<CharT, Traits, Allocator> const& s, std::basic_ostream<CharT, Traits>& os,
             Fmt fmt = formatter<std::basic_string<CharT, Traits, Allocator>, CharT>{})
  {
    fmt.prefix(os);
    os << s;
    fmt.suffix(os);
  }

  template<Char CharT,
           CharTraits Traits = std::char_traits<CharT>,
           Formatter<CharT> Fmt = formatter<std::basic_string_view<CharT, Traits>, CharT>>
  void print(std::basic_string_view<CharT, Traits> const& sv, std::basic_ostream<CharT, Traits>& os,
             Fmt fmt = formatter<std::basic_string_view<CharT, Traits>, CharT>{})
  {
    fmt.prefix(os);
    os << sv;
    fmt.suffix(os);
  }

  template <typename T1,
            typename T2,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<std::pair<T1, T2>, CharT>>
  void print(std::pair<T1, T2> const& p, std::basic_ostream<CharT, Traits>& os, Fmt fmt = formatter<std::pair<T1, T2>, CharT>{})
  {
    fmt.prefix(os);
    print(p.first, os, formatter<T1, CharT>{});
    fmt.separator(os);
    print(p.second, os, formatter<T2, CharT>{});
    fmt.suffix(os);
  }

  template <typename... T,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<std::tuple<T...>, CharT>>
  void print(std::tuple<T...> const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = formatter<std::tuple<T...>, CharT>{})
  {
    fmt.prefix(os);
    if constexpr(sizeof...(T) > 0) {
      print(std::get<0>(t), os, formatter<decltype(std::get<0>(t)),CharT>{});
      std::apply([&os, &fmt] (auto&, auto& ...x) {
        (..., (fmt.separator(os), print(x, os, formatter<decltype(x),CharT>{})));
      }, t);
    }
    fmt.suffix(os);
  }

  template<typename R,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<R, CharT>>
  requires (concepts::InputRange<R> || MultiDimArray<R>) && !CString<R>
  void print(R const& r, std::basic_ostream<CharT, Traits>& os, Fmt fmt = formatter<R, CharT>{})
  {
    using value_type = typename std::iterator_traits<decltype(std::cbegin(r))>::value_type;
    using formatter_type = formatter<value_type, CharT>;

    fmt.prefix(os);
    if (std::cbegin(r) != std::cend(r)) {
      print(*std::cbegin(r), os, formatter_type {});

      std::for_each(std::next(std::cbegin(r)), std::cend(r),
        [&r, &os, &fmt](auto const& e) {
          fmt.separator(os);
          print(e, os, formatter_type {});
        });
    }
    fmt.suffix(os);
  }

  template<typename T,
           Char CharT = char,
           CharTraits Traits = std::char_traits<CharT>,
           Formatter<CharT> Fmt = formatter<T, CharT>>
  void print_line(T const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = formatter<T, CharT>{})
  {
    print(t, os, fmt);
    os << std::endl;
  }
}
#endif //CPRINT_HPP
