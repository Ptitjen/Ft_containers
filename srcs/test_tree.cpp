

#include "Node.hpp"
#include "make_pair.hpp"
#include "map_utils.hpp"
#include "tree.hpp"

int main(void) {
  ft::Node<ft::pair<int, char> > n =
      ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
  printNode(&n);

  ft::RbTree<int, char> t = ft::RbTree<int, char>(n);
  printNode(t.getStart());
  std::cout << std::endl;
  printNode((t.getStart()->getLeft()));
  printNode((t.getStart()->getRight()));
  printTree(t);
}