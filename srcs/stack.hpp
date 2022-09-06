#ifndef STACK_HPP
#define STACK_HPP

//#include <deque>
#include "vector.hpp"
namespace ft {
// template <class T, class Container = std::deque<T> >
template <class T, class Container = vector<T> >
class stack {
 public:
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef Container container_type;

 protected:
  Container c;

 public:
  explicit stack(const Container& other = Container()) { c = other; };
  bool empty() const { return c.empty(); }

  size_type size() { return c.size(); }
  value_type& top() { return c.back(); }
  const value_type& top() const {}
  void push(const value_type& x) { c.push_back(x); }
  void pop() { c.pop_back(); }

  template <class T_, class C_>
  friend bool operator==(const stack<T_, C_>& lhs,
                         const stack<T_, C_>& rhs) throw();
  template <class T_, class C_>
  friend bool operator<(const stack<T_, C_>& lhs,
                        const stack<T_, C_>& rhs) throw();
  template <class T_, class C_>
  friend bool operator==(stack<T_, C_>& lhs, stack<T_, C_>& rhs) throw();
  template <class T_, class C_>
  friend bool operator<(stack<T_, C_>& lhs, stack<T_, C_>& rhs) throw();
};

template <class T, class Container>
bool operator==(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return (x == y);
};
template <class T, class Container>
bool operator==(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return (x == y);
};
template <class T, class Container>
bool operator<(const stack<T, Container>& x,
               const stack<T, Container>& y) throw() {
  return (x < y);
};
template <class T, class Container>
bool operator<(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return (x < y);
};
template <class T, class Container>
bool operator!=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(x == y);
};
template <class T, class Container>
bool operator!=(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return !(x == y);
};
template <class T, class Container>
bool operator>(const stack<T, Container>& x,
               const stack<T, Container>& y) throw() {
  return (y < x);
};
template <class T, class Container>
bool operator>(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return (y < x);
};
template <class T, class Container>
bool operator>=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(x < y);
};
template <class T, class Container>
bool operator>=(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return !(x < y);
};
template <class T, class Container>
bool operator<=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(y < x);
};
template <class T, class Container>
bool operator<=(stack<T, Container>& x, stack<T, Container>& y) throw() {
  return !(y < x);
};
}  // namespace ft
#endif
