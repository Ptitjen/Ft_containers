#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib>
#include <exception>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <stdexcept>

#include "../functions/enable_if.hpp"
#include "../functions/equal.hpp"
#include "../functions/is_integral.hpp"
#include "../functions/lexicographical_compare.hpp"
#include "../functions/reverse_iterator.hpp"

namespace ft {

/* ******************** class vector ********************* */

template <class T, class Allocator = std::allocator<T> >
class vector {
  /* ***************** vector iterator ***************** */
  class iterator {
   public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef long long unsigned difference_type;

    /* Constructors and destructor */
    iterator() throw() : ptr_(NULL){};
    iterator(pointer ptr) throw() : ptr_(ptr) {}
    iterator(iterator const& it) throw() : ptr_(it.ptr_){};
    iterator& operator=(iterator const& it) {
      if (&it == this) return (*this);
      ptr_ = it.ptr_;
      return (*this);
    };
    ~iterator() throw(){};

    /* incrementation and decrementation */
    iterator& operator++() {
      ptr_++;
      return *this;
    }
    iterator operator++(int) {
      iterator it = *this;
      ptr_++;
      return it;
    }

    iterator& operator--() {
      ptr_--;
      return *this;
    }
    iterator operator--(int) {
      iterator it = *this;
      ptr_--;
      return it;
    }

    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

    iterator operator+(difference_type n) const {
      iterator it = *this;
      it.ptr_ = ptr_ + n;
      return it;
    };
    iterator operator+(iterator it) const {
      iterator itcpy = *this;
      itcpy.ptr_ = ptr_ + it.ptr_;
      return itcpy;
    };
    iterator operator-(difference_type n) const {
      iterator it = *this;
      it.ptr_ = ptr_ - n;
      return it;
    };
    difference_type operator-(iterator it) const { return ptr_ - it.ptr_; };

    iterator& operator+=(difference_type n) {
      ptr_ += n;
      return *this;
    };
    iterator& operator-=(difference_type n) {
      ptr_ -= n;
      return *this;
    };

    reference operator[](difference_type n) const { return ptr_ + n; };

    /* comparison */
    bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }

    bool operator<(const iterator& rhs) { return ptr_ < rhs.ptr_; }
    bool operator>(const iterator& rhs) { return ptr_ > rhs.ptr_; }

    bool operator<=(const iterator& rhs) { return ptr_ <= rhs.ptr_; }
    bool operator>=(const iterator& rhs) { return ptr_ >= rhs.ptr_; }

    pointer ptr_;
  };

  /* **************** const iterator *************** */

  class const_iterator {
   public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef long long unsigned difference_type;

    /* Constructors and destructor */
    const_iterator() throw() : ptr_(NULL){};
    const_iterator(pointer ptr) throw() : ptr_(ptr) {}
    const_iterator(iterator const& it) throw() : ptr_(it.ptr_){};

    const_iterator(const_iterator const& it) throw() : ptr_(it.ptr_){};
    const_iterator& operator=(const_iterator const& it) throw() {
      if (&it == this) return (*this);
      ptr_ = it.ptr_;
      return (*this);
    };
    ~const_iterator() throw(){};

    /* incrementation and decrementation */
    const_iterator& operator++() {
      ptr_++;
      return *this;
    }
    const_iterator operator++(int) {
      iterator it = *this;
      ptr_++;
      return it;
    }

    const_iterator& operator--() {
      ptr_--;
      return *this;
    }
    const_iterator operator--(int) {
      const_iterator it = *this;
      ptr_--;
      return it;
    }

    /* deref */
    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }

    /* add and substract */
    const_iterator operator+(difference_type n) const {
      iterator it = *this;
      it.ptr_ = ptr_ + n;
      return it;
    };
    const_iterator operator+(const_iterator it) const {
      iterator itcpy = *this;
      itcpy.ptr_ = ptr_ + it.ptr_;
      return itcpy;
    };
    const_iterator operator-(difference_type n) const {
      iterator it = *this;
      it.ptr_ = ptr_ - n;
      return it;
    };
    difference_type operator-(const_iterator it) const {
      return ptr_ - it.ptr_;
    };

    const_iterator& operator+=(difference_type n) {
      ptr_ += n;
      return *this;
    };
    const_iterator& operator-=(difference_type n) {
      ptr_ -= n;
      return *this;
    };

    /* ref */
    reference operator[](difference_type n) const { return ptr_ + n; };

    /* comparison */
    bool operator==(const const_iterator& rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const const_iterator& rhs) { return ptr_ != rhs.ptr_; }

    bool operator<(const const_iterator& rhs) { return ptr_ < rhs.ptr_; }
    bool operator>(const const_iterator& rhs) { return ptr_ > rhs.ptr_; }

    bool operator<=(const const_iterator& rhs) { return ptr_ <= rhs.ptr_; }
    bool operator>=(const const_iterator& rhs) { return ptr_ >= rhs.ptr_; }

    pointer ptr_;
  };

 public:
  /************ TYPEDEFS ************/
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef long long unsigned int size_type;
  typedef long long unsigned int difference_type;
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;

  /************ CONSTRUCTORS AND DESTRUCTOR ************/
  explicit vector(allocator_type const& alloc = Allocator()) {
    try {
      a = alloc;
      _size = 0;
      _capacity = 0;
      _max_size = std::numeric_limits<long long unsigned>::max();
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  explicit vector(size_type n, const T& value = T(),
                  const Allocator& alloc = Allocator()) {
    if (n > std::numeric_limits<long long unsigned>::max())
      throw(std::length_error(""));
    try {
      a = alloc;
      if (n != 0) {
        _array = a.allocate(n);
        std::uninitialized_fill(_array, _array + n, value);
      }
      _size = n;
      _capacity = n;
      _max_size = std::numeric_limits<long long unsigned>::max();
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  template <typename InputIterator>
  vector(InputIterator first,
         typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                InputIterator>::type last,
         const Allocator& alloc = Allocator()) {
    size_type to_insert = last - first;
    if (to_insert > std::numeric_limits<long long unsigned>::max())
      throw(std::length_error(""));
    try {
      a = alloc;
      if (to_insert != 0) {
        _array = a.allocate(to_insert);
        std::uninitialized_copy(first, last, _array);
      }
      _size = to_insert;
      _capacity = to_insert;
      _max_size = std::numeric_limits<long long unsigned>::max();
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  vector(const vector<T, Allocator>& x) {
    try {
      _max_size = x._max_size;
      _size = x._size;
      _capacity = x._capacity;
      if (_capacity != 0) _array = a.allocate(_capacity);
      if (x._size != 0) std::uninitialized_copy(x.begin(), x.end(), _array);
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  ~vector() throw() {
    if (_capacity != 0) {
      for (size_type i = 0; i < _capacity; i++) a.destroy(_array + i);
      a.deallocate(_array, _capacity);
    }
  };

  vector<T, Allocator>& operator=(const vector<T, Allocator>& x) {
    if (&x == this) return (*this);
    try {
      _max_size = x._max_size;
      _size = x._size;
      _capacity = x._capacity;
      _array = a.allocate(_capacity);
      std::uninitialized_copy(x.begin(), x.end(), _array);
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
    return (*this);
  };

  template <class InputIterator>
  void assign(InputIterator first,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type last) {
    try {
      clear();
      reserve(last - first);
      std::uninitialized_copy(first, last, _array);
      _size = last - first;
    } catch (std::exception& e) {
      throw e;
    }
  };

  void assign(size_type n, const T& u) {
    try {
      clear();
      reserve(n);
      std::uninitialized_fill(_array, _array + n, u);
      _size = n;
    } catch (std::exception& e) {
      throw e;
    }
  };

  allocator_type get_allocator() const throw() { return a; };

  /**************** ITERATOR OPERATORS *****************/

  iterator begin() throw() { return _array; };

  const_iterator begin() const throw() { return _array; };

  iterator end() throw() { return _array + _size; };

  const_iterator end() const throw() { return _array + _size; };

  /**************** REVERSE ITERATOR OPERATORS *****************/
  // return directement reverseop
  reverse_iterator rbegin() throw() {
    return reverse_iterator(_array + _size - 1);
  };

  const_reverse_iterator rbegin() const throw() {
    return const_reverse_iterator(_array + _size - 1);
  };

  reverse_iterator rend() throw() { return reverse_iterator(_array - 1); };

  const_reverse_iterator rend() const throw() {
    return const_reverse_iterator(_array - 1);
  };

  /**************** CAPACITY *****************/
  size_type size() const throw() { return _size; };
  size_type max_size() const throw() { return _max_size; };

  void resize(size_type n, T c = T()) {
    ft::vector<T> save(*this);
    try {
      if (n < _size) {
        for (size_type i = n; i < _size; i++) a.destroy(_array + i);
        _size = n;
        return;
      }
      if (n > _capacity) {
        realloc(n);
        std::uninitialized_fill(_array + _size, _array + n, c);
        _size = n;
      }
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  size_type capacity() const throw() { return _capacity; };
  bool empty() const throw() { return _size == 0; };

  void reserve(size_type n) {
    if (n > _max_size) throw std::length_error("");
    if (n > _capacity) {
      try {
        realloc(n);
      } catch (std::exception& e) {
        throw e;
      }
    }
  };

  /**************** ACCESS *****************/

  reference operator[](size_type n) throw() { return *(_array + n); };
  const_reference operator[](size_type n) const throw() {
    return *(_array + n);
  };
  const_reference at(size_type n) const {
    if (n < _size) {
      ft::vector<T> save(*this);
      try {
        return (_array[n]);
      } catch (std::exception& e) {
        swap(save);
        throw e;
      }
    }
    throw std::out_of_range("");
  };

  reference at(size_type n) {
    if (n < _size) {
      ft::vector<T> save(*this);
      try {
        return _array[n];
      } catch (std::exception& e) {
        swap(save);
        throw e;
      }
    }
    throw std::out_of_range("");
  };
  reference front() throw() { return *_array; };
  const_reference front() const throw() { return *_array; };
  reference back() throw() { return *(_array + _size - 1); };
  const_reference back() const throw() { return *(_array + _size - 1); };

  /**************** MODIFIERS *****************/

  void push_back(const T& x) {
    try {
      if (_capacity == 0) {
        _array = a.allocate(1);
        a.construct(_array, x);
        _capacity = 1;
        _size = 1;
        return;
      }
      if (_size == _capacity) realloc(_capacity * 2);
      a.construct(_array + _size, x);
      _size++;
    } catch (std::bad_alloc& e) {
      throw e;
    }
  };

  void pop_back() throw() {
    a.destroy(_array + _size - 1);
    _size--;
  };

  iterator insert(iterator position, const T& x) {
    ft::vector<T> save(*this);
    try {
      if (_size == 0) {
        if (_capacity == 0) {
          _array = a.allocate(1);
          _capacity = 1;
        }
        a.construct(_array, x);
        _size = 1;
        return _array;
      }
      size_type ins = position - _array;
      if (_size == _capacity) realloc(_capacity * 2);
      for (size_type i = _size; i > ins; i--) _array[i] = _array[i - 1];
      _size++;
      a.construct(_array + ins, x);
      return _array + ins;
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  void insert(iterator position, size_type n, const T& x) {
    ft::vector<T> save(*this);
    try {
      size_type ins = position - _array;
      if (_capacity == 0) {
        _array = a.allocate(n);
        _capacity = n;
      } else if (_size + n > _capacity)
        realloc(_capacity * 2);
      for (size_type i = _size; i >= ins; i--)
        a.construct(_array + i + n, _array[i]);
      _size += n;
      for (size_type i = ins; i < n + ins; i++) a.construct(_array + i, x);
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  template <class InputIterator>
  void insert(iterator position, InputIterator first,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type last) {
    ft::vector<T> save(*this);
    try {
      difference_type to_insert = last - first;
      difference_type ins = position - _array;

      if (_capacity == 0) {
        _array = a.allocate(to_insert);
        _capacity = to_insert;
      }
      if (_size + to_insert > _capacity) realloc(_capacity * 2);
      for (size_type i = _size; i >= ins; i--)
        a.construct(_array + i + to_insert, _array[i]);
      _size += to_insert;
      for (size_type i = ins; i < to_insert + ins; i++) {
        a.construct(_array + i, *first);
        first++;
      };
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  iterator erase(iterator position) {
    iterator saved = position;
    try {
      for (iterator it = position; it + 1 != end(); it++) *it = *(it + 1);
      _size--;
      a.destroy(_array + _size);
    } catch (std::exception& e) {
      throw e;
    }
    return saved;
  };

  iterator erase(iterator first, iterator last) {
    size_type to_erase = last - first;
    try {
      for (iterator it = first; it != end() - to_erase; it++)
        *(it) = *(it + to_erase);
      _size -= to_erase;
      for (size_type i = 0; i < to_erase; i++) a.destroy(_array + _size + i);
      return last - to_erase;
    } catch (std::exception& e) {
      throw e;
    }
  };

  void swap(ft::vector<T, Allocator>& other) throw() {
    try {
      if (_size > other.max_size() || other.size() > _max_size) return;
      std::swap(a, other.a);
      std::swap(_array, other._array);
      std::swap(_size, other._size);
      std::swap(_capacity, other._capacity);
    } catch (std::exception& e) {
      throw e;
    }
  };

  void clear() throw() {
    for (size_type i = 0; i < _size; i++) a.destroy(&_array[i]);
    _size = 0;
  };

 private:
  T* _array;
  size_type _size;
  size_type _max_size;
  size_type _capacity;
  std::allocator<T> a;

  void realloc(size_type n) {
    try {
      if (n <= _capacity) return;
      if (n >= _max_size) throw(std::length_error(""));
      T* tmp = a.allocate(n);
      std::uninitialized_copy(_array, _array + _size, tmp);
      for (size_type i = 0; i < _size; i++) {
        a.destroy(&_array[i]);
      }
      a.deallocate(_array, _capacity);
      _array = tmp;
      _capacity = n;

    } catch (std::exception& e) {
      throw(e);
    }
  };
};

template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& x,
                const vector<T, Allocator>& y) throw() {
  if (x.size() != y.size()) return false;
  return (ft::equal(x.begin(), x.end(), y.begin()));
};

template <class T, class Allocator>
bool operator<(const vector<T, Allocator>& x,
               const vector<T, Allocator>& y) throw() {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
};

template <class T, class Allocator>
bool operator!=(const vector<T, Allocator>& x,
                const vector<T, Allocator>& y) throw() {
  return !(x == y);
};

template <class T, class Allocator>
bool operator>(const vector<T, Allocator>& x,
               const vector<T, Allocator>& y) throw() {
  return (y < x);
};

template <class T, class Allocator>
bool operator>=(const vector<T, Allocator>& x,
                const vector<T, Allocator>& y) throw() {
  return !(x < y);
};

template <class T, class Allocator>
bool operator<=(const vector<T, Allocator>& x,
                const vector<T, Allocator>& y) throw() {
  return !(y < x);
};

template <class T, class Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y) throw() {
  try {
    x.swap(y);
  } catch (std::exception& e) {
    return;
  }
};
}  // namespace ft
#endif
