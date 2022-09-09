#include "Node.hpp"
#include "make_pair.hpp"
#include "map_utils.hpp"

void printThisTree(ft::RbTree<int, char>& t) {
  std::cout << "            ";
  /* Start*/
  printNode(*t.getStart());
  std::cout << std::endl << "    ";
  /*Etage 1*/
  printNode(*t.getStart()->_left);
  std::cout << "      |      ";
  printNode(*t.getStart()->_right);
  std::cout << std::endl;
  /* Etage 2 */
  if (t.getStart()->_left != NULL) {
    printNode(*t.getStart()->_left->_left);
    std::cout << "     ";
    printNode(*t.getStart()->_left->_right);
    std::cout << "  |  ";
  }
  if (t.getStart()->_right != NULL) {
    printNode(*t.getStart()->_right->_left);
    std::cout << "    ";
    printNode(*t.getStart()->_right->_right);
    std::cout << std::endl;
  }
  /* Etage 3 */
  if (t.getStart()->_left != NULL && t.getStart()->_left->_left != NULL) {
    printNode(*t.getStart()->_left->_left->_left);
    printNode(*t.getStart()->_left->_left->_right);
  }
  std::cout << "|";
  if (t.getStart()->_left != NULL && t.getStart()->_left->_right != NULL) {
    printNode(*t.getStart()->_left->_right->_left);
    std::cout << " ";
    printNode(*t.getStart()->_left->_right->_right);
  }
  if (t.getStart()->_right != NULL && t.getStart()->_right->_left != NULL) {
    std::cout << "| ";
    printNode(*t.getStart()->_right->_left->_left);
    printNode(*t.getStart()->_right->_left->_right);
    std::cout << "| ";
  }
  if (t.getStart()->_right != NULL && t.getStart()->_right->_right != NULL) {
    printNode(*t.getStart()->_right->_right->_left);
    std::cout << " ";
    printNode(*t.getStart()->_right->_right->_right);
  }
  std::cout << std::endl;
}

void printWithIterators(ft::RbTree<int, char>& t) {
  ft::RbTree<int, char>::iterator itv = t.begin();
  for (; itv != t.last(); itv++) {
    std::cout << "|";
    if (itv->_color == ft::BLACK_NODE)
      std::cout << BOLDBLUE;
    else
      std::cout << BOLDRED;
    std::cout << itv->_content.first << " " << itv->_content.second << END
              << "| ";
    if (itv->_type == ft::START_NODE) std::cout << "Start node";
    if (itv->_type == ft::LEFT_NODE) std::cout << "Left node";
    if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node";
    if (itv->_type == ft::NOT_YET_DEFINED) std::cout << BOLDMAGENTA "Undefined";
    std::cout << " " << &*itv << std::endl;
    std::cout << " --- " << std::endl;
  }
  std::cout << "|";
  if (itv->_color == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << itv->_content.first << " " << itv->_content.second << END
            << "| ";
  if (itv->_type == ft::START_NODE) std::cout << "Start node";
  if (itv->_type == ft::LEFT_NODE) std::cout << "Left node";
  if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node";
  if (itv->_type == ft::NOT_YET_DEFINED) std::cout << BOLDMAGENTA "Undefined";
  std::cout << " " << &*itv << std::endl;
  std::cout << " --- " << std::endl;
}

void printWithDecrementIterators(ft::RbTree<int, char>& t) {
  ft::RbTree<int, char>::iterator itv = t.last();
  for (; itv != t.begin(); itv--) {
    std::cout << "|";
    if (itv->_color == ft::BLACK_NODE)
      std::cout << BOLDBLUE;
    else
      std::cout << BOLDRED;
    std::cout << itv->_content.first << " " << itv->_content.second << END
              << "| ";
    if (itv->_type == ft::START_NODE) std::cout << "Start node";
    if (itv->_type == ft::LEFT_NODE) std::cout << "Left node";
    if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node";
    if (itv->_type == ft::NOT_YET_DEFINED) std::cout << BOLDMAGENTA "Undefined";
    std::cout << " " << &*itv << std::endl;
    std::cout << " --- " << std::endl;
  }
  std::cout << "|";
  if (itv->_color == ft::BLACK_NODE)
    std::cout << BOLDBLUE;
  else
    std::cout << BOLDRED;
  std::cout << itv->_content.first << " " << itv->_content.second << END
            << "| ";
  if (itv->_type == ft::START_NODE) std::cout << "Start node";
  if (itv->_type == ft::LEFT_NODE) std::cout << "Left node";
  if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node";
  if (itv->_type == ft::NOT_YET_DEFINED) std::cout << BOLDMAGENTA "Undefined";
  std::cout << " " << &*itv << std::endl;
  std::cout << " --- " << std::endl;
}

int main(void) {
  {
    std::cout << BOLDYELLOW "***** SIMPLE TREE *****" END << std::endl;
    ft::Node<ft::pair<int, char> > n2 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));
    ft::Node<ft::pair<int, char> > n3 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));
    n3._color = ft::RED_NODE;
    ft::Node<ft::pair<int, char> > n1 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
    ft::Node<ft::pair<int, char> > n4 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));

    std::cout << std::endl << "NODES" << std::endl;

    n2._type = ft::START_NODE;
    n2._right = &n4;
    n2._left = &n1;
    n1._parent = &n2;
    n4._parent = &n2;
    n1._type = ft::LEFT_NODE;
    n2._parent = NULL;
    n4._type = ft::RIGHT_NODE;
    n4._left = &n3;
    n3._parent = &n4;
    n3._type = ft::LEFT_NODE;
    ft::RbTree<int, char> t = ft::RbTree<int, char>(n2);
    t.resetHeader();

    std::cout << "          ";
    printNode(*t.getStart());
    std::cout << std::endl << "    ";
    printNode(*t.getStart()->_left);

    std::cout << "    |    ";
    printNode(*t.getStart()->_right);
    std::cout << std::endl;
    printNode(*t.getStart()->_left->_left);
    std::cout << "   ";
    printNode(*t.getStart()->_left->_right);
    std::cout << "| ";

    printNode(*t.getStart()->_right->_left);
    std::cout << "    ";

    printNode(*t.getStart()->_right->_right);

    std::cout << std::endl << std::endl << "ACCESS" << std::endl;
    std::cout << std::endl << "Begin : ";

    ft::RbTree<int, char>::iterator it = t.begin();
    std::cout << &*t.begin() << std::endl;
    std::cout << it->_content.first << " " << it->_content.second << std::endl;
    std::cout << std::endl << "Last : ";

    ft::RbTree<int, char>::iterator itl = t.last();
    std::cout << &*t.last() << std::endl;

    std::cout << itl->_content.first << " " << itl->_content.second
              << std::endl;

    std::cout << std::endl;

    std::cout << std::endl << "TREE" << std::endl;
    std::cout << "Incrementation" << std::endl;
    std::cout << " --- " << std::endl;
    for (ft::RbTree<int, char>::iterator itv = t.begin(); itv != t.last();
         itv++) {
      std::cout << "|";
      if (itv->_color == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->_content.first << " " << itv->_content.second << END
                << "| ";
      if (itv->_type == ft::START_NODE) std::cout << "Start node" << std::endl;
      if (itv->_type == ft::LEFT_NODE) std::cout << "Left node" << std::endl;
      if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node" << std::endl;
      std::cout << " --- " << std::endl;
    }
    std::cout << std::endl << "Decrementation" << std::endl;
    std::cout << " --- " << std::endl;

    for (ft::RbTree<int, char>::iterator itv = t.last(); itv != t.begin();
         itv--) {
      std::cout << "|";
      if (itv->_color == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->_content.first << " " << itv->_content.second << END
                << "| ";
      if (itv->_type == ft::START_NODE) std::cout << "Start node" << std::endl;
      if (itv->_type == ft::LEFT_NODE) std::cout << "Left node" << std::endl;
      if (itv->_type == ft::RIGHT_NODE) std::cout << "Right node" << std::endl;
      std::cout << " --- " << std::endl;
    }
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

    n6._type = ft::START_NODE;

    n6._right = &n8;
    n8._parent = &n6;
    n8._type = ft::RIGHT_NODE;

    n6._left = &n2;
    n2._parent = &n6;
    n2._type = ft::LEFT_NODE;

    n2._left = &n1;
    n1._parent = &n2;
    n1._type = ft::LEFT_NODE;

    n2._right = &n4;
    n4._parent = &n2;
    n4._type = ft::RIGHT_NODE;

    n4._left = &n3;
    n3._parent = &n4;
    n3._type = ft::LEFT_NODE;

    n4._right = &n5;
    n5._parent = &n4;
    n5._type = ft::RIGHT_NODE;

    n8._right = &n9;
    n9._parent = &n8;
    n9._type = ft::RIGHT_NODE;

    n8._left = &n7;
    n7._parent = &n8;
    n7._type = ft::LEFT_NODE;

    ft::RbTree<int, char> t = ft::RbTree<int, char>(n6);
    t.resetHeader();
    printThisTree(t);
    std::cout << std::endl << std::endl << "ACCESS" << std::endl;
    std::cout << std::endl << "Begin : ";

    ft::RbTree<int, char>::iterator it = t.begin();
    std::cout << &*t.begin() << std::endl;
    std::cout << it->_content.first << " " << it->_content.second << std::endl;
    std::cout << std::endl << "Last : ";

    ft::RbTree<int, char>::iterator itl = t.last();
    std::cout << &*t.last() << std::endl;

    std::cout << itl->_content.first << " " << itl->_content.second
              << std::endl;

    std::cout << std::endl;

    std::cout << std::endl << "TREE" << std::endl;
    std::cout << "Incrementation" << std::endl;
    std::cout << " --- " << std::endl;
    // printWithIterators(t);
    std::cout << std::endl << "Decrementation" << std::endl;
    std::cout << " --- " << std::endl;

    // printWithDecrementIterators(t);

    ft::Node<ft::pair<int, char> > newNode =
        ft::Node<ft::pair<int, char> >(ft::make_pair(0, '.'));
    t.addNode(newNode);
    printThisTree(t);
    // printWithIterators(t);
    // printWithDecrementIterators(t);

    ft::Node<ft::pair<int, char> > newNodel =
        ft::Node<ft::pair<int, char> >(ft::make_pair(11, 'k'));
    t.addNode(newNodel);
    printThisTree(t);
    // std::cout << "-------------" << std::endl;
    // printWithIterators(t);
    // std::cout << "-------------" << std::endl;
    // printWithDecrementIterators(t);
    // std::cout << "-------------" << std::endl;
    ft::Node<ft::pair<int, char> > newNode2 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(9, 'i'));
    // t.addNode(newNode2);  // to do
    printWithIterators(t);
    std::cout << std::endl << "LEFT ROTATE" << std::endl;
    t.leftRotate(t.getStart()->_right->_right);  // TO DO
    std::cout << std::endl;
    printThisTree(t);
    printWithIterators(t);

    t.leftRotate(t.getStart()->_left->_right);  // TO DO
    std::cout << std::endl;
    printThisTree(t);
    std::cout << "     |";
    printNode(*t.getStart()->_left->_right->_left->_left);
    printNode(*t.getStart()->_left->_right->_left->_right);
    std::cout << std::endl;
    printWithIterators(t);

    t.rightRotate(t.getStart()->_left->_right);
    printThisTree(t);
    printWithIterators(t);
  }
}