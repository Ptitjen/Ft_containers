

#include "Node.hpp"
#include "make_pair.hpp"
#include "map_utils.hpp"
#include "tree.hpp"

int main(void) {
  ft::Node<ft::pair<int, char> > n =
      ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
  // printNode(n);

  ft::RbTree<int, char> t = ft::RbTree<int, char>(n);
  printNode(*t._startNode);
  std::cout << std::endl;
  printNode(*(t._startNode->getLeft()));
  printNode(*(t._startNode->getRight()));
}