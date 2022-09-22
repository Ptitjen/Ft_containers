#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

namespace ft {

enum Color { BLACK_NODE, RED_NODE };
enum Type {
  LEFT_NODE,
  RIGHT_NODE,
  START_NODE,
  BEGIN_NODE,
  LAST_NODE,
  NOT_YET_DEFINED
};

class BaseNode;
/* ******************* NODE BASE ****************** */

class BaseNode {
 public:
  BaseNode() {
    _color = BLACK_NODE;
    _type = NOT_YET_DEFINED;
  };

  ~BaseNode(){};

  Color _color;
  Type _type;
};

/* ******************* NODE ****************** */

template <class Content>
class Node : public BaseNode {
 public:
  Node() : _left(NULL), _right(NULL), _content(NULL) { _color = BLACK_NODE; };
  Node(Content c) : _content(c), _left(NULL), _right(NULL) {
    _color = BLACK_NODE;
    _ptr = this;
  };
  Node(const Node &other) : _content(other._content) {
    _left = other._left;
    _right = other._right;
    _parent = other._parent;
    _ptr = other._ptr;
    _color = other._color;
    _type = other._type;
  }
  Node &operator=(const Node &other) {
    if (&other == this) return (*this);
    _left = other._left;
    _right = other._right;
    _content = other._content;
    _parent = other._parent;
    _ptr = other._ptr;
    _color = other._color;
    _type = other._type;
    return (*this);
  }
  ~Node(){};

  Node *_left;
  Node *_right;
  Node *_parent;
  Content _content;
  Node *_ptr;
};

}  // namespace ft

#endif
