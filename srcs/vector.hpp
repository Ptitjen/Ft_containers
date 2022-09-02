#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>
#include <iterator>
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
    typedef long unsigned difference_type;  // ou ptrdiff?

    /* Constructors and destructor */
    iterator() : ptr_(NULL){};
    iterator(pointer ptr) : ptr_(ptr) {}
    iterator(iterator const& it) : ptr_(it.ptr_){};
    iterator& operator=(iterator const& it) {  // PB?
      if (&it == this) return (*this);
      ptr_ = it.ptr_;
      return (*this);
    };
    ~iterator(){};

    /* incrementation and decrementation */
    iterator& operator++() {
      ptr_++;
      return *this;
    }
    iterator operator++(int i) {
      iterator it = *this;
      ptr_++;
      return it;
    }

    // pointer operator++() { // TO CHECK => *a++
    //   *ptr_++;
    //   return *this;
    // }

    iterator& operator--() {
      ptr_--;
      return *this;
    }
    iterator operator--(int i) {
      iterator it = *this;
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
    /* ref */
    reference operator[](difference_type n) const {
      return ptr_ + n;  //???
    };

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
    typedef long unsigned difference_type;  // ou ptrdiff?

    /* Constructors and destructor */
    const_iterator() : ptr_(NULL){};
    const_iterator(pointer ptr) : ptr_(ptr) {}
    const_iterator(const_iterator const& it) : ptr_(it.ptr_){};
    const_iterator& operator=(const_iterator const& it) {  // PB?
      if (&it == this) return (*this);
      ptr_ = it.ptr_;
      return (*this);
    };
    ~const_iterator(){};

    /* incrementation and decrementation */
    const_iterator& operator++() {
      ptr_++;
      return *this;
    }
    const_iterator operator++(int i) {
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
    const_iterator operator--(int i) {
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
    reference operator[](difference_type n) const {
      return ptr_ + n;  //???
    };

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

  // TODO +++++ : strong guarantee & verify exceptions
 public:
  /************ TYPEDEFS ************/
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef long unsigned int size_type;
  typedef long unsigned int difference_type;
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;

  /************ CONSTRUCTORS AND DESTRUCTOR ************/
  explicit vector(const Allocator& = Allocator()) {
    _array = a.allocate(1);
    _size = 0;
    _capacity = 0;
    _max_size = 4611686018427387903;
  };

  explicit vector(size_type n, const T& value = T(),
                  const Allocator& = Allocator()) {
    _array = a.allocate(n + 1);
    std::uninitialized_fill(_array, _array + n, value);
    _size = n;
    _capacity = n;
    _max_size = 4611686018427387903;
  };

  template <typename InputIterator>
  vector(InputIterator first,
         typename std::enable_if<!std::is_integral<InputIterator>::value,
                                 InputIterator>::type last,
         const Allocator& = Allocator()) {
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++) to_insert++;
    _array = a.allocate(to_insert + 1);
    _size = to_insert;
    _capacity = to_insert;
    _max_size = 4611686018427387903;
    std::uninitialized_fill(_array, _array + _capacity, T());
    for (size_type i = 0; i < to_insert; i++) {
      _array[i] = *first;
      first++;
    }
  }

  vector(const vector<T, Allocator>& x) {
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity + 1);
    for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
  };  // OK

  ~vector() {
    for (size_type i = 0; i < _capacity; i++) {
      a.destroy(_array + i);
    }
  };

  vector<T, Allocator>& operator=(const vector<T, Allocator>& x) {
    if (&x == this) return (*this);
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity);
    for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
    return (*this);
  };

  template <class InputIterator>
  void assign(InputIterator first,
              typename std::enable_if<!std::is_integral<InputIterator>::value,
                                      InputIterator>::type last) {
    clear();
    insert(begin(), first, last);
  };
  void assign(size_type n, const T& u) {
    clear();
    insert(begin(), n, u);
  };

  allocator_type get_allocator() const { return a; };

  /**************** ITERATOR OPERATORS *****************/
  iterator begin() { return _array; };
  const_iterator begin() const {
    const iterator& it = _array;
    return it;
  };
  iterator end() { return _array + _size; };
  const_iterator end() const {
    const iterator& it = _array + _size;
    return it;
  };

  /**************** REVERSE ITERATOR OPERATORS *****************/

  reverse_iterator rbegin() {
    reverse_iterator it(_array + _size - 1);
    return it;
  };
  const_reverse_iterator rbegin() const {
    const reverse_iterator& it(_array + _size - 1);
    return it;
  };
  reverse_iterator rend() {
    reverse_iterator it(_array - 1);
    return it;
  };
  const_reverse_iterator rend() const {
    const reverse_iterator& it(_array - 1);
    return it;
  };

  /**************** CAPACITY *****************/
  size_type size() const { return _size; };
  size_type max_size() const { return _max_size; };

  void resize(size_type n, T c = T()) {
    if (n < _size) {
      for (size_type i = n; i < _size; i++) {
        a.destroy(_array + i);
      }
      _size = n;
      _capacity = n;
      return;
    }
    size_type save_size = _size;
    if (n > _capacity) {
      realloc(n);
    }
    _size = n;
    for (size_type i = save_size; i < _size; i++) {
      _array[i] = c;
    }
  };

  size_type capacity() const { return _capacity; };
  bool empty() const { return _size == 0; };
  void reserve(size_type n) {
    if (n > max_size()) {
      throw std::length_error("");
    }
    if (n > _capacity) {
      realloc(n);
    }
  };

  /**************** ACCESS *****************/
  reference operator[](size_type n) {
    T& ref = _array[n];
    return ref;
  };
  const_reference operator[](size_type n) const {
    const T& ref = _array[n];
    return (ref);
  };
  const_reference at(size_type n) const {
    if (n < size()) {
      const T& ref = _array[n];
      return (ref);
    }
    throw std::out_of_range("");
  };
  reference at(size_type n) {
    if (n < size()) {
      T& ref = _array[n];
      return ref;
    }
    throw std::out_of_range("");
  };
  reference front() {
    T& ref = _array[0];
    return ref;
  };
  const_reference front() const {
    const T& ref = _array[0];
    return ref;
  };
  reference back() {
    T& ref = _array[size() - 1];
    return ref;
  };
  const_reference back() const {
    const T& ref = _array[size() - 1];
    return ref;
  };

  /**************** MODIFIERS *****************/
  void push_back(const T& x) {
    if (_size == _max_size) { /* ??? */
      return;
    }
    try {
      realloc(_capacity + 1);
    } catch (std::bad_alloc& e) {
      return;
    }
    _array[_size] = x;
    _size++;
  };

  void pop_back() {
    if (_size > 0) {
      a.destroy(_array + _size - 1);
      _size--;
      _capacity--;
    }
  };

  iterator insert(iterator position, const T& x) {
    if (_size == _max_size) return NULL; /* ??? */
    if (_size == 0) {
      try {
        realloc(1);
      } catch (std::bad_alloc& e) {
        return _array;
      }
      _array[0] = x;
      _size = 1;
      return _array;
    }
    size_type ins = 0;
    for (iterator it = _array; it != position; it++) {
      ins++;
    };
    try {
      if (_size == _capacity) {
        realloc(_capacity + 1);
      }
    } catch (std::bad_alloc& e) {
      return _array;
    }
    for (size_type i = _size; i > ins; i--) _array[i] = _array[i - 1];
    _size++;
    _array[ins] = x;
    return _array + ins;
  };

  void insert(iterator position, size_type n, const T& x) {
    if (_size + n >= _max_size) return; /* ??? */
    if (_size == 0) {
      realloc(n);
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
      if (_size >= _capacity) {
        realloc(_capacity + n + 1);
      }
    } catch (std::bad_alloc& e) {
      return;
    }
    for (size_type i = _size; i >= ins; i--) _array[i + n] = _array[i];
    _size += n;
    for (size_type i = ins; i < n + ins; i++) _array[i] = x;
  };

  template <class InputIterator>
  void insert(iterator position, InputIterator first,
              typename std::enable_if<!std::is_integral<InputIterator>::value,
                                      InputIterator>::type last) {
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++) to_insert++;
    size_type ins = 0;
    if (_size == 0) {
      realloc(to_insert);
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
    if (_size + to_insert >= _max_size) return;  //?
    try {
      if (_size + to_insert >= _capacity) {
        realloc(_size + to_insert);
      }
    } catch (std::bad_alloc& e) {
      return;
    }
    for (size_type i = _size; i >= ins; i--) _array[i + to_insert] = _array[i];
    _size += to_insert;
    for (size_type i = ins; i < to_insert + ins; i++) {
      _array[i] = *first;
      first++;
    };
  };

  iterator erase(iterator position) {
    iterator saved = position;
    size_type i = 0;
    for (iterator it = begin(); it != position; it++) {
      i++;
    }
    for (iterator it = position; it + 1 != end(); it++) {
      *it = *(it + 1);
    }
    _size--;
    a.destroy(_array + _size);
    _capacity--;
    return saved;
  };

  iterator erase(iterator first, iterator last) {
    iterator saved = last;
    size_type to_erase = 0;
    for (iterator it = first; it != last; it++) to_erase++;
    for (iterator it = first; it != end() - to_erase; it++) {
      *(it) = *(it + to_erase);
    }
    _size -= to_erase;
    for (size_type i = 0; i < to_erase; i++) {
      a.destroy(_array + _size + i);
    }
    _capacity -= to_erase;
    return last - to_erase;
  };

  void swap(ft::vector<T, Allocator>& other) {
    try {
      if (_size > other.max_size() || other.size() > _max_size) return;
      ft::vector<T> tmp = *this;
      *this = other;
      other = tmp;
    } catch (std::exception& e) {
      return;
    }
  };

  void clear() {
    for (size_type i = 0; i < _size; i++) {
      a.destroy(_array + i);
    }
    _size = 0;
    _capacity = 0;
  };

 private:
  T* _array;
  size_type _size;
  size_type _max_size;
  size_type _capacity;
  std::allocator<T> a;

  void realloc(size_type n) {
    T* tmp = a.allocate(n + 1);
    std::uninitialized_fill(tmp, tmp + n, T());
    for (size_type i = 0; i < _size; i++) {
      tmp[i] = _array[i];
      a.destroy(_array + i);
    }
    _array = tmp;
    _capacity = n;
  };
};

/* ************* TODO ************* */
template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  if (x.size() != y.size()) return false;
  return (ft::equal(x.begin(), x.end(), y.begin()));
};

template <class T, class Allocator>
bool operator==(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  if (x.size() != y.size()) return false;
  return (ft::equal(x.begin(), x.end(), y.begin()));
};

template <class T, class Allocator>
bool operator<(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
};

template <class T, class Allocator>
bool operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
};
/*The less-than comparison (operator<) behaves as if using algorithm
 * lexicographical_compare, which compares the elements sequentially using
 * operator< in a reciprocal manner (i.e., checking both a<b and b<a) and
 * stopping at the first occurrence.*/

template <class T, class Allocator>
bool operator!=(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  return !(x == y);
};
template <class T, class Allocator>
bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return !(x == y);
};

template <class T, class Allocator>
bool operator>(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  return (y < x);
};
template <class T, class Allocator>
bool operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return (y < x);
};

template <class T, class Allocator>
bool operator>=(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  return !(x < y);
};

template <class T, class Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return !(x < y);
};

template <class T, class Allocator>
bool operator<=(vector<T, Allocator>& x, vector<T, Allocator>& y) {
  return !(y < x);
};
template <class T, class Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y) {
  return !(y < x);
};

// TODOspecialized algorithms:
template <class T, class Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y);
}  // namespace ft
#endif
