#ifndef CPRINT_FORMATTER_HPP
#define CPRINT_FORMATTER_HPP

#include <string>
#include <ostream>
#include <string_view>
#include <set>
#include <unordered_set>
#include <tuple>
#include <utility>

namespace cprint {
  template<typename T, typename CharT, typename Traits = std::char_traits<CharT>>
  struct formatter {};

  template<typename T>
  struct formatter<T, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "["; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << "]"; }
  };

  template<std::size_t N>
  struct formatter<char[N], char> {
    void prefix(std::basic_ostream<char>& os) const { os << "\""; }
    void separator(std::basic_ostream<char>&) const {}
    void suffix(std::basic_ostream<char>& os) const { os << "\""; }
  };

  template<>
  struct formatter<const char* const&, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "\""; }
    void separator(std::basic_ostream<char>&) const {}
    void suffix(std::basic_ostream<char>& os) const { os << "\""; }
  };

  template<>
  struct formatter<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "\""; }
    void separator(std::basic_ostream<char>&) const {}
    void suffix(std::basic_ostream<char>& os) const { os << "\""; }
  };

  template<>
  struct formatter<std::basic_string_view<char, std::char_traits<char>>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "\""; }
    void separator(std::basic_ostream<char>&) const {}
    void suffix(std::basic_ostream<char>& os) const { os << "\""; }
  };

  template<typename T1, typename T2>
  struct formatter<std::pair<T1, T2>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "("; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << ")"; }
  };

  template<typename K,
      typename C,
      typename A>
  struct formatter<std::set<K, C, A>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "{"; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << "}"; }
  };

  template<typename K,
      typename C,
      typename A>
  struct formatter<std::multiset<K, C, A>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "{"; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << "}"; }
  };

  template<typename K,
      typename H,
      typename E,
      typename A>
  struct formatter<std::unordered_set<K, H, E, A>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "{"; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << "}"; }
  };

  template<typename K,
      typename H,
      typename E,
      typename A>
  struct formatter<std::unordered_multiset<K, H, E, A>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "{"; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << "}"; }
  };

  template<typename... Ts>
  struct formatter<std::tuple<Ts...>, char> {
    void prefix(std::basic_ostream<char>& os) const { os << "("; }
    void separator(std::basic_ostream<char>& os) const { os << ", "; }
    void suffix(std::basic_ostream<char>& os) const { os << ")"; }
  };

  template<typename T>
  struct formatter<T, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"["; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"]"; }
  };

  template<std::size_t N>
  struct formatter<wchar_t[N], wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
    void separator(std::basic_ostream<wchar_t>&) const {}
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
  };

  template<>
  struct formatter<const wchar_t* const&, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
    void separator(std::basic_ostream<wchar_t>&) const {}
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
  };

  template<>
  struct formatter<std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
    void separator(std::basic_ostream<wchar_t>&) const {}
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
  };

  template<>
  struct formatter<std::basic_string_view<wchar_t, std::char_traits<wchar_t>>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
    void separator(std::basic_ostream<wchar_t>&) const {}
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"\""; }
  };

  template<typename T1, typename T2>
  struct formatter<std::pair<T1, T2>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"("; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L")"; }
  };

  template<typename K,
      typename C,
      typename A>
  struct formatter<std::set<K, C, A>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"{"; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"}"; }
  };

  template<typename K,
      typename C,
      typename A>
  struct formatter<std::multiset<K, C, A>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"{"; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"}"; }
  };

  template<typename K,
      typename H,
      typename E,
      typename A>
  struct formatter<std::unordered_set<K, H, E, A>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"{"; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"}"; }
  };

  template<typename K,
      typename H,
      typename E,
      typename A>
  struct formatter<std::unordered_multiset<K, H, E, A>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"{"; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L"}"; }
  };

  template<typename... Ts>
  struct formatter<std::tuple<Ts...>, wchar_t> {
    void prefix(std::basic_ostream<wchar_t>& os) const { os << L"("; }
    void separator(std::basic_ostream<wchar_t>& os) const { os << L", "; }
    void suffix(std::basic_ostream<wchar_t>& os) const { os << L")"; }
  };
}
#endif //CPRINT_FORMATTER_HPP
