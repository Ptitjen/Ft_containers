#ifndef TREE_HPP
#define TREE_HPP

// Every node in T is either red or black.
// The root node of T is black.
// Every NULL node is black.
// If a node is red, both of its children are black. This means
// no two nodes on a path can be red nodes. Every path from a root node to a
// NULL node has the same number of black nodes.
#include <functional>
#include <iterator>
#include <memory>

#include "Node.hpp"
#include "map_utils.hpp"
#include "pair.hpp"

namespace ft {
/* ******************* TREE HEADER ****************** */
template <class T>
class TreeHeader {
  typedef long long unsigned int size_type;

 public:
  TreeHeader() { _count = 0; };
  TreeHeader(size_type n, T* start) {
    _count = n;
    _start = start;
  }
  ~TreeHeader(){};

  size_type _count;
  T* _start;
  T* _begin;
  T* _last;
  // height?
};

/* ******************* TREE ****************** */

// change with this when keyofvalue ok
//  template <class Key, class Value, class KeyOfValue,
//            class Compare = std::less<Key>,
//            class Allocator = std::allocator<Node<ft::pair<Key, Value> > > >

template <class Key, class Value,
          class Compare = std::less<Key>,  // key or val?
          class Allocator = std::allocator<Node<ft::pair<Key, Value> > > >
class RbTree {
  typedef Node<ft::pair<Key, Value> > T;

 public:
  /************* ITERATOR ***************/
  class iterator {
   public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
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
      // std::cout << "Old : " << ptr_ << std::endl;
      increment();
      // std::cout << "New : " << ptr_ << std::endl;
      return *this;
    }
    iterator operator++(int) {
      // std::cout << "Old : " << ptr_ << std::endl;
      iterator it = *this;
      increment();
      // std::cout << "New : " << ptr_ << std::endl;
      return it;
    }
    // TO CHECK => *a++

    iterator& operator--() {
      decrement();
      return *this;
    }
    iterator operator--(int) {
      iterator it = *this;
      decrement();
      return it;
    }
    // TO CHECK => *a--

    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

    /* comparison */
    bool operator==(const iterator& other) { return ptr_ == other.ptr_; }
    bool operator!=(const iterator& other) { return ptr_ != other.ptr_; }

    // private:
    pointer ptr_;

    void increment() {
      if (ptr_->_type == START_NODE) {
        ptr_ = (ptr_->_right)->_ptr;
        while (ptr_->_left) ptr_ = ptr_->_left->_ptr;
      } else if (ptr_->_right) {
        ptr_ = ptr_->_right->_ptr;
        while (ptr_->_left) ptr_ = ptr_->_left->_ptr;

      } else if (ptr_->_type == LEFT_NODE) {
        ptr_ = ptr_->_parent->_ptr;
      } else if (ptr_->_type == RIGHT_NODE) {
        while (!(ptr_->_type == LEFT_NODE)) ptr_ = ptr_->_parent->_ptr;
        ptr_ = ptr_->_parent->_ptr;
      }
    }

    void decrement() {
      if (ptr_->_type == START_NODE) {
        ptr_ = (ptr_->_left)->_ptr;
        while (ptr_->_right) ptr_ = ptr_->_right->_ptr;
      } else if (ptr_->_left) {
        ptr_ = ptr_->_left->_ptr;
        while (ptr_->_right) ptr_ = ptr_->_right->_ptr;

      } else if (ptr_->_type == RIGHT_NODE) {
        ptr_ = ptr_->_parent->_ptr;
      } else if (ptr_->_type == LEFT_NODE) {
        while (!(ptr_->_type == RIGHT_NODE)) ptr_ = ptr_->_parent->_ptr;
        ptr_ = ptr_->_parent->_ptr;
      }
    }
  };

  class const_iterator {
   public:
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef long long unsigned difference_type;

    /* Constructors and destructor */
    const_iterator() throw() : ptr_(NULL){};
    const_iterator(pointer ptr) throw() : ptr_(ptr) {}
    const_iterator(const_iterator const& it) throw() : ptr_(it.ptr_){};
    const_iterator& operator=(const_iterator const& it) {
      if (&it == this) return (*this);
      ptr_ = it.ptr_;
      return (*this);
    };
    ~const_iterator() throw(){};

    /* incrementation and decrementation */
    const_iterator& operator++() {  // TODO?
      increment();
      return *this;
    }
    const_iterator operator++(int) {  // TODO?
      const_iterator it = *this;
      increment();
      return it;
    }

    const_iterator& operator--() {  // TODO?
      decrement();
      return *this;
    }
    const_iterator operator--(int) {  // TODO?
      const_iterator it = *this;
      decrement();
      return it;
    }

    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

    /* comparison */
    bool operator==(const const_iterator& other) { return ptr_ == other.ptr_; }
    bool operator!=(const const_iterator& other) { return ptr_ != other.ptr_; }

    // private:
    pointer ptr_;

    void increment() {
      if (ptr_->_type == START_NODE) {
        ptr_ = (ptr_->_right)->_ptr;
        while (ptr_->_left) ptr_ = ptr_->_left->_ptr;
      } else if (ptr_->_right) {
        ptr_ = ptr_->_right->_ptr;
        while (ptr_->_left) ptr_ = ptr_->_left->_ptr;

      } else if (ptr_->_type == LEFT_NODE) {
        ptr_ = ptr_->_parent->_ptr;
      } else if (ptr_->_type == RIGHT_NODE) {
        while (!(ptr_->_type == LEFT_NODE)) ptr_ = ptr_->_parent->_ptr;
        ptr_ = ptr_->_parent->_ptr;
      }
    }

    void decrement() {
      if (ptr_->_type == START_NODE) {
        ptr_ = (ptr_->_left)->_ptr;
        while (ptr_->_right) ptr_ = ptr_->_right->_ptr;
      } else if (ptr_->_left) {
        ptr_ = ptr_->_left->_ptr;
        while (ptr_->_right) ptr_ = ptr_->_right->_ptr;

      } else if (ptr_->_type == RIGHT_NODE) {
        ptr_ = ptr_->_parent->_ptr;
      } else if (ptr_->_type == LEFT_NODE) {
        while (!(ptr_->_type == RIGHT_NODE)) ptr_ = ptr_->_parent->_ptr;
        ptr_ = ptr_->_parent->_ptr;
      }
    }
  };

  /************* CONSTRUCTORS **************/

  RbTree() {}
  RbTree(T startNode) {
    _startNode = _a.allocate(1);
    _startNode = &startNode;
    _header = TreeHeader<T>(1, _startNode);
    _startNode->_left = startNode._left;
    _startNode->_right = startNode._right;
    _startNode->_parent = NULL;
    iterator it(_startNode);
    while (it->_left) {
      it.ptr_ = it.ptr_->_left->_ptr;
    };
    _header._begin = &*it;
    // it.ptr_->_left = _a.allocate(1);  //
    // it.ptr_->_left = NULL;            //
    iterator itl(_startNode);
    while (it.ptr_->_right) {
      itl++;
    };
    // itl.ptr_->_right = _a.allocate(1);  //
    // itl.ptr_->_right = NULL;            //
    _header._last = &*itl;
  }
  ~RbTree() {  // dealloc
  }

  /**************** ACCESS ************/

  T* getStart() { return _startNode; }

  iterator begin() { return iterator(_header._begin); }
  const_iterator begin() const { return const_iterator(_header._begin); }

  iterator last() { return iterator(_header._last); }

  const_iterator last() const { return const_iterator(_header._last); }

  iterator end() { return iterator(last()->ptr_ + 1); }  // DOES NOT WORK

  const_iterator end() const {
    return const_iterator(last()->ptr_ + 1);
  }  // DOES NOT WORK

  template <typename A, typename B>
  bool f(A a, B b, std::less<Key> u = std::less<Key>()) {
    return u(a, b);
  }

  // HERE
  void addNode(T& x = T()) {
    /* FIRST */

    if (f((x._content).first, begin().ptr_->_content.first)) {
      std::cout << "Add node at beginning" << std::endl;  // new first
      (begin().ptr_)->_left = _a.allocate(1);
      begin().ptr_->_left = &x;
      begin().ptr_->_left->_parent = begin().ptr_;
      resetHeader();
      begin().ptr_->_type = LEFT_NODE;
      // reequilibrer

      return;
    }
    /* LAST */

    if (!f((x._content).first, last().ptr_->_content.first)) {
      std::cout << "Add node at end" << std::endl;  // new first
      (last().ptr_)->_right = _a.allocate(1);
      last().ptr_->_right = &x;
      last().ptr_->_right->_parent = last().ptr_;
      resetHeader();
      last().ptr_->_type = RIGHT_NODE;
      // reequilibrer
      return;
    }
    std::cout << "Somewhere else " << std::endl;
    /* Find position */
    iterator it = begin();
    for (; it != last(); it++) {  // change with end
      std::cout << it.ptr_->_content.first << std::endl;
      if (f((x._content).first, it.ptr_->_content.first)) break;
    }
    std::cout << "Insert before " << it.ptr_->_content.first;
    // insert
  }

  void leftRotate(T* x) {
    std::cout << "Rotate around " << x->_content.first << std::endl;
    // marche autour de 10 et 4
    T* y = (x->_right);
    x->_right = y->_left;
    if (y->_left != NULL) (y->_left)->_parent = x;
    y->_parent = x->_parent;
    if (x->_type == START_NODE)  // x is root
      _startNode = y;
    else if (x->_type == LEFT_NODE)  // x is left child
      (x->_parent)->_left = y;
    else  // x is right child
      (x->_parent)->_right = y;
    y->_left = x;
    x->_type = LEFT_NODE;
    x->_parent = y;
    resetHeader();
  }

  void rightRotate(T* x) {}
  /*

  */
  void resetHeader() {
    iterator it(_startNode);
    while (it->_left) {
      it.ptr_ = it.ptr_->_left->_ptr;
    };
    _header._begin = &*it;
    iterator itl(_startNode);
    while (itl->_right) {
      itl.ptr_ = itl.ptr_->_right->_ptr;
    };

    _header._last = &*itl;
    // itl.ptr_->_right = _a.allocate(1);  //
    // itl.ptr_->_right = NULL;            //

    // reset start?
  };
  /************ MEMBER VALUES ************/
 private:
  Allocator _a;
  TreeHeader<T> _header;
  T* _startNode;

  // RB-INSERT(T, k)
  //      BST-INSERT(T, k) //normal BST insertion
  //      while k.parent.color == RED
  //          if k.parent == k.parent.parent.right
  //             u = k.parent.parent.left //uncle
  //              if u.color == RED // case 3.1
  //                 u.color = BLACK
  //                 k.parent.color = BLACK
  //                 k.parent.parent.color = RED
  //                 k = k.parent.parent
  //              else if k == k.parent.left // case 3.3.1 and 3.3.2
  //                     k = k.parent
  //                     LEFT-ROTATE(T, k)
  //                 k.parent.color = BLACK
  //                 k.parent.parent.color = RED
  //                 RIGHT-ROTATE(T, k.parent.parent)
  //         else (same as then clause with “left” and “right” exchanged)
  //      T.root.color = BLACK

  // while (it._parent._color == RED_NODE)
  //   if (it._parent == it._parent._parent._right) {
  //     if (it._parent._parent._left._color == RED_NODE) {
  //       it._parent._parent._left.setColor(BLACK_NODE);
  //       it._parent.setColor(BLACK_NODE);
  //       it._parent._parent.setColor(RED_NODE);
  //       it = it._parent._parent;
  //     } else if (it.isLeftNode()) {
  //       it = it._parent;
  //       leftRotate(newNode, it);
  //     }
  //   }

  /* Re-structure after modification */
  // left rotation
  // right rotation
  // recolor

  //   RB-DELETE(T, x)
  //      BST-DELETE(T, x)
  //      while x ≠ T.root and x.color == BLACK
  //          if x == x.parent.left
  //              s = x.parent.right
  //              if s.color == RED
  //                  s.color = BLACK // case 3.1
  //                  x.parent.color = RED // case 3.1
  //                  LEFT-ROTATE(T, x.parent) // case 3.1
  //                  s = x.parent.right // case 3.1
  //              if s.left.color == BLACK and s.right.color == BLACK
  //                  s.color = RED // case 3.2
  //                  x = x.parent //case 3.2
  //              else if s.right.color == BLACK
  //                      s.left.color = BLACK // case 3.3
  //                      s.color = RED //case 3.3
  //                      RIGHT-ROTATE(T, s) // case 3.3
  //                      s = x.parent.right // case 3.3
  //                  s.color = x.parent.right // case 3.4
  //                  x.parent.color = BLACK // case 3.4
  //                  s.right.color = BLACK // case 3.4
  //                  LEFT-ROTATE(T, x.parent) // case 3.4
  //                  x = T.root
  //          else (same as then close with “right” and “left” exchanged)
  //      x.color = BLACK
};
}  // namespace ft
#endif
