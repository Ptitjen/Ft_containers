#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include <iostream>
#include <typeinfo>

namespace ft {
template <class T>
struct is_integral {
  enum { value = false };
};

template <>
struct is_integral<bool> {
  enum { value = true };
};
template <>
struct is_integral<char> {
  enum { value = true };
};
template <>
struct is_integral<wchar_t> {
  enum { value = true };
};
template <>
struct is_integral<short> {
  enum { value = true };
};
template <>
struct is_integral<int> {
  enum { value = true };
};
template <>
struct is_integral<long> {
  enum { value = true };
};
template <>
struct is_integral<long long> {
  enum { value = true };
};
}  // namespace ft
#endif
