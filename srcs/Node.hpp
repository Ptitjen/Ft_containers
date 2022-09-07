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
    ptr = NULL;
  };
  BaseNode(BaseNode *parent) {
    color = BLACK_NODE;
    ptr = NULL;
    _parent = parent;
  };
  ~BaseNode(){};

  BaseNode *getPtr() { return ptr; }
  Color getColor() { return color; }

 protected:
  BaseNode *ptr;
  Color color;
  BaseNode *_parent;
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

  Content getContent() { return content; }

  const Node *getLeft() const { return left; }
  const Node *getRight() const { return right; }

  void setLeft(Node *l) { left = l; }
  void setRight(Node *r) { right = r; }

 private:
  Node *left;
  Node *right;
  Content content;
};

}  // namespace ft

#endif
