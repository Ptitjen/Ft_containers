#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>
#include <iterator>
#include <limits>
#include <memory>
#include <new>
#include <stdexcept>
#include <type_traits>

#include "enable_if.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "reverse_iterator.hpp"

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

    // TO CHECK => *a++

    iterator& operator--() {
      ptr_--;
      return *this;
    }
    iterator operator--(int) {
      iterator it = *this;
      ptr_--;
      return it;
    }
    // TO CHECK => *a--

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

   private:
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

    // pointer operator++() { // TO CHECK => *a++
    //   *ptr_++;
    //   return *this;
    // }

    const_iterator& operator--() {
      ptr_--;
      return *this;
    }
    const_iterator operator--(int) {
      const_iterator it = *this;
      ptr_--;
      return it;
    }
    // iterator operator--(iterator *it) { // BAD => *a--
    //   *ptr_--;
    //   return *this;
    // }

    /* deref */
    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

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

   private:
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
  explicit vector(const Allocator& = Allocator()) {
    try {
      _array = a.allocate(1);
      _size = 0;
      _capacity = 0;
      _max_size = std::numeric_limits<long long unsigned>::max();
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  explicit vector(size_type n, const T& value = T(),
                  const Allocator& = Allocator()) {
    if (n > std::numeric_limits<long long unsigned>::max())
      throw(std::length_error(""));
    try {
      _array = a.allocate(n + 1);
      std::uninitialized_fill(_array, _array + n, value);
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
         typename std::enable_if<!std::is_integral<InputIterator>::value,
                                 InputIterator>::type last,
         const Allocator& = Allocator()) {
    size_type to_insert = 0;
    try {
      for (iterator it = first; it != last; it++) to_insert++;
    } catch (std::exception& e) {
      throw e;
    }
    if (to_insert > std::numeric_limits<long long unsigned>::max())
      throw(std::length_error(""));
    try {
      _array = a.allocate(to_insert + 1);
      _size = to_insert;
      _capacity = to_insert;
      _max_size = std::numeric_limits<long long unsigned>::max();
      std::uninitialized_fill(_array, _array + _capacity, T());
      for (size_type i = 0; i < to_insert; i++) {
        _array[i] = *first;
        first++;
      }
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
      _array = a.allocate(_capacity + 1);
      for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
  };

  ~vector() throw() {
    for (size_type i = 0; i < _capacity; i++) {
      a.destroy(_array + i);
    }
    a.deallocate(_array, _capacity);
  };

  vector<T, Allocator>& operator=(const vector<T, Allocator>& x) {
    if (&x == this) return (*this);
    try {
      _max_size = x._max_size;
      _size = x._size;
      _capacity = x._capacity;
      _array = a.allocate(_capacity);
      for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
    } catch (std::exception& e) {
      this->~vector();
      throw e;
    }
    return (*this);
  };

  template <class InputIterator>
  void assign(InputIterator first,
              typename std::enable_if<!std::is_integral<InputIterator>::value,
                                      InputIterator>::type last) {
    try {
      size_type save = _capacity;
      clear();
      reserve(save);
      insert(begin(), first, last);
    } catch (std::exception& e) {
      throw e;
    }
  };

  void assign(size_type n, const T& u) {
    try {
      size_type save = _capacity;
      clear();
      reserve(save);
      insert(begin(), n, u);
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
    reverse_iterator it(_array + _size - 1);
    return it;
  };

  const_reverse_iterator rbegin() const throw() {
    const_reverse_iterator& it(_array + _size - 1);
    return it;
  };

  reverse_iterator rend() throw() {
    reverse_iterator it(_array - 1);
    return it;
  };

  const_reverse_iterator rend() const throw() {
    const_reverse_iterator& it(_array - 1);
    return it;
  };

  /**************** CAPACITY *****************/
  size_type size() const throw() { return _size; };
  size_type max_size() const throw() { return _max_size; };

  void resize(size_type n, T c = T()) {
    if (n > _max_size) throw std::length_error("");  //?
    ft::vector<T> save(*this);
    try {
      if (n < _size) {
        for (size_type i = n; i < _size; i++) {
          a.destroy(_array + i);
        }
        _size = n;
        return;
      }
    } catch (std::exception& e) {
      swap(save);
      return;
    }
    try {
      size_type save_size = _size;
      if (n > _capacity) {
        realloc(n);
      }
      _size = n;
      for (size_type i = save_size; i < _size; i++) {
        _array[i] = c;
      }
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  size_type capacity() const throw() { return _capacity; };
  bool empty() const throw() { return _size == 0; };

  void reserve(size_type n) {
    if (n > max_size()) {
      throw std::length_error("");
    }
    if (n > _capacity) {
      ft::vector<T> save(*this);
      try {
        realloc(n);
      } catch (std::exception& e) {
        swap(save);
        throw e;
      }
    }
  };

  /**************** ACCESS *****************/

  reference operator[](size_type n) throw() {
    T& ref = _array[n];
    return ref;
  };
  const_reference operator[](size_type n) const throw() {
    const T& ref = _array[n];
    return (ref);
  };
  const_reference at(size_type n) const {
    if (n < _size) {
      ft::vector<T> save(*this);
      try {
        const T& ref = _array[n];
        return (ref);
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
        T& ref = _array[n];
        return ref;
      } catch (std::exception& e) {
        swap(save);
        throw e;
      }
    }
    throw std::out_of_range("");
  };
  reference front() throw() {
    T& ref = _array[0];
    return ref;
  };
  const_reference front() const throw() {
    const T& ref = _array[0];
    return ref;
  };
  reference back() throw() {
    T& ref = _array[size() - 1];
    return ref;
  };
  const_reference back() const throw() {
    const T& ref = _array[size() - 1];
    return ref;
  };

  /**************** MODIFIERS *****************/

  void push_back(const T& x) {
    if (_size == _max_size) throw std::length_error(""); /* ??? */
    ft::vector<T> save(*this);
    try {
      if (_capacity == 0)
        reserve(1);
      else if (_size == _capacity) {
        reserve(_capacity * 2);
      }
      _array[_size] = x;
      _size++;
    } catch (std::bad_alloc& e) {
      swap(save);
      return;
    }
  };

  void pop_back() throw() {  // original : segfault if empty?
    // if (_size > 0) {
    a.destroy(_array + _size - 1);
    _size--;
    //}
  };

  iterator insert(iterator position, const T& x) {
    if (_size == _max_size) throw std::length_error(""); /* ??? */
    ft::vector<T> save(*this);
    if (_size == 0) {
      if (_capacity != 0) try {
          realloc(1);
        } catch (std::exception& e) {
          swap(save);
          throw e;
        }
      _array[0] = x;
      _size = 1;
      return _array;
    }
    size_type ins = 0;
    try {
      for (iterator it = _array; it != position; it++) {
        ins++;
      };
      if (_size == _capacity) {
        realloc(_capacity * 2);
      }
      for (size_type i = _size; i > ins; i--) _array[i] = _array[i - 1];
      _size++;
      _array[ins] = x;
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
    return _array + ins;
  };

  void insert(iterator position, size_type n, const T& x) {
    if (_size + n >= _max_size) throw std::length_error(""); /* ??? */
    ft::vector<T> save(*this);
    try {
      if (_size == 0) {
        try {
          if (n > _capacity) realloc(_capacity * 2);
        } catch (std::bad_alloc& e) {
          throw e;
        }
        for (size_type i = 0; i < n; i++) {
          _array[i] = x;
        }
        _size = n;
        return;
      }
      size_type ins = 0;
      for (iterator it = _array; it != position; it++) {
        ins++;
      };
      try {
        if (_size + n >= _capacity) {
          realloc(_capacity * 2);
        }
      } catch (std::bad_alloc& e) {
        throw e;
      }
      for (size_type i = _size; i >= ins; i--) _array[i + n] = _array[i];
      _size += n;
      for (size_type i = ins; i < n + ins; i++) _array[i] = x;
    } catch (std::exception& e) {
      swap(save);
      throw e;
    }
  };

  template <class InputIterator>
  void insert(iterator position, InputIterator first,
              typename std::enable_if<!std::is_integral<InputIterator>::value,
                                      InputIterator>::type last) {
    ft::vector<T> save(*this);
    try {
      size_type to_insert = 0;
      for (iterator it = first; it != last; it++) to_insert++;
      size_type ins = 0;
      if (_size == 0) {
        if (to_insert > _capacity) try {
            realloc(to_insert);
          } catch (std::bad_alloc& e) {
            throw e;
          }
        for (size_type i = 0; i < to_insert; i++) {
          _array[i] = *first;
          first++;
        }
        _size = to_insert;
        return;
      }
      for (iterator it = _array; it != position; it++) {
        ins++;
      };
      if (_size + to_insert >= _max_size) throw std::length_error("");  //?
      try {
        if (_size + to_insert >= _capacity) {
          realloc(_capacity * 2);
        }
      } catch (std::bad_alloc& e) {
        throw e;
      }
      for (size_type i = _size; i >= ins; i--)
        _array[i + to_insert] = _array[i];
      _size += to_insert;
      for (size_type i = ins; i < to_insert + ins; i++) {
        _array[i] = *first;
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
      size_type i = 0;
      for (iterator it = begin(); it != position; it++) {
        i++;
      }
      for (iterator it = position; it + 1 != end(); it++) {
        *it = *(it + 1);
      }
      _size--;
      a.destroy(_array + _size);
    } catch (std::exception& e) {
      throw e;
    }
    return saved;
  };

  iterator erase(iterator first, iterator last) {
    size_type to_erase = 0;
    if (last == end()) try {
        for (iterator it = first; it != last; it++) to_erase++;
        for (iterator it = first; it != end() - to_erase; it++) {
          *(it) = *(it + to_erase);
        }
        _size -= to_erase;
        for (size_type i = 0; i < to_erase; i++) {
          a.destroy(_array + _size + i);
        }
        return last - to_erase;
      } catch (std::exception& e) {
        return last - to_erase;
      }
    else {
      for (iterator it = first; it != last; it++) to_erase++;
      for (iterator it = first; it != end() - to_erase; it++) {
        *(it) = *(it + to_erase);
      }
      _size -= to_erase;
      for (size_type i = 0; i < to_erase; i++) {
        a.destroy(_array + _size + i);
      }
      return last - to_erase;
    }
  };

  void swap(ft::vector<T, Allocator>& other) throw() {
    try {
      if (_size > other.max_size() || other.size() > _max_size) return;
      ft::vector<T> tmp = *this;
      *this = other;
      other = tmp;
    } catch (std::exception& e) {
      return;
    }
  };

  void clear() throw() {
    for (size_type i = 0; i < _size; i++) {
      a.destroy(_array + i);
    }
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
      if (n >= _max_size) throw(std::length_error(""));
      T* tmp = a.allocate(n + 1);
      std::uninitialized_fill(tmp, tmp + n, T());
      for (size_type i = 0; i < _size; i++) {
        tmp[i] = _array[i];
        a.destroy(_array + i);
      }
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
    if (x.size() > y.max_size() || y.size() > x.max_size()) return;
    ft::vector<T> tmp = x;
    x = y;
    y = tmp;
  } catch (std::exception& e) {
    return;
  }
};
}  // namespace ft
#endif
