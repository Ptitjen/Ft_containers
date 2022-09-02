#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft {
/* ***************** reverse operator **************** */

template <class Iterator>
class reverse_iterator {
 public:
  typedef Iterator iterator_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::pointer pointer;
  reverse_iterator() : current(NULL){};  //??
  explicit reverse_iterator(Iterator x) : current(x){};

  template <class U>
  reverse_iterator(const reverse_iterator<U> &u) : current(u.current){};
  reverse_iterator &operator=(reverse_iterator const &it) {  // PB?
    if (&it == this) return (*this);
    ptr_(it.ptr_);
    return (*this);
  };

  Iterator base() const {
    Iterator it;
    it = current + 1;
    return it;
  };  // verify - returns pointer to adjacent (next)element

  reference operator*() { return *current; };
  pointer operator->() { return current; };

  reverse_iterator &operator++() {
    current--;
    return *this;
  };

  reverse_iterator operator++(int) {
    reverse_iterator it = *this;
    current--;
    return it;
  };

  reverse_iterator &operator--() {
    current++;
    return *this;
  };

  reverse_iterator operator--(int) {
    reverse_iterator it = *this;
    current++;
    return it;
  };

  reverse_iterator operator+(difference_type n) const {
    reverse_iterator it = *this;
    it.current = current - n;
    return it;
  };

  reverse_iterator &operator+=(difference_type n) {
    current -= n;
    return *this;
  };

  reverse_iterator operator-(difference_type n) const {
    reverse_iterator it = *this;
    it.current = current + n;
    return it;
  };

  reverse_iterator &operator-=(difference_type n) {
    current += n;
    return *this;
  };

  reference operator[](difference_type n) const { return current - n; };  //???

  bool operator==(const reverse_iterator &rhs) {
    return current == rhs.current;
  }
  bool operator!=(const reverse_iterator &rhs) {
    return current != rhs.current;
  }
  bool operator<(const reverse_iterator &rhs) { return current > rhs.current; }
  bool operator>(const reverse_iterator &rhs) { return current < rhs.current; }
  bool operator<=(const reverse_iterator &rhs) {
    return current >= rhs.current;
  }
  bool operator>=(const reverse_iterator &rhs) {
    return current <= rhs.current;
  }

 protected:
  Iterator current;
};

/* ***************** const reverse operator **************** */
template <class Iterator>
class const_reverse_iterator {
  typedef Iterator iterator_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::pointer pointer;
  const_reverse_iterator() : current(NULL){};  //??
  explicit const_reverse_iterator(Iterator x) : current(x){};

  template <class U>
  const_reverse_iterator(const reverse_iterator<U> &u) : current(u.current){};
  const_reverse_iterator &operator=(const_reverse_iterator const &it) {  // PB?
    if (&it == this) return (*this);
    ptr_(it.ptr_);
    return (*this);
  };

  Iterator base() const {
    Iterator it;
    it = current + 1;  // access to next element??
    return it;
  };  // verify - returns pointer to adjacent (next)element

  reference operator*() { return *current; };
  pointer operator->() { return current; };

  const_reverse_iterator &operator++() {
    current--;
    return *this;
  };

  const_reverse_iterator operator++(int) {
    const_reverse_iterator it = *this;
    current--;
    return it;
  };

  const_reverse_iterator &operator--() {
    current++;
    return *this;
  };

  const_reverse_iterator operator--(int) {
    const_reverse_iterator it = *this;
    current++;
    return it;
  };

  const_reverse_iterator operator+(difference_type n) const {
    const_reverse_iterator it = *this;
    it.current = current - n;
    return it;
  };

  const_reverse_iterator &operator+=(difference_type n) {
    current -= n;
    return *this;
  };

  const_reverse_iterator operator-(difference_type n) const {
    const_reverse_iterator it = *this;
    it.current = current + n;
    return it;
  };

  const_reverse_iterator &operator-=(difference_type n) {
    current += n;
    return *this;
  };

  reference operator[](difference_type n) const { return current - n; };  //???

  bool operator==(const const_reverse_iterator &rhs) {
    return current == rhs.current;
  }
  bool operator!=(const const_reverse_iterator &rhs) {
    return current != rhs.current;
  }
  bool operator<(const const_reverse_iterator &rhs) {
    return current > rhs.current;
  }
  bool operator>(const const_reverse_iterator &rhs) {
    return current < rhs.current;
  }
  bool operator<=(const const_reverse_iterator &rhs) {
    return current >= rhs.current;
  }
  bool operator>=(const const_reverse_iterator &rhs) {
    return current <= rhs.current;
  }

 protected:
  Iterator current;
};
}  // namespace ft
#endif
/// https://cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator