#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP
#include "Node.hpp"
#include "tests_utils.hpp"

template <class Key, class T>
void printNode(ft::Node<ft::pair<Key, T> > node) {
  if (node.getColor() == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << node.getContent().first;
  std::cout << END << std::endl;
  std::cout << node.getContent().second << std::endl;
  ;
}

#endif
