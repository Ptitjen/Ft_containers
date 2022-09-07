#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>
namespace ft {

enum Color { BLACK_NODE, RED_NODE };

/* ******************* NODE BASE ****************** */

class BaseNode {
 public:
  BaseNode() {
    color = BLACK_NODE;
    parent = NULL;
    ptr = NULL;
  };
  ~BaseNode(){};

  BaseNode *getPtr() { return ptr; }
  Color getColor() { return color; }

 protected:
  BaseNode *ptr;
  Color color;
  BaseNode *parent;
};

/* ******************* NODE ****************** */

template <class Content>
class Node : public BaseNode {
 public:
  Node() : left(NULL), right(NULL), content(NULL) {
    color = BLACK_NODE;
    parent = NULL;
  };
  Node(Content c) : content(c), left(NULL), right(NULL) {
    color = BLACK_NODE;
    parent = NULL;
    ptr = this;
  };
  ~Node(){};

  Content getContent() { return content; }

 private:
  BaseNode *left;
  BaseNode *right;
  Content content;
};

/* ******************* END NODE ****************** */

class EndNode : public BaseNode {
 public:
  EndNode() {
    color = BLACK_NODE;
    ptr = NULL;
  }
  EndNode(BaseNode &n) {
    color = BLACK_NODE;
    ptr = NULL;
    parent = n.getPtr();
  }
  ~EndNode() {}
};

}  // namespace ft

#endif
