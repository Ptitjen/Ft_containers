#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <exception>
#include <iterator>
#include <memory>
#include <new>
#include <stdexcept>
#include <type_traits>

#include "enable_if.hpp"
#include "is_integral.hpp"
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
      ptr_(it.ptr_);
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
    /* ref */ reference operator[](difference_type n) const {
      return ptr_[n];  //???
    };

    /* comparison */
    bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }

    bool operator<(const iterator& rhs) { return ptr_ < rhs.ptr_; }
    bool operator>(const iterator& rhs) { return ptr_ > rhs.ptr_; }

    bool operator<=(const iterator& rhs) { return ptr_ <= rhs.ptr_; }
    bool operator>=(const iterator& rhs) { return ptr_ >= rhs.ptr_; }

    //  private: //TODO : reput private when OK
    pointer ptr_;
  };

  /* **************** const iterator *************** */

  class const_iterator {
   public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;  // TO DO : check type of difftype

    /* Constructors and destructor */
    const_iterator() : ptr_(NULL){};
    const_iterator(pointer ptr) : ptr_(ptr) {}
    const_iterator(const_iterator const& it);
    const_iterator& operator=(const_iterator const& it);
    ~const_iterator(){};

    /* incrementation and decrementation */
    const_iterator operator++() {
      ptr_++;
      return *this;
    }
    const_iterator operator++(int i) {
      const_iterator it = *this;
      ptr_++;
      return it;
    }
    // const_iterator
    // operator++(const_iterator *it) { // CHECK function template => *a++
    //   *ptr_++;
    //   return *this;
    // }

    const_iterator operator--() {
      ptr_--;
      return *this;
    }
    const_iterator operator--(int i) {
      const_iterator it = *this;
      ptr_--;
      return it;
    }
    // const_iterator
    // operator--(const_iterator *it) { // CHECK function template => *a--
    //   *ptr_--;
    //   return *this;
    // }

    /* deref */
    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

    /* add and substract */
    const_iterator operator+(difference_type n) const {
      const_iterator it = *this;
      it.ptr_ = ptr_ + n;
      return it;
    };
    const_iterator operator+(const_iterator it) const {
      const_iterator itcpy = *this;
      itcpy.ptr_ = ptr_ + it.ptr_;
      return itcpy;
    };

    const_iterator operator-(difference_type n) const {
      const_iterator it = *this;
      it.ptr_ = ptr_ - n;
      return it;
    };
    const_iterator operator-(const_iterator it) const {
      const_iterator itcpy = *this;
      itcpy.ptr_ = ptr_ - it.ptr_;
      return itcpy;
    };

    const_iterator operator+=(difference_type n) {
      ptr_ += n;
      return *this;
    };
    const_iterator operator-=(difference_type n) {
      ptr_ -= n;
      return *this;
    };

    /* ref */
    reference operator[](difference_type n) const {
      {
        return ptr_[n];  //???
      };
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

 public:
  // types:
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef long unsigned int size_type;        // OK
  typedef long unsigned int difference_type;  // TO CHECK
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;

  // 23.2.4.1 construct/copy/destroy:
  explicit vector(const Allocator& = Allocator()) {
    // std::allocator<T> a;
    _array = a.allocate(1);
    _size = 0;
    _capacity = 0;
    _max_size = 4611686018427387903;
  };  // OK

  explicit vector(size_type n, const T& value = T(),
                  const Allocator& = Allocator()) {
    // std::allocator<T> a;
    _array = a.allocate(n + 1);
    std::uninitialized_fill(_array, _array + n, value);
    _size = n;
    _capacity = n;
    _max_size = 4611686018427387903;
    // for (size_type i = 0; i < n; i++) {
    //   // _array[i] = a.construct(_array[i], value);
    //   _array[i] = value;
    //   // replace with construct ?
    // }
  };  // OK - test with uninitialized fill

  template <typename InputIterator>
  vector(InputIterator first,
         typename std::enable_if<!std::is_integral<InputIterator>::value,
                                 InputIterator>::type last,
         const Allocator& = Allocator()) {
    // std::allocator<T> a;
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++) to_insert++;
    a.allocate(to_insert + 1);
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
    // std::allocator<T> a;
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity + 1);
    for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
  };  // OK

  ~vector(){
      // deallocate ?
  };

  vector<T, Allocator>& operator=(const vector<T, Allocator>& x) {
    if (&x == this) return (*this);
    // std::allocator<T> a;
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity);
    for (size_type i = 0; i < _size; i++) _array[i] = x._array[i];
    return (*this);
  };  // OK

  template <class InputIterator>
  void assign(InputIterator first, InputIterator last) {
    clear();
    insert(first, last);
  };
  void assign(size_type n, const T& u) {
    clear();
    insert(n, u);
  };

  allocator_type get_allocator() const { return Allocator(); };  //???

  // iterators: OK
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

  // reverse iterator :
  /* NOT OK */
  reverse_iterator rbegin() { return &(_array[_size - 1]); };
  const_reverse_iterator rbegin() const {
    const iterator& it = &_array[_size - 1];
    return it;
  };
  reverse_iterator rend() { return &(_array[0]) - 1; };
  const_reverse_iterator rend() const {
    const iterator& it = &_array[0] - 1;
    return it;
  };

  // TODO +++++ : save array before reallocation in case of fail to restore it
  // TODO : try catch for each allocation - catch badalloc
  // TODO : use destroy to destroy elements...

  //  23.2.4.2 capacity:
  size_type size() const { return _size; };          // ok
  size_type max_size() const { return _max_size; };  // ok

  void resize(size_type n, T c = T()) {
    if (n < _size) {
      for (size_type i = n; i < _size; i++) {
        _array[i].~T();
        // dealloc
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
  };  // ok - TO TEST WITH VALUES

  size_type capacity() const { return _capacity; };  // ok
  bool empty() const { return _size == 0; };         // ok
  void reserve(size_type n) {
    if (n > max_size()) {
      throw std::length_error("");
    }
    if (n > _capacity) {
      realloc(n);
    }
  };  // ok

  // ************ element access ************** - ok:
  reference operator[](size_type n) {
    T& ref = _array[n];
    return ref;
  };  // no exception is thrown - no bound check - ok
  const_reference operator[](size_type n) const {  // ok
    const T& ref = _array[n];
    return (ref);
  };
  const_reference at(
      size_type n) const {  // throws exception - bound check - ok
    if (n < size()) {
      const T& ref = _array[n];
      return (ref);
    }
    throw std::out_of_range("");
  };
  reference at(size_type n) {  // ok
    if (n < size()) {
      T& ref = _array[n];
      return ref;
    }
    throw std::out_of_range("");
  };
  reference front() {  // undefined behavior if empty - ok OK
    T& ref = _array[0];
    return ref;
  };
  const_reference front() const {  // undefined behavior if empty - ok OK
    const T& ref = _array[0];
    return ref;
  };
  reference back() {  // undefined behavior if empty - ok OK
    T& ref = _array[size() - 1];
    return ref;
  };
  const_reference back() const {  // ok
    const T& ref = _array[size() - 1];
    return ref;
  };

  // 23.2.4.3 modifiers:  /// TODO : keep copy until realloc - try catch
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
      _array[_size - 1].~T();
      _size--;
    }
  };  // ok

  iterator insert(iterator position, const T& x) {
    if (_size == _max_size) return NULL;  // ?

    size_type ins = 0;
    for (iterator it = _array; it != position; it++) {
      ins++;
    };
    try {
      if (_size == _capacity) {
        realloc(_capacity + 1);
      }
    } catch (std::bad_alloc& e) {
      return NULL;
    }
    for (size_type i = _size; i > ins; i--) _array[i] = _array[i - 1];
    _size++;
    _array[ins] = x;
    return _array + ins;
  };  // ok

  void insert(iterator position, size_type n, const T& x) {
    if (_size + n >= _max_size) return;  // ?
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
  };  // ok

  template <class InputIterator>
  void insert(iterator position, InputIterator first,
              typename std::enable_if<!std::is_integral<InputIterator>::value,
                                      InputIterator>::type last) {
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++) to_insert++;
    size_type ins = 0;
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
  };  // ok

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
  };  // seems ok

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
  };  // seems ok

  void swap(ft::vector<T, Allocator>& other) {
    try {
      if (_size > other.max_size() || other.size() > _max_size) return;
      ft::vector<T> tmp = *this;
      *this = other;
      other = tmp;
    } catch (std::exception& e) {
      return;
    }
  };  // ok

  void clear() {
    for (size_type i = 0; i < _size; i++) {
      _array[i].~T();  // dealloc
    }
    _size = 0;
    _capacity = 0;
  };  // ok

 private:
  T* _array;
  size_type _size;
  size_type _max_size;
  size_type _capacity;
  std::allocator<T> a;

  void realloc(size_type n) {
    // std::allocator<T> a;
    T* tmp = a.allocate(n + 1);
    std::uninitialized_fill(tmp, tmp + n, T());
    for (size_type i = 0; i < _size; i++) {
      tmp[i] = _array[i];
    }
    _array = tmp;
    _capacity = n;

    // destroy and deallocate tmp ?
  };
};

/* ************* TODO ************* */

template <class T, class Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
bool operator<(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
bool operator>(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
template <class T, class Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);
// specialized algorithms:
template <class T, class Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y);
}  // namespace ft
#endif
