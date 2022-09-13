
#include "bstree.hpp"
#include "make_pair.hpp"
#include "tests_utils.hpp"

template <class Key, class T>
void printNode(const ft::Node<ft::pair<Key, T> >* node) {
  if (node) {
    if (node->content.first < 0 ||
        node->content.first > 20)  // remove when add ok
      std::cout << "END";
    else
      std::cout << node->content.first << "" << node->content.second;
  } else
    std::cout << "  ";
}

void printThisTree(ft::BstTree<int, char>& t) {
  std::cout << "            ";
  /* Start*/
  printNode(t.getStart());
  std::cout << std::endl << "    ";
  /*Etage 1*/
  printNode(t.getStart()->left);
  std::cout << "      |      ";
  printNode(t.getStart()->right);
  std::cout << std::endl;
  /* Etage 2 */
  if (t.getStart()->left != NULL) {
    printNode(t.getStart()->left->left);
    std::cout << "     ";
    printNode(t.getStart()->left->right);
    std::cout << "   |  ";
  }
  if (t.getStart()->right != NULL) {
    printNode(t.getStart()->right->left);
    std::cout << "    ";
    printNode(t.getStart()->right->right);
    std::cout << std::endl;
  }
  /* Etage 3 */
  if (t.getStart()->left != NULL && t.getStart()->left->left != NULL) {
    printNode(t.getStart()->left->left->left);
    printNode(t.getStart()->left->left->right);
  }
  std::cout << "| ";
  if (t.getStart()->left != NULL && t.getStart()->left->right != NULL) {
    printNode(t.getStart()->left->right->left);
    std::cout << " ";
    printNode(t.getStart()->left->right->right);
  }
  if (t.getStart()->right != NULL && t.getStart()->right->left != NULL) {
    std::cout << " | ";
    printNode(t.getStart()->right->left->left);
    std::cout << " ";
    printNode(t.getStart()->right->left->right);
    std::cout << "|";
  }
  if (t.getStart()->right != NULL && t.getStart()->right->right != NULL) {
    printNode(t.getStart()->right->right->left);
    std::cout << " ";
    printNode(t.getStart()->right->right->right);
  }
  std::cout << std::endl;
}

void printWithIterators(ft::BstTree<int, char>& t) {
  std::cout << std::endl << " --- " << std::endl;
  for (ft::BstTree<int, char>::iterator it = t.begin(); it != t.end(); it++) {
    std::cout << "|";
    std::cout << it.node->content.first << " " << it.node->content.second << "|"
              << std::endl;
    std::cout << " --- " << std::endl;
  }

  // for (ft::BstTree<int, char>::iterator it = t.end(); it != t.begin(); it--)
  // {
  //   std::cout << "|";
  //   std::cout << it.node->content.first << " " << it.node->content.second <<
  //   "|"
  //             << std::endl;
  //   std::cout << " --- " << std::endl;
  // }
}

int main(void) {
  {
    std::cout << BOLDYELLOW "***** SIMPLE TREE *****" END << std::endl;
    // ft::pair<int, char> startpair = ft::make_pair(2, 'b');
    ft::Node<ft::pair<int, char> > n2 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));

    ft::Node<ft::pair<int, char> > n3 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));

    ft::Node<ft::pair<int, char> > n1 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
    ft::Node<ft::pair<int, char> > n4 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));

    // ft::BstTree<int, char> t(startpair); //tree from value
    ft::BstTree<int, char> t(&n2);  // tree from node
    t.getStart()->left = &n1;
    t.getStart()->right = &n4;

    n1.parent = t.getStart();
    n4.parent = t.getStart();

    n4.left = &n3;
    n3.parent = &n4;

    std::cout << "          " << t.getStart()->content.first << " "
              << t.getStart()->content.second << std::endl;

    std::cout << "   " << t.getStart()->left->content.first << " "
              << t.getStart()->left->content.second << "          "
              << t.getStart()->right->content.first << " "
              << t.getStart()->right->content.second << std::endl;
    ;

    std::cout << t.getStart()->left->left << "  " << t.getStart()->left->right;

    std::cout << "     " << t.getStart()->right->left->content.first << " "
              << t.getStart()->right->left->content.second;
    std::cout << "    " << t.getStart()->right->right << std::endl;
    std::cout << "           " << t.getStart()->right->left->left << " "
              << t.getStart()->right->left->right << std::endl;

    t.resetHeader();
    printWithIterators(t);
  }
  {
    std::cout << BOLDYELLOW "***** MORE COMPLICATED TREE *****" END
              << std::endl;
    ft::Node<ft::pair<int, char> > n1 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
    ft::Node<ft::pair<int, char> > n2 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));
    ft::Node<ft::pair<int, char> > n3 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));
    ft::Node<ft::pair<int, char> > n4 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));
    ft::Node<ft::pair<int, char> > n5 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(5, 'e'));
    ft::Node<ft::pair<int, char> > n6 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(6, 'f'));
    ft::Node<ft::pair<int, char> > n7 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(7, 'g'));
    ft::Node<ft::pair<int, char> > n8 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(8, 'h'));
    ft::Node<ft::pair<int, char> > n9 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(10, 'j'));

    std::cout << std::endl << "NODES" << std::endl;

    n6.right = &n8;
    n8.parent = &n6;

    n6.left = &n2;
    n2.parent = &n6;

    n2.left = &n1;
    n1.parent = &n2;

    n2.right = &n4;
    n4.parent = &n2;

    n4.left = &n3;
    n3.parent = &n4;

    n4.right = &n5;
    n5.parent = &n4;

    n8.right = &n9;
    n9.parent = &n8;

    n8.left = &n7;
    n7.parent = &n8;

    ft::BstTree<int, char> t = ft::BstTree<int, char>(&n6);
    t.resetHeader();
    printWithIterators(t);
    printThisTree(t);

    /*** SEARCH ***/  // OK
    // std::cout << (t.search(0, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(1, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(2, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(3, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(4, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(5, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(6, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(7, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(8, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(9, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(10, t.getStart()))->content.second << std::endl;
    // std::cout << (t.search(11, t.getStart()))->content.second << std::endl;

    /*** ADD ***/
    t.addNode(ft::make_pair(0, '.'));
    t.addNode(ft::make_pair(1, 'A'));
    t.addNode(ft::make_pair(2, 'B'));
    t.addNode(ft::make_pair(3, 'C'));
    t.addNode(ft::make_pair(4, 'D'));
    t.addNode(ft::make_pair(5, 'E'));
    t.addNode(ft::make_pair(6, 'F'));
    t.addNode(ft::make_pair(7, 'G'));
    t.addNode(ft::make_pair(8, 'H'));
    t.addNode(ft::make_pair(9, 'I'));
    t.addNode(ft::make_pair(10, 'J'));
    t.addNode(ft::make_pair(11, 'K'));
    printWithIterators(t);
    printThisTree(t);
    std::cout << "                         ";
    printNode(t.getStart()->right->right->right->right);

    // ft::Node<ft::pair<int, char> > newNode =
    //     ft::Node<ft::pair<int, char> >(ft::make_pair(0, '.'));
    // t.addNode(&newNode);
    // printWithIterators(t);

    // // printWithIterators(t);
    // // printWithDecrementIterators(t);

    // ft::Node<ft::pair<int, char> > newNodel =
    //     ft::Node<ft::pair<int, char> >(ft::make_pair(11, 'k'));
    // t.addNode(&newNodel);
    // printWithIterators(t);
    // ft::Node<ft::pair<int, char> > newNode2 =
    //     ft::Node<ft::pair<int, char> >(ft::make_pair(9, 'i'));
    // t.addNode(&newNode2);
    // printWithIterators(t);
  }
}
