#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {

template <bool, typename T = void>
class enable_if {};

template <typename T>
class enable_if<true, T> {
 public:
  typedef T type;
};
};  // namespace ft

#endif
