#ifndef CPRINT_CONCEPTS_HPP
#define CPRINT_CONCEPTS_HPP

#include <type_traits>
#include "stl2/concepts.hpp"

namespace cprint{
  namespace concepts = std::experimental::ranges;

  template<typename T>
  concept bool Char =
    std::disjunction_v<
      std::is_same<T, char>,
      std::is_same<T, wchar_t>,
      std::is_same<T, const char>,
      std::is_same<T, const wchar_t>
    >;

  template<typename T>
  concept bool CharTraits =
    requires(typename T::char_type& a, typename T::char_type& b) {
      typename T::char_type;
      typename T::int_type;
      typename T::off_type;
      typename T::pos_type;
      typename T::state_type;
      { T::assign(a, b) } -> void;
      { T::eq(a, b) } -> bool;
      { T::lt(a, b) } -> bool;
      // ... to be continued
      { T::eof() } ->  typename T::int_type;
    };

  template <typename T>
  concept bool Array = std::is_array_v<T>;

  template <typename T>
  concept bool MonoDimArray = Array<T> && std::rank_v<T> == 1;

  template <typename T>
  concept bool MultiDimArray = Array<T> && std::rank_v<T> != 1;

  template <typename T>
  concept bool CString =
    (MonoDimArray<T> && Char<std::remove_all_extents_t<T>>) ||
      (std::is_pointer_v<T> && Char<std::remove_cv_t<std::remove_pointer_t<T>>>);

  template <typename F,
            typename CharT,
            typename Traits = std::char_traits<CharT>>
  concept bool Formatter =
    requires(F f, std::basic_ostream<CharT, Traits>& os) {
      { f.prefix(os) } -> void;
      { f.separator(os) } -> void;
      { f.suffix(os) } -> void;
    };
}
#endif //CPRINT_CONCEPTS_HPP
