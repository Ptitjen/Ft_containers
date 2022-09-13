
#include "bstree.hpp"
#include "make_pair.hpp"
#include "tests_utils.hpp"

void printWithIterators(ft::BstTree<int, char>& t) {
  ft::BstTree<int, char>::iterator itv = t.begin();
  std::cout << " --- " << std::endl;

  //   for (; itv != t.last(); itv++) {
  //     std::cout << "|";
  //     std::cout << itv.node->content.first << " " << itv.node->content.second
  //               << "|" << std::endl;
  //     std::cout << " --- " << std::endl;
  //   }

  //   std::cout << "|";
  //   std::cout << itv.node->content.first << " " << itv.node->content.second;
  //   std::cout << "|" << std::endl;

  //   std::cout << " --- " << std::endl;
  // std::cout << "Header : " << t.header.node << std::endl;
  // std::cout << "Last: " << t.last().node << std::endl;
  // std::cout << "End: " << t.end().node << std::endl;
  for (ft::BstTree<int, char>::iterator it = t.begin(); it != t.end(); it++) {
    std::cout << "|";
    std::cout << it.node->content.first << " " << it.node->content.second << "|"
              << std::endl;
    std::cout << " --- " << std::endl;
  }
}

int main(void) {
  {
    std::cout << BOLDYELLOW "***** SIMPLE TREE *****" END << std::endl;
    ft::pair<int, char> startpair = ft::make_pair(2, 'b');
    // ft::Node<ft::pair<int, char> > n2 =
    //     ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));
    ft::Node<ft::pair<int, char> > n3 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));

    ft::Node<ft::pair<int, char> > n1 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
    ft::Node<ft::pair<int, char> > n4 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));

    ft::BstTree<int, char> t(startpair);
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

  // std::cout << BOLDYELLOW "***** MORE COMPLICATED TREE *****" END
  //           << std::endl;
  // ft::Node<ft::pair<int, char> > n1 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
  // ft::Node<ft::pair<int, char> > n2 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));
  // ft::Node<ft::pair<int, char> > n3 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));
  // ft::Node<ft::pair<int, char> > n4 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));
  // ft::Node<ft::pair<int, char> > n5 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(5, 'e'));
  // ft::Node<ft::pair<int, char> > n6 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(6, 'f'));
  // ft::Node<ft::pair<int, char> > n7 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(7, 'g'));
  // ft::Node<ft::pair<int, char> > n8 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(8, 'h'));
  // ft::Node<ft::pair<int, char> > n9 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(10, 'j'));

  // std::cout << std::endl << "NODES" << std::endl;

  // n6._type = ft::START_NODE;

  // n6._right = &n8;
  // n8._parent = &n6;
  // n8._type = ft::RIGHT_NODE;

  // n6._left = &n2;
  // n2._parent = &n6;
  // n2._type = ft::LEFT_NODE;

  // n2._left = &n1;
  // n1._parent = &n2;
  // n1._type = ft::LEFT_NODE;

  // n2._right = &n4;
  // n4._parent = &n2;
  // n4._type = ft::RIGHT_NODE;

  // n4._left = &n3;
  // n3._parent = &n4;
  // n3._type = ft::LEFT_NODE;

  // n4._right = &n5;
  // n5._parent = &n4;
  // n5._type = ft::RIGHT_NODE;

  // n8._right = &n9;
  // n9._parent = &n8;
  // n9._type = ft::RIGHT_NODE;

  // n8._left = &n7;
  // n7._parent = &n8;
  // n7._type = ft::LEFT_NODE;

  // ft::RbTree<int, char> t = ft::RbTree<int, char>(n6);
  // t.resetHeader();
  // printThisTree(t);
  // std::cout << std::endl << std::endl << "ACCESS" << std::endl;
  // std::cout << std::endl << "Begin : ";

  // ft::RbTree<int, char>::iterator it = t.begin();
  // std::cout << &*t.begin() << std::endl;
  // std::cout << it->_content.first << " " << it->_content.second << std::endl;
  // std::cout << std::endl << "Last : ";

  // ft::RbTree<int, char>::iterator itl = t.last();
  // std::cout << &*t.last() << std::endl;

  // std::cout << itl->_content.first << " " << itl->_content.second
  //           << std::endl;

  // std::cout << std::endl;

  // std::cout << std::endl << "TREE" << std::endl;
  // std::cout << "Incrementation" << std::endl;
  // std::cout << " --- " << std::endl;
  // // printWithIterators(t);
  // std::cout << std::endl << "Decrementation" << std::endl;
  // std::cout << " --- " << std::endl;

  // // printWithDecrementIterators(t);

  // ft::Node<ft::pair<int, char> > newNode =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(0, '.'));
  // t.addNode(newNode);
  // printThisTree(t);
  // // printWithIterators(t);
  // // printWithDecrementIterators(t);

  // ft::Node<ft::pair<int, char> > newNodel =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(11, 'k'));
  // t.addNode(newNodel);
  // printThisTree(t);
  // // std::cout << "-------------" << std::endl;
  // // printWithIterators(t);
  // // std::cout << "-------------" << std::endl;
  // // printWithDecrementIterators(t);
  // // std::cout << "-------------" << std::endl;
  // ft::Node<ft::pair<int, char> > newNode2 =
  //     ft::Node<ft::pair<int, char> >(ft::make_pair(9, 'i'));
  // // t.addNode(newNode2);  // to do
  // printWithIterators(t);
  // std::cout << std::endl << "LEFT ROTATE" << std::endl;
  // t.leftRotate(t.getStart()->_right->_right);  // TO DO
  // std::cout << std::endl;
  // printThisTree(t);
  // printWithIterators(t);

  // t.leftRotate(t.getStart()->_left->_right);  // TO DO
  // std::cout << std::endl;
  // printThisTree(t);
  // std::cout << "     |";
  // printNode(*t.getStart()->_left->_right->_left->_left);
  // printNode(*t.getStart()->_left->_right->_left->_right);
  // std::cout << std::endl;
  // printWithIterators(t);

  // t.rightRotate(t.getStart()->_left->_right);
  // printThisTree(t);
  // printWithIterators(t);
}
