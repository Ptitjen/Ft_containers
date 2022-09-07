#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP
#include "Node.hpp"
#include "tests_utils.hpp"

template <class Key, class T>
void printNode(ft::Node<ft::pair<Key, T> > node) {
  if (!node.getPtr()) {
    std::cout << BOLDWHITE "END " END;
    return;
  }
  if (node.getColor() == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << node.getContent().first << ":" << node.getContent().second
            << END;
}

#endif
