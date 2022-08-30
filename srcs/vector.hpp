#ifndef VECTOR_HPP
#define VECTOR_HPP

// template <class Iterator> class iterator_traits;
// template <class T> class iterator_traits<T *>;
// template <class T> class iterator_traits<const T *>;
#include <iterator>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include <exception>
#include <iterator>
#include <new>
#include <stdexcept>
#include <memory>
#include <type_traits>

namespace ft {

/* ******************** class vector ********************* */

template <class T, class Allocator = std::allocator<T> > class vector {

  /* ***************** vector iterator ***************** */
  class iterator {

  public:
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;

    /* Constructors and destructor */
    iterator() : ptr_(NULL){};
    iterator(pointer ptr) : ptr_(ptr) {}
    iterator(iterator const &it);
    iterator &operator=(iterator const &it);
    ~iterator(){};

    /* incrementation and decrementation */
    iterator &operator++() {
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

    iterator &operator--() {
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
    iterator operator-(iterator it) const { // difference type?
      iterator itcpy = *this;
      itcpy.ptr_ = ptr_ - it.ptr_;
      return itcpy;
    };

    iterator &operator+=(difference_type n) {
      ptr_ += n;
      return *this;
    };
    iterator &operator-=(difference_type n) {
      ptr_ -= n;
      return *this;
    };

    /* ref */
    reference operator[](difference_type n) const {
      {
          // TODO
      };
    };

    /* comparison */
    bool operator==(const iterator &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const iterator &rhs) { return ptr_ != rhs.ptr_; }

    bool operator<(const iterator &rhs) { return ptr_ < rhs.ptr_; }
    bool operator>(const iterator &rhs) { return ptr_ > rhs.ptr_; }

    bool operator<=(const iterator &rhs) { return ptr_ <= rhs.ptr_; }
    bool operator>=(const iterator &rhs) { return ptr_ >= rhs.ptr_; }

  private:
    pointer ptr_;
  };

  /* **************** const iterator *************** */

  class const_iterator {

  public:
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef std::random_access_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type; // TO DO : check type of difftype

    /* Constructors and destructor */
    const_iterator() : ptr_(NULL){};
    const_iterator(pointer ptr) : ptr_(ptr) {}
    const_iterator(const_iterator const &it);
    const_iterator &operator=(const_iterator const &it);
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
          // TODO
      };
    };

    /* comparison */
    bool operator==(const const_iterator &rhs) { return ptr_ == rhs.ptr_; }
    bool operator!=(const const_iterator &rhs) { return ptr_ != rhs.ptr_; }

    bool operator<(const const_iterator &rhs) { return ptr_ < rhs.ptr_; }
    bool operator>(const const_iterator &rhs) { return ptr_ > rhs.ptr_; }

    bool operator<=(const const_iterator &rhs) { return ptr_ <= rhs.ptr_; }
    bool operator>=(const const_iterator &rhs) { return ptr_ >= rhs.ptr_; }

  private:
    pointer ptr_;
  };

public:
  // types:
  typedef typename Allocator::reference reference;
  typedef typename Allocator::const_reference const_reference;
  typedef iterator iterator;
  typedef const_iterator const_iterator;
  typedef long unsigned int size_type; // OK
  typedef int difference_type;    // TO CHECK
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;

  // 23.2.4.1 construct/copy/destroy:
  // TODO : explicit authorized in c++98??
  explicit vector(const Allocator & = Allocator()) { //OK
    _size = 0;
    _capacity = 0;
    _max_size = 4611686018427387903;
  }; //OK

  explicit vector(size_type n, const T &value = T(),
                  const Allocator & = Allocator()) {
    std::allocator<T> a;
    _array = a.allocate(n);
    _size = n;
    _capacity = n;
    _max_size = 4611686018427387903;
    for (size_type i = 0; i < n; i++)
      _array[i] = value;
  }; //OK

template <class InputIterator, std::enable_if<!std::is_signed<InputIterator>::value, int> = 0> vector(InputIterator first, InputIterator last, const Allocator & = Allocator()) {
  std::cout << "Called " << std:: endl;
    std::allocator<T> a;
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++)
      to_insert ++;
    a.allocate(to_insert);

    _size = to_insert;
    _capacity = to_insert;
    _max_size = 4611686018427387903;
    for (size_type i = 0; i < to_insert; i++)
      _array[i] = &first + i;  
}//TODO : enable if => find the right type and replace with mine


  vector(const vector<T, Allocator> &x) {
    std::allocator<T> a;
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity);
    for (size_type i = 0; i < _size; i++)
      _array[i] = x._array[i];
  }; //OK

  ~vector() {
    //deallocate ?
  };

  vector<T, Allocator> &operator=(const vector<T, Allocator> &x) {   
    if (&x == this)
      return (*this);
   // _array.clear();
    std::allocator<T> a;
    _max_size = x._max_size;
    _size = x._size;
    _capacity = x._capacity;
    _array = a.allocate(_capacity);
    for (size_type i = 0; i < _size; i++)
      _array[i] = x._array[i];
    return (*this);
  }; //OK

  /******* TO DO *******/
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);
  void assign(size_type n, const T &u);
    /******************************************/
  allocator_type get_allocator() const {return Allocator();};


  // iterators:
  iterator begin() { 
    iterator it;
    it = &_array[0];
    return it; };
  const_iterator begin() const { 
    const iterator& it = &_array[0];
    return it; };
  iterator end() { iterator it;
    it = &_array[_size];
    return it; };
  const_iterator end() const { 
    const iterator& it = &_array[_size];
    return it; };
  reverse_iterator rbegin() { 
    iterator it = &_array[_size - 1];
    return it;  };
  const_reverse_iterator rbegin() const { 
    const iterator& it = &_array[_size - 1];
    return it; };
  reverse_iterator rend() { iterator it = &_array[0] - 1;
    return it; }; // NIMP
  const_reverse_iterator rend() const { const iterator& it = &_array[0] - 1;
    return it; };

  // TODO +++++ : save array before reallocation in case of fail to restore it
  // TODO : try catch for each allocation - catch badalloc
  // TODO : use destroy to destroy elements...

  //  23.2.4.2 capacity:
  size_type size() const { return _size; };         // ok
  size_type max_size() const { return _max_size; }; // ok
  void resize(size_type n, T c = T()) {
    if (n < size()) {
      for (iterator it = _array[n]; it != end(); it++) {
        it.destroy();
      }
      _size = n;
      return;
    }
    if (n > _capacity)
      realloc(n);
    _size = n;
    for (iterator it = _array[n]; it != end(); it++) {
      it = c;
    }
  };
  size_type capacity() const { return _capacity; }; // ok
  bool empty() const { return _size == 0; };        // ok
  void reserve(size_type n) {
    if (n > max_size()) {
      throw std::length_error("");
    }
    if (n > _capacity) {
      realloc(n);
    }
  };

  // ************ element access ************** - ok:
  reference operator[](size_type n) {
    T &ref = _array[n];
    return ref;
  }; // no exception is thrown - no bound check - ok
  const_reference operator[](size_type n) const { // ok
    const T &ref = _array[n];
    return (ref);
  };
  const_reference at(size_type n) const { // throws exception - bound check - ok
    if (n < size()) {
      const T &ref = _array[n];
      return (ref);
    } else
      throw std::out_of_range("");
  };
  reference at(size_type n) { // ok
    if (n < size()) {
      T &ref = _array[n];
      return ref;
    } else
      throw std::out_of_range("");
  };
  reference front() { // undefined behavior if empty - ok
    T &ref = _array[0];
    return ref;
  };
  const_reference front() const { // undefined behavior if empty - ok
    const T &ref = _array[0];
    return ref;
  };
  reference back() { // undefined behavior if empty - ok
    T &ref = _array[size() - 1];
    return ref;
  };
  const_reference back() const { // ok
    const T &ref = _array[size() - 1];
    return ref;
  };

  // 23.2.4.3 modifiers:
  /// TODO : keep copy until realloc - try catch
  void push_back(const T &x) {
    // what to do if size == max size ?
    if (_size == _max_size) { /* ??? */
      return;
    }
    if (_capacity == 0)
      realloc(1);
    else if (_size >= _capacity) {
      if (_capacity > _max_size / 2)
        realloc(_max_size);
      else
        realloc(_capacity * 2);
    }
    _array[_size] = x;
    _size++;
  };

  void pop_back() { // destroys element
    if (size() > 0) {
      _array[size() - 1].destroy();
      _size--;
    }
  }; // ok

  iterator insert(iterator position, const T &x) {
    if (size() >= max_size())
      return; // ?
    try {
      if (size() >= capacity()) {
        if (_capacity > _max_size / 2)
          realloc(_max_size);
        else
          realloc(_capacity * 2);
      }
    } catch (std::bad_alloc &e) {
      return NULL; // ???
    }
    _size++;
    for (iterator it = end(); it != position; it--) {
      *it = *(it - 1);
    }
    *position = x;
    return position;
  };

  void insert(iterator position, size_type n, const T &x) {
    if (size() + n >= max_size())
      return; // ?
    try {
      if (size() + n >= capacity()) {
        while (_capacity < n) { // realloc - throws badalloc if fails
          if (_capacity > _max_size / 2) {
            realloc(_max_size);
            break;
          } else
            realloc(_capacity * 2);
        }
      }
    } catch (std::bad_alloc &e) {
      return; // ???
    }
    _size += n;
    for (iterator it = end(); it != position; it--) {
      *(it + n) = *(it - 1);
    }
    for (iterator it = position; it != position + n; it++) {
      *it = x;
    }
  };

  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last) {
    size_type to_insert = 0;
    for (iterator it = first; it != last; it++)
      to_insert ++;
    if (size() + to_insert >= max_size())
      return; // ?
    try {
      if (size() + to_insert >=
          capacity()) { // realloc - throws badalloc if fails
      }
    } catch (std::bad_alloc &e) {
      return; // ???
    }
    _size += to_insert;
    for (iterator it = end(); it != position; it--) {
      *(it + to_insert) = *(it - 1);
    }
    for (iterator it = position; it != position + to_insert; it++) {
      *it = *first;
      first++;
    }
  };

  iterator erase(iterator position) {
    iterator saved = position + 1;
    for (iterator it = position; it + 1 != end(); it++) {
      *it = *(it + 1);
    }
    position.destroy();
    _size--;
    return saved; // not sure
  };
  iterator erase(iterator first, iterator last) {
    size_type to_erase = 0;
    for (iterator it = first; it != last; it++)
      to_erase ++;
    for (iterator it = first; it != end() - to_erase; it++) {
      it.destroy(); // PROBABLY TO CHANGE - destroy current element
      *(it) = *(it + to_erase);
    }
    _size -= to_erase;
    return last;
  }; // finished but clearly gonna crash
  void swap(ft::vector<T, Allocator> &other) {
    if (size() > other.max_size() || other.size() > max_size())
      return; // ?
    if (size() > other.capacity())
      other.reserve(size());
    if (other.size() > capacity())
      reserve(other.size());
    ft::vector<T> tmp = *this;
    *this = other;
    other = tmp;
  }; // finished - to test
  void clear() {
    for (size_type i = 0; i < size(); i++) {
      _array[i].destroy();
    }
    _size = 0;
  }; // ok

private:
  T* _array;
  size_type _size; //change - size_type / ul
  size_type _max_size;
  size_type _capacity; // size currently allocated

  void realloc(size_type n) {
    std::allocator<T> a;
    if (_capacity == 0)
    {
      _array = a.allocate(1);
      _capacity = 1;
      return;
    }

    T* tmp = a.allocate(n);
    for (size_type i = 0; i < _size; i ++)
    {
      tmp[i] = _array[i];    
    }
    _array = tmp;    
    _capacity = n;
  };
};

template <class T, class Allocator>
bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template <class T, class Allocator>
bool operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template <class T, class Allocator>
bool operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template <class T, class Allocator>
bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template <class T, class Allocator>
bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template <class T, class Allocator>
bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
// specialized algorithms:
template <class T, class Allocator>
void swap(vector<T, Allocator> &x, vector<T, Allocator> &y);
} // namespace ft
#endif
