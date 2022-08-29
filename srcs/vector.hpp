#ifndef VECTOR_HPP
#define VECTOR_HPP

// template <class Iterator> class iterator_traits;
// template <class T> class iterator_traits<T *>;
// template <class T> class iterator_traits<const T *>;

#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

/* ******************** class vector ********************* */

template <class T, class Allocator = std::allocator<T>> class vector {

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
    iterator operator++(iterator *it) { // TO CHECK => *a++
      *ptr_++;
      return *this;
    }

    iterator &operator--() {
      ptr_--;
      return *this;
    }
    iterator operator--(int i) {
      iterator it = *this;
      ptr_--;
      return it;
    }
    iterator operator--(iterator *it) { // TO CHECK => *a--
      *ptr_--;
      return *this;
    }

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
    const_iterator
    operator++(const_iterator *it) { // CHECK function template => *a++
      *ptr_++;
      return *this;
    }

    const_iterator operator--() {
      ptr_--;
      return *this;
    }
    const_iterator operator--(int i) {
      const_iterator it = *this;
      ptr_--;
      return it;
    }
    const_iterator
    operator--(const_iterator *it) { // CHECK function template => *a--
      *ptr_--;
      return *this;
    }

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
  typedef unsigned int size_type; // TO CHECK - nb of elements
  typedef int difference_type;    // TO CHECK
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename Allocator::pointer pointer;
  typedef typename Allocator::const_pointer const_pointer;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;

  // 23.2.4.1 construct/copy/destroy:
  explicit vector(const Allocator & = Allocator());
  explicit vector(size_type n, const T &value = T(),
                  const Allocator & = Allocator());
  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         const Allocator & = Allocator());
  vector(const vector<T, Allocator> &x);
  ~vector();
  vector<T, Allocator> &operator=(const vector<T, Allocator> &x);
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last);
  void assign(size_type n, const T &u);
  allocator_type get_allocator() const;

  // iterators:
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  reverse_iterator rbegin();
  const_reverse_iterator rbegin() const;
  reverse_iterator rend();
  const_reverse_iterator rend() const;

  // 23.2.4.2 capacity:
  size_type size() const;
  size_type max_size() const;
  void resize(size_type sz, T c = T());
  size_type capacity() const;
  bool empty() const;
  void reserve(size_type n);

  // element access:
  reference operator[](size_type n);
  const_reference operator[](size_type n) const;
  const_reference at(size_type n) const;
  reference at(size_type n);
  reference front();
  const_reference front() const;
  reference back();
  const_reference back() const;

  // 23.2.4.3 modifiers:
  void push_back(const T &x);
  void pop_back();
  iterator insert(iterator position, const T &x);
  void insert(iterator position, size_type n, const T &x);
  template <class InputIterator>
  void insert(iterator position, InputIterator first, InputIterator last);
  iterator erase(iterator position);
  iterator erase(iterator first, iterator last);
  void swap(vector<T, Allocator> &);
  void clear();

private:
  pointer _array; //?
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
