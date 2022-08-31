#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {

template <bool, typename T = void>
class enable_if {};

template <typename T>
class enable_if<true, T> {
  typedef T type;
};
};  // namespace ft

#endif
