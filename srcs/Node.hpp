#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

namespace ft {

enum Color { BLACK_NODE, RED_NODE };
class BaseNode;
/* ******************* NODE BASE ****************** */

class BaseNode {
 public:
  BaseNode() {
    color = BLACK_NODE;
    // ptr = NULL;
  };

  ~BaseNode(){};

  Color getColor() const { return color; }
  void setColorColor(Color newColor) { color = newColor; }

 protected:
  // void *ptr;
  Color color;
};

/* ******************* NODE ****************** */

template <class Content>
class Node : public BaseNode {
 public:
  Node() : left(NULL), right(NULL), content(NULL) { color = BLACK_NODE; };
  Node(Content c) : content(c), left(NULL), right(NULL) {
    color = BLACK_NODE;
    ptr = this;
  };
  Node(Node *parent) : content(NULL), left(NULL), right(NULL) {  // end node
    color = BLACK_NODE;
    ptr = NULL;
  };

  Node(Content c, Node *parent) : content(c), left(NULL), right(NULL) {
    color = BLACK_NODE;
    _parent = parent;
    ptr = this;
  };
  ~Node(){};

  Content getContent() const { return content; }

  Node *getLeft() const { return left; }
  Node *getRight() const { return right; }
  Node *getParent() const { return _parent; }
  Node *getPtr() const { return ptr; }

  void setLeft(Node *l) { left = l; }
  void setRight(Node *r) { right = r; }
  void setParent(Node *p) { _parent = p; }

 private:
  Node *left;
  Node *right;
  Content content;
  Node *_parent;
  Node *ptr;
};

}  // namespace ft

#endif
