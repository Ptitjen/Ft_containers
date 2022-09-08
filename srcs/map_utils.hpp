#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP
#include "Node.hpp"
#include "tests_utils.hpp"
#include "tree.hpp"

// template <class Key, class T>
// void printNode(ft::Node<ft::pair<Key, T> >* node) {
//   if (!node) {
//     std::cout << BOLDWHITE "END " END;
//     return;
//   }
//   if (node->getColor() == ft::BLACK_NODE)
//     std::cout << BOLDBLUE;
//   else
//     std::cout << BOLDRED;
//   std::cout << node->getContent().first << ":" << node->getContent().second
//             << END;
// }

template <class Key, class T>
void printNode(const ft::Node<ft::pair<Key, T> >* node) {
  if (!node) {
    std::cout << BOLDWHITE "END " END;
    return;
  }
  if (node->getColor() == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << node->getContent().first << ":" << node->getContent().second
            << END;
}

template <class Key, class Value>
void printTree(ft::RbTree<Key, Value> tree) {
  for (typename ft::RbTree<Key, Value>::iterator it = tree.begin();
       it != tree.last(); it++) {
    // printNode(it);
  }
}

#endif
