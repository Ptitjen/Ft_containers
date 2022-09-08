

#include "Node.hpp"
#include "make_pair.hpp"
#include "map_utils.hpp"
#include "tests_utils.hpp"
#include "tree.hpp"

int main(void) {
  {
    std::cout << BOLDYELLOW "***** SIMPLE TREE *****" END << std::endl;
    ft::Node<ft::pair<int, char> > n =
        ft::Node<ft::pair<int, char> >(ft::make_pair(2, 'b'));
    ft::Node<ft::pair<int, char> > n3 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(3, 'c'));
    n3.setColorColor(ft::RED_NODE);
    ft::Node<ft::pair<int, char> > n2 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(1, 'a'));
    ft::Node<ft::pair<int, char> > n1 =
        ft::Node<ft::pair<int, char> >(ft::make_pair(4, 'd'));

    std::cout << std::endl << "NODES" << std::endl;

    n.setType(ft::START_NODE);
    n.setRight(&n1);
    n.setLeft(&n2);
    n1.setParent(&n);
    n1.setType(ft::RIGHT_NODE);

    n2.setParent(&n);
    n2.setType(ft::LEFT_NODE);
    n1.setLeft(&n3);
    n3.setParent(&n1);
    n3.setType(ft::LEFT_NODE);
    ft::RbTree<int, char> t = ft::RbTree<int, char>(n);
    t.resetHeader();

    std::cout << "          ";
    printNode(t.getStart());
    std::cout << std::endl << "    ";
    printNode(t.getStart()->getLeft());

    std::cout << "    |    ";
    printNode(t.getStart()->getRight());
    std::cout << std::endl;
    printNode(t.getStart()->getLeft()->getLeft());
    std::cout << "   ";
    printNode(t.getStart()->getLeft()->getRight());
    std::cout << "| ";

    printNode(t.getStart()->getRight()->getLeft());
    std::cout << "    ";

    printNode(t.getStart()->getRight()->getRight());

    std::cout << std::endl << std::endl << "ACCESS" << std::endl;
    std::cout << std::endl << "Begin : ";

    ft::RbTree<int, char>::iterator it = t.begin();
    std::cout << &*t.begin() << std::endl;
    std::cout << it->getContent().first << " " << it->getContent().second
              << std::endl;
    std::cout << std::endl << "Last : ";

    ft::RbTree<int, char>::iterator itl = t.last();
    std::cout << &*t.last() << std::endl;

    std::cout << itl->getContent().first << " " << itl->getContent().second
              << std::endl;

    std::cout << std::endl;

    std::cout << std::endl << "TREE" << std::endl;
    std::cout << "Incrementation" << std::endl;
    std::cout << " --- " << std::endl;
    for (ft::RbTree<int, char>::iterator itv = t.begin(); itv != t.last();
         itv++) {
      std::cout << "|";
      if (itv->getColor() == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->getContent().first << " " << itv->getContent().second
                << END << "| ";
      if (itv->getType() == ft::START_NODE)
        std::cout << "Start node" << std::endl;
      if (itv->getType() == ft::LEFT_NODE)
        std::cout << "Left node" << std::endl;
      if (itv->getType() == ft::RIGHT_NODE)
        std::cout << "Right node" << std::endl;
      std::cout << " --- " << std::endl;
    }
    std::cout << std::endl << "Decrementation" << std::endl;
    std::cout << " --- " << std::endl;

    for (ft::RbTree<int, char>::iterator itv = t.last(); itv != t.begin();
         itv--) {
      std::cout << "|";
      if (itv->getColor() == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->getContent().first << " " << itv->getContent().second
                << END << "| ";
      if (itv->getType() == ft::START_NODE)
        std::cout << "Start node" << std::endl;
      if (itv->getType() == ft::LEFT_NODE)
        std::cout << "Left node" << std::endl;
      if (itv->getType() == ft::RIGHT_NODE)
        std::cout << "Right node" << std::endl;
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
        ft::Node<ft::pair<int, char> >(ft::make_pair(9, 'i'));

    std::cout << std::endl << "NODES" << std::endl;

    n6.setType(ft::START_NODE);

    n6.setRight(&n8);
    n8.setParent(&n6);
    n8.setType(ft::RIGHT_NODE);

    n6.setLeft(&n2);
    n2.setParent(&n6);
    n2.setType(ft::LEFT_NODE);

    n2.setLeft(&n1);
    n1.setParent(&n2);
    n1.setType(ft::LEFT_NODE);

    n2.setRight(&n4);
    n4.setParent(&n2);
    n4.setType(ft::RIGHT_NODE);

    n4.setLeft(&n3);
    n3.setParent(&n4);
    n3.setType(ft::LEFT_NODE);

    n4.setRight(&n5);
    n5.setParent(&n4);
    n5.setType(ft::RIGHT_NODE);

    n8.setRight(&n9);
    n9.setParent(&n8);
    n9.setType(ft::RIGHT_NODE);

    n8.setLeft(&n7);
    n7.setParent(&n8);
    n7.setType(ft::LEFT_NODE);

    ft::RbTree<int, char> t = ft::RbTree<int, char>(n6);
    t.resetHeader();

    std::cout << "            ";
    printNode(t.getStart());
    std::cout << std::endl << "    ";
    printNode(t.getStart()->getLeft());
    std::cout << "      |      ";
    printNode(t.getStart()->getRight());
    std::cout << std::endl;

    printNode(t.getStart()->getLeft()->getLeft());
    std::cout << "     ";
    printNode(t.getStart()->getLeft()->getRight());
    std::cout << "  |  ";
    printNode(t.getStart()->getRight()->getLeft());
    std::cout << "    ";
    printNode(t.getStart()->getRight()->getRight());
    std::cout << std::endl;
    printNode(t.getStart()->getLeft()->getLeft()->getLeft());
    printNode(t.getStart()->getLeft()->getLeft()->getRight());

    std::cout << "| ";
    printNode(t.getStart()->getLeft()->getRight()->getLeft());
    std::cout << " ";
    printNode(t.getStart()->getLeft()->getRight()->getRight());

    std::cout << "|  ";
    printNode(t.getStart()->getRight()->getLeft()->getLeft());
    printNode(t.getStart()->getRight()->getLeft()->getRight());
    std::cout << "|  ";
    printNode(t.getStart()->getRight()->getRight()->getLeft());
    printNode(t.getStart()->getRight()->getRight()->getRight());

    std::cout << std::endl << std::endl << "ACCESS" << std::endl;
    std::cout << std::endl << "Begin : ";

    ft::RbTree<int, char>::iterator it = t.begin();
    std::cout << &*t.begin() << std::endl;
    std::cout << it->getContent().first << " " << it->getContent().second
              << std::endl;
    std::cout << std::endl << "Last : ";

    ft::RbTree<int, char>::iterator itl = t.last();
    std::cout << &*t.last() << std::endl;

    std::cout << itl->getContent().first << " " << itl->getContent().second
              << std::endl;

    std::cout << std::endl;

    std::cout << std::endl << "TREE" << std::endl;
    std::cout << "Incrementation" << std::endl;
    std::cout << " --- " << std::endl;
    for (ft::RbTree<int, char>::iterator itv = t.begin(); itv != t.last();
         itv++) {
      std::cout << "|";
      if (itv->getColor() == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->getContent().first << " " << itv->getContent().second
                << END << "| ";
      if (itv->getType() == ft::START_NODE)
        std::cout << "Start node" << std::endl;
      if (itv->getType() == ft::LEFT_NODE)
        std::cout << "Left node" << std::endl;
      if (itv->getType() == ft::RIGHT_NODE)
        std::cout << "Right node" << std::endl;
      std::cout << " --- " << std::endl;
    }
    std::cout << std::endl << "Decrementation" << std::endl;
    std::cout << " --- " << std::endl;

    for (ft::RbTree<int, char>::iterator itv = t.last(); itv != t.begin();
         itv--) {
      std::cout << "|";
      if (itv->getColor() == ft::BLACK_NODE)
        std::cout << BOLDBLUE;
      else
        std::cout << BOLDRED;
      std::cout << itv->getContent().first << " " << itv->getContent().second
                << END << "| ";
      if (itv->getType() == ft::START_NODE)
        std::cout << "Start node" << std::endl;
      if (itv->getType() == ft::LEFT_NODE)
        std::cout << "Left node" << std::endl;
      if (itv->getType() == ft::RIGHT_NODE)
        std::cout << "Right node" << std::endl;
      std::cout << " --- " << std::endl;
    }
    t.leftRotate(t.getStart()->getLeft());  // TO DO

    std::cout << "            ";
    printNode(t.getStart());
    std::cout << std::endl << "    ";
    printNode(t.getStart()->getLeft());
    std::cout << "      |      ";
    printNode(t.getStart()->getRight());
    std::cout << std::endl;

    printNode(t.getStart()->getLeft()->getLeft());
    std::cout << "     ";
    printNode(t.getStart()->getLeft()->getRight());
    std::cout << "  |  ";
    printNode(t.getStart()->getRight()->getLeft());
    std::cout << "    ";
    printNode(t.getStart()->getRight()->getRight());
    std::cout << std::endl;
    printNode(t.getStart()->getLeft()->getLeft()->getLeft());
    printNode(t.getStart()->getLeft()->getLeft()->getRight());

    std::cout << "| ";
    printNode(t.getStart()->getLeft()->getRight()->getLeft());
    std::cout << " ";
    printNode(t.getStart()->getLeft()->getRight()->getRight());

    std::cout << "|  ";
    printNode(t.getStart()->getRight()->getLeft()->getLeft());
    printNode(t.getStart()->getRight()->getLeft()->getRight());
    std::cout << "|  ";
    printNode(t.getStart()->getRight()->getRight()->getLeft());
    printNode(t.getStart()->getRight()->getRight()->getRight());
  }
}