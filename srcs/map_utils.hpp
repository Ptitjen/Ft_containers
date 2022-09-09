#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP
#include <__nullptr>

#include "Node.hpp"
#include "tests_utils.hpp"
#include "tree.hpp"

template <class Key, class T>
void printNode(const ft::Node<ft::pair<Key, T> >& node) {
  if (&node == nullptr) {
    std::cout << BOLDWHITE "X " END;
    return;
  }

  if (node._color == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << node._content.first << ":" << node._content.second << END;
}

template <class Key, class Value>
void printTree(ft::RbTree<Key, Value> tree) {
  for (typename ft::RbTree<Key, Value>::iterator it = tree.begin();
       it != tree.last(); it++) {
    std::cout << it->_content.first << " " << it->_content.second << std::endl;
  }
}

#endif
