#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
namespace ft {
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

  template <class T_, class Container_>
  friend bool operator==(const stack<T_, Container_>& lhs,
                         const stack<T_, Container_>& rhs) throw();
  template <class T_, class Container_>
  friend bool operator<(const stack<T_, Container_>& lhs,
                        const stack<T_, Container_>& rhs) throw();
};

template <class T, class Container>
bool operator==(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return (x.c == y.c);
};

template <class T, class Container>
bool operator<(const stack<T, Container>& x,
               const stack<T, Container>& y) throw() {
  return x.c < y.c;
};

template <class T, class Container>
bool operator!=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(x == y);
};

template <class T, class Container>
bool operator>(const stack<T, Container>& x,
               const stack<T, Container>& y) throw() {
  return (y < x);
};

template <class T, class Container>
bool operator>=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(x < y);
};

template <class T, class Container>
bool operator<=(const stack<T, Container>& x,
                const stack<T, Container>& y) throw() {
  return !(y < x);
};

}  // namespace ft
#endif
