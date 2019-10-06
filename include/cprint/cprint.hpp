#ifndef CPRINT_HPP
#define CPRINT_HPP

#include <string>
#include <ostream>
#include <string_view>
#include <tuple>
#include <algorithm>
#include <utility>
#include "stl2/concepts.hpp"
#include "stl2/detail/span.hpp"
#include "concepts.hpp"
#include "formatter.hpp"

namespace cprint {
  namespace concepts = std::experimental::ranges;
  template <typename T>
  constexpr auto type_name()
  {
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
  }

//  if constexpr(std::is_same_v<CharT, char>)
//    os << std::endl << "---> " << type_name<decltype(s)>() << std::endl;

  template <typename T,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<T, CharT>>
  requires concepts::StreamInsertable<T, CharT, Traits> && !CString<T> && !Array<T>
  void print(T const& t, std::basic_ostream<CharT, Traits>& os, [[maybe_unused]] Fmt fmt = Fmt{})
  {
    os << t;
  }

  template <CString T,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<T, CharT>>
  void print(T const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    fmt.prefix(os);
    os << t;
    fmt.suffix(os);
  }

  template <CharSpan S,
            Char CharT,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<S, CharT>>
  void print(S s, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    fmt.prefix(os);
    os << s.data();
    fmt.suffix(os);
  }

  template <Char CharT,
            CharTraits Traits = std::char_traits<CharT>,
            typename Allocator = std::allocator<CharT>,
            Formatter<CharT> Fmt = formatter<std::basic_string<CharT, Traits, Allocator>, CharT>>
  void print(std::basic_string<CharT, Traits, Allocator> const& s,
             std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    fmt.prefix(os);
    os << s;
    fmt.suffix(os);
  }

  template<Char CharT,
           CharTraits Traits = std::char_traits<CharT>,
           Formatter<CharT> Fmt = formatter<std::basic_string_view<CharT, Traits>, CharT>>
  void print(std::basic_string_view<CharT, Traits> const& sv,
             std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
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
  void print(std::pair<T1, T2> const& p, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
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
  void print(std::tuple<T...> const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    fmt.prefix(os);
    if constexpr(sizeof...(T) > 0) {
      std::apply([&os, &fmt] (auto x, auto... xs) {
        print(x, os, formatter<decltype(x),CharT>{});
        (..., (fmt.separator(os), print(xs, os, formatter<decltype(xs),CharT>{})));
      }, t);
    }
    fmt.suffix(os);
  }

  template<typename R,
            Char CharT = char,
            CharTraits Traits = std::char_traits<CharT>,
            Formatter<CharT> Fmt = formatter<R, CharT>>
  requires (concepts::InputRange<R> || MultiDimArray<R>) && !CString<R> && !CharSpan<R>
  void print(R const& r, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    using value_type = typename std::iterator_traits<decltype(std::cbegin(r))>::value_type;
    using formatter_type = formatter<value_type, CharT>;

    fmt.prefix(os);
    if (std::cbegin(r) != std::cend(r)) {
      print(*std::cbegin(r), os, formatter_type{});

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
  void print_line(T const& t, std::basic_ostream<CharT, Traits>& os, Fmt fmt = Fmt{})
  {
    print(t, os, fmt);
    os << std::endl;
  }
}
#endif //CPRINT_HPP
