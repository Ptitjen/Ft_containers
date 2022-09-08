#ifndef TREE_HPP
#define TREE_HPP

// Every node in T is either red or black.
// The root node of T is black.
// Every NULL node is black.
// If a node is red, both of its children are black. This means
// no two nodes on a path can be red nodes. Every path from a root node to a
// NULL node has the same number of black nodes.
#include <iterator>
#include <memory>

#include "Node.hpp"
#include "pair.hpp"
#include "tests_utils.hpp"
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
  size_type getCount() const { return _count; }
  void increaseCount(size_type n) { _count += n; }
  void decreaseCount(size_type n) { _count -= n; }

 private:
  size_type _count;
  BaseNode* _start;
  // height?
};

/* ******************* TREE ****************** */

// change with this when keyofvalue ok
//  template <class Key, class Value, class KeyOfValue,
//            class Compare = std::less<Key>,
//            class Allocator = std::allocator<Node<ft::pair<Key, Value> > > >

template <class Key, class Value, class Compare = std::less<Key>,
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
    iterator& operator++() {  // TODO?
      increment();
      return *this;
    }
    iterator operator++(int) {  // TODO?
      iterator it = *this;
      increment();
      return it;
    }
    // TO CHECK => *a++

    iterator& operator--() {  // TODO?
      decrement();
      return *this;
    }
    iterator operator--(int) {  // TODO?
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
      if (isEnd()) return;  // TODO : check what to do
      if (ptr_->getRight())
        ptr_ = ptr_->getRight();
      else if (isLeftNode())
        ptr_ = ptr_->getParent();
      else if (isRightNode()) {
        while (!isLeftNode()) ptr_ = ptr_->getParent();
        ptr_ = ptr_->getParent();
      }
    }
    void decrement() {
      if (isBegin()) return;  // TODO : check what to do
      if (ptr_->getLeft())
        ptr_ = ptr_->getLeft();
      else if (isRightNode())
        ptr_ = ptr_->getParent();
      else if (isLeftNode()) {
        while (!isRightNode()) ptr_ = ptr_->getParent();
        ptr_ = ptr_->getParent();
      }
    }

    bool isLeftNode() { return ptr_->getParent()->getLeft() == ptr_; }

    bool isRightNode() { return ptr_->getParent()->getRight() == ptr_; }

    bool isEnd() {
      while (ptr_->getParent()) {
        if (isLeftNode()) return false;
        ptr_ = ptr_->getParent();
      }
      return true;
    }

    bool isBegin() {
      while (ptr_->getParent()) {
        if (isRightNode()) return false;
        ptr_ = ptr_->getParent();
      }
      return true;
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
    const_iterator(iterator const& it) throw() : ptr_(it.ptr_){};
    iterator& operator=(iterator const& it) {
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
    // TO CHECK => *a++

    const_iterator& operator--() {  // TODO?
      decrement();
      return *this;
    }
    const_iterator operator--(int) {  // TODO?
      const_iterator it = *this;
      decrement();
      return it;
    }
    // TO CHECK => *a--

    reference operator*() { return *ptr_; }
    pointer operator->() { return ptr_; }

    /* comparison */
    bool operator==(const const_iterator& other) { return ptr_ == other.ptr_; }
    bool operator!=(const const_iterator& other) { return ptr_ != other.ptr_; }

    // private:
    pointer ptr_;

    void increment() {
      if (isEnd()) return;  // TODO : check what to do
      if (ptr_->getRight())
        ptr_ = ptr_->getRight();
      else if (isLeftNode())
        ptr_ = ptr_->getParent();
      else if (isRightNode()) {
        while (!isLeftNode()) ptr_ = ptr_->getParent();
        ptr_ = ptr_->getParent();
      }
    }
    void decrement() {
      if (isBegin()) return;  // TODO : check what to do
      if (ptr_->getLeft())
        ptr_ = ptr_->getLeft();
      else if (isRightNode())
        ptr_ = ptr_->getParent();
      else if (isLeftNode()) {
        while (!isRightNode()) ptr_ = ptr_->getParent();
        ptr_ = ptr_->getParent();
      }
    }

    bool isLeftNode() { return ptr_->getParent()->getLeft() == ptr_; }

    bool isRightNode() { return ptr_->getParent()->getRight() == ptr_; }

    bool isEnd() {
      while (ptr_->getParent()) {
        if (isLeftNode()) return false;
        ptr_ = ptr_->getParent();
      }
      return true;
    }

    bool isBegin() {
      while (ptr_->getParent()) {
        if (isRightNode()) return false;
        ptr_ = ptr_->getParent();
      }
      return true;
    }
  };

  /************* CONSTRUCTORS **************/

  RbTree() {}
  RbTree(T startNode) {
    _startNode = _a.allocate(1);
    _startNode = &startNode;
    _header = TreeHeader<T>(1, _startNode);
    startNode.setLeft(NULL);
    startNode.setRight(NULL);
  }
  ~RbTree() {}

  /**************** ACCESS ************/

  T* getStart() { return _startNode; }
  iterator begin() {
    iterator it(_startNode);
    while (it.ptr_->getLeft()) it = it.ptr_->getLeft();
    return it;
  }
  const_iterator begin() const {
    const_iterator it(_startNode);
    while (it.ptr_->getLeft()) it = it.ptr_->getLeft();
    return it;
  }

  iterator last() {
    iterator it(_startNode);
    while (it.ptr_->getRight()) it = it.ptr_->getRight();
    return it;
  }
  const_iterator last() const {
    const_iterator it(_startNode);
    while (it.ptr_->getRight()) it = it.ptr_->getRight();
    return it;
  }

  void addNode(T* x) {
    iterator next = begin();
    /* if 1st */
    if (Compare(x->getContent().first, next.getContent().first)) {  // new first
      next.setLeft(x);
      // reequilibrer
    }
    /* 1. find position */
    while (Compare(x->getContent().first, next.getContent().first)) {
      next++;
    }
    next--;
    /* 2. insert */
  }

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

  // while (it.getParent().getColor() == RED_NODE)
  //   if (it.getParent() == it.getParent().getParent().getRight()) {
  //     if (it.getParent().getParent().getLeft().getColor() == RED_NODE) {
  //       it.getParent().getParent().getLeft().setColor(BLACK_NODE);
  //       it.getParent().setColor(BLACK_NODE);
  //       it.getParent().getParent().setColor(RED_NODE);
  //       it = it.getParent().getParent();
  //     } else if (it.isLeftNode()) {
  //       it = it.getParent();
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
