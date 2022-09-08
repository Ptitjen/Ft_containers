#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

namespace ft {

enum Color { BLACK_NODE, RED_NODE };
enum Type { LEFT_NODE, RIGHT_NODE, START_NODE, NOT_YET_DEFINED };

class BaseNode;
/* ******************* NODE BASE ****************** */

class BaseNode {
 public:
  BaseNode() {
    color = BLACK_NODE;
    type = NOT_YET_DEFINED;
  };

  ~BaseNode(){};

  Color getColor() const { return color; }
  void setColorColor(Color newColor) { color = newColor; }

  Type getType() { return type; }
  void setType(Type newType) { type = newType; }

 protected:
  // void *ptr;
  Color color;
  Type type;
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
  Node &operator=(const Node &other) {
    if (&other == this) return (*this);
    left = other.getLeft();
    right = other.getRight();
    content = other.getContent();
    _parent = other.getParent();
    ptr = other.getPtr();
  }
  ~Node(){};

  Content getContent() { return content; }

  Node *getLeft() { return left; }
  Node *getRight() { return right; }
  Node *getParent() { return _parent; }
  Node *getPtr() { return ptr; }

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
