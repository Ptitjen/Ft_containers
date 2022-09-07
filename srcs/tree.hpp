#ifndef TREE_HPP
#define TREE_HPP

// Every node in T is either red or black.
// The root node of T is black.
// Every NULL node is black.
// If a node is red, both of its children are black. This means
// no two nodes on a path can be red nodes. Every path from a root node to a
// NULL node has the same number of black nodes.
#include <memory>

#include "Node.hpp"
#include "pair.hpp"
namespace ft {

/* ******************* TREE HEADER ****************** */
class TreeHeader {
  typedef long long unsigned int size_type;

 public:
  TreeHeader() { _count = 0; };
  TreeHeader(size_type n, BaseNode* start) {
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
};

/* ******************* TREE ****************** */

// change with this when keyofvalue ok
//  template <class Key, class Value, class KeyOfValue,
//            class Compare = std::less<Key>,
//            class Allocator = std::allocator<Node<ft::pair<Key, Value> > > >

template <class Key, class Value, class Compare = std::less<Key>,
          class Allocator = std::allocator<Node<ft::pair<Key, Value> > > >
class RbTree {
 public:
  RbTree() {}
  RbTree(Node<ft::pair<Key, Value> > startNodeContent) {
    _startNode = _a.allocate(1);
    _startNode = &startNodeContent;
    _header = TreeHeader(1, _startNode->getPtr());
  }
  ~RbTree() {}

  ft::Node<ft::pair<Key, Value> >* _startNode;

 private:
  Allocator _a;
  TreeHeader _header;

  // header
  // start node

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
