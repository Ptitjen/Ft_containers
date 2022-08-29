#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft {
/* ***************** reverse operator **************** */

template <class Iterator> class reverse_iterator {
protected:
  Iterator current;

public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::reference reference;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  reverse_iterator() : current(NULL){}; //??
  explicit reverse_iterator(Iterator x) : current(x){};

  template <class U> reverse_iterator(const reverse_iterator<U> &u); //??

  Iterator base() const {
    Iterator it;
    it = current + 1; // access to next element??
    return it;
  }; // verify - returns pointer to adjacent (next)element

  reference operator*() const { return *current; };

  pointer operator->() const { return current; };

  reverse_iterator &operator++() {
    current++;
    return *this;
  };

  reverse_iterator operator++(int i) {
    Iterator it = *this;
    current++;
    return it;
  };

  reverse_iterator &operator--() {
    current--;
    return *this;
  };

  reverse_iterator operator--(int i) {
    Iterator it = *this;
    current--;
    return it;
  };

  reverse_iterator operator+(difference_type n) const {
    Iterator it = *this;
    it.ptr_ = current + n;
    return it;
  };

  reverse_iterator &operator+=(difference_type n) {
    current += n;
    return *this;
  };

  reverse_iterator operator-(difference_type n) const {
    Iterator it = *this;
    it.ptr_ = current - n;
    return it;
  };

  reverse_iterator &operator-=(difference_type n) {
    current -= n;
    return *this;
  };

  reference operator[](difference_type n) const; //???
};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator> &x,
                const reverse_iterator<Iterator> &y) {
  return x.current == y.current;
};

template <class Iterator>
bool operator<(const reverse_iterator<Iterator> &x,
               const reverse_iterator<Iterator> &y) {
  return x.current < y.current;
}; // TODO :verify if inversion or not

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator> &x,
                const reverse_iterator<Iterator> &y) {
  return x.current != y.current;
};

template <class Iterator>
bool operator>(const reverse_iterator<Iterator> &x,
               const reverse_iterator<Iterator> &y) {
  return x.current > y.current;
};

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator> &x,
                const reverse_iterator<Iterator> &y) {
  return x.current >= y.current;
};

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator> &x,
                const reverse_iterator<Iterator> &y) {
  return x.current <= y.current;
};

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type
operator-(const reverse_iterator<Iterator> &x,
          const reverse_iterator<Iterator> &y) {
  return x.current - y.current;
};

template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
          const reverse_iterator<Iterator> &x) {
  return x.current + n;
};

/* ***************** const reverse operator **************** */
template <class Iterator> class const_reverse_iterator {
protected:
  Iterator current;

public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::reference reference;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  const_reverse_iterator() : current(NULL){}; //??
  explicit const_reverse_iterator(Iterator x) : current(x){};

  template <class U> const_reverse_iterator(const reverse_iterator<U> &u); //??

  Iterator base() const {
    Iterator it;
    it = current + 1; // access to next element??
    return it;
  }; // verify - returns pointer to adjacent (next)element

  reference operator*() const { return *current; };

  pointer operator->() const { return current; };

  const_reverse_iterator &operator++() {
    current++;
    return *this;
  };

  const_reverse_iterator operator++(int i) {
    Iterator it = *this;
    current++;
    return it;
  };

  const_reverse_iterator &operator--() {
    current--;
    return *this;
  };

  const_reverse_iterator operator--(int i) {
    Iterator it = *this;
    current--;
    return it;
  };

  const_reverse_iterator operator+(difference_type n) const {
    Iterator it = *this;
    it.ptr_ = current + n;
    return it;
  };

  const_reverse_iterator &operator+=(difference_type n) {
    current += n;
    return *this;
  };

  const_reverse_iterator operator-(difference_type n) const {
    Iterator it = *this;
    it.ptr_ = current - n;
    return it;
  };

  const_reverse_iterator &operator-=(difference_type n) {
    current -= n;
    return *this;
  };

  reference operator[](difference_type n) const; //???
};

template <class Iterator>
bool operator==(const const_reverse_iterator<Iterator> &x,
                const const_reverse_iterator<Iterator> &y) {
  return x.current == y.current;
};

template <class Iterator>
bool operator<(const const_reverse_iterator<Iterator> &x,
               const const_reverse_iterator<Iterator> &y) {
  return x.current < y.current;
}; // TODO :verify if inversion or not

template <class Iterator>
bool operator!=(const const_reverse_iterator<Iterator> &x,
                const const_reverse_iterator<Iterator> &y) {
  return x.current != y.current;
};

template <class Iterator>
bool operator>(const const_reverse_iterator<Iterator> &x,
               const const_reverse_iterator<Iterator> &y) {
  return x.current > y.current;
};

template <class Iterator>
bool operator>=(const const_reverse_iterator<Iterator> &x,
                const const_reverse_iterator<Iterator> &y) {
  return x.current >= y.current;
};

template <class Iterator>
bool operator<=(const const_reverse_iterator<Iterator> &x,
                const const_reverse_iterator<Iterator> &y) {
  return x.current <= y.current;
};

template <class Iterator>
typename const_reverse_iterator<Iterator>::difference_type
operator-(const const_reverse_iterator<Iterator> &x,
          const const_reverse_iterator<Iterator> &y) {
  return x.current - y.current;
};

template <class Iterator>
const_reverse_iterator<Iterator>
operator+(typename const_reverse_iterator<Iterator>::difference_type n,
          const const_reverse_iterator<Iterator> &x) {
  return x.current + n;
};
} // namespace ft
#endif
/// https://cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator