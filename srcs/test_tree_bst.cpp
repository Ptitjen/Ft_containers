
#include <stdexcept>

#include "bstree.hpp"
#include "make_pair.hpp"
#include "tests_utils.hpp"

template <class Key, class T>
void printNode(const ft::Node<ft::pair<Key, T> >* node) {
  if (node) {
    if (node->content.first < -20 || node->content.first > 20)
      std::cout << "END";
    else
      std::cout << node->content.first << "" << node->content.second;
  } else
    std::cout << "X ";
}

void printThisTree(ft::BstTree<int, char>& t) {
  std::cout << BOLDWHITE "            ";
  /* Start*/
  printNode(t.getStart());
  std::cout << std::endl << "    ";
  /*Etage 1*/
  printNode(t.getStart()->left);
  std::cout << "       |      ";
  printNode(t.getStart()->right);
  std::cout << std::endl;
  /* Etage 2 */
  if (t.getStart()->left != NULL) {
    printNode(t.getStart()->left->left);
    std::cout << "     ";
    printNode(t.getStart()->left->right);
    std::cout << "    |  ";
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
  } else
    std::cout << "    ";
  std::cout << "| ";
  if (t.getStart()->left != NULL && t.getStart()->left->right != NULL) {
    printNode(t.getStart()->left->right->left);
    std::cout << " ";
    printNode(t.getStart()->left->right->right);
  }
  if (t.getStart()->right != NULL && t.getStart()->right->left != NULL) {
    std::cout << "  | ";
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

  std::cout << std::endl << "        ";
  printNode(t.getStart()->left->right->right->left);
  std::cout << " ";
  printNode(t.getStart()->left->right->right->right);
  std::cout << END << std::endl;
}

void printWithIterators(ft::BstTree<int, char>& t) {
  if (t.size() == 0) {
    std::cout << "Empty" << std::endl;
    return;
  }
  for (ft::BstTree<int, char>::iterator it = t.begin(); it != t.end(); it++) {
    std::cout << "|";
    std::cout << it->first << " " << it->second
              << " | Height: " << it.node->height
              << " | LeftW: " << it.node->left_weight
              << " | RightW: " << it.node->right_weight << std::endl;
  }
  //   for (ft::BstTree<int, char>::iterator it = t.begin(); it != t.end();
  //   it++) { std::cout << "|"; std::cout << *(it->first) << " " <<
  //   it.node->content.second;
  // }
  std::cout << "|" << std::endl << std::endl;
}

int main(void) {
  {
    std::cout << BOLDGREEN
        "/* ***************************************************************** "
        "*/" << std::endl
              << "/*                               TREE                        "
                 "        */"
              << std::endl
              << "/* "
                 "*************************************************************"
                 "**** */" END
              << std::endl;

    ft::BstTree<int, char> t;
    ft::BstTree<int, char> tc;
    tc = t;
    printWithIterators(t);
    printWithIterators(tc);
    ft::pair<int, char> p = ft::make_pair(6, 'f');
    t.insert(p);
    // std::cout << t.begin()->first;
    // std::cout << t.last()->first;
    // std::cout << t.size();
    // std::cout << t.end().node;

    // tc = t;
    // printWithIterators(t);
    // printWithIterators(tc);
    ft::pair<int, char> p1 = ft::make_pair(1, 'a');
    t.insert(p1);
    // tc = t;
    // printWithIterators(t);
    // printWithIterators(tc);
    t.insert(ft::pair<int, char>(ft::make_pair(10, 'j')));
    // tc = t;
    // printWithIterators(t);
    // printWithIterators(tc);
    t.insert(ft::pair<int, char>(ft::make_pair(7, 'g')));
    t.insert(ft::pair<int, char>(ft::make_pair(2, 'b')));
    t.insert(ft::pair<int, char>(ft::make_pair(4, 'd')));
    t.insert(ft::pair<int, char>(ft::make_pair(5, 'e')));
    t.insert(ft::pair<int, char>(ft::make_pair(6, 'f')));
    t.insert(ft::pair<int, char>(ft::make_pair(3, 'c')));
    printThisTree(t);
    // std::cout << "Begin : " << t.begin().node;
    std::cout << "End address : " << t.end().node << std::endl;
    printWithIterators(t);

    //   std::cout << std::endl << BOLDBLUE "Lower and upper bounds: " END;

    //   std::cout << "-1: lower:" << t.lower_bound(-1)->first
    //             << " upper: " << t.upper_bound(-1)->first << std::endl;
    //   std::cout << "1: lower:" << t.lower_bound(1)->first
    //             << " upper: " << t.upper_bound(1)->first << std::endl;
    //   std::cout << "5: lower:" << t.lower_bound(5)->first
    //             << " upper: " << t.upper_bound(5)->first << std::endl;
    //   std::cout << "9: lower:" << t.lower_bound(9)->first
    //             << " upper: " << t.upper_bound(9)->first << std::endl;
    //   std::cout << "15: lower:" << t.lower_bound(15)->first
    //             << " upper: " << t.upper_bound(15)->first << std::endl;

    //   std::cout << std::endl << BOLDBLUE "Equal range: " END;

    //   std::cout << "-1: " << t.equal_range(-1).first->first << " "
    //             << t.equal_range(-1).second->first << std::endl;
    //   std::cout << "1: " << t.equal_range(1).first->first << " "
    //             << t.equal_range(1).second->first << std::endl;
    //   std::cout << "5: " << t.equal_range(5).first->first << " "
    //             << t.equal_range(5).second->first << std::endl;
    //   std::cout << "9: " << t.equal_range(9).first->first << " "
    //             << t.equal_range(9).second->first << std::endl;
    //   std::cout << "15: " << t.equal_range(15).first->first << " "
    //             << t.equal_range(15).second->first << std::endl;

    //   /*** SEARCH ***/  // OK
    //   std::cout << std::endl << BOLDBLUE "Find 0-12: " END;
    //   printNode(t.find(0).node);
    //   std::cout << " ";
    //   printNode(t.find(1).node);
    //   std::cout << " ";
    //   printNode(t.find(2).node);
    //   std::cout << " ";
    //   printNode(t.find(3).node);
    //   std::cout << " ";
    //   printNode(t.find(4).node);
    //   std::cout << " ";
    //   printNode(t.find(5).node);
    //   std::cout << " ";
    //   printNode(t.find(6).node);
    //   std::cout << " ";
    //   printNode(t.find(7).node);
    //   std::cout << " ";
    //   printNode(t.find(8).node);
    //   std::cout << " ";
    //   printNode(t.find(9).node);
    //   std::cout << " ";
    //   printNode(t.find(10).node);
    //   std::cout << " ";
    //   printNode(t.find(11).node);
    //   std::cout << " ";
    //   printNode(t.find(12).node);
    //   std::cout << " " << std::endl;

    //   std::cout << BOLDBLUE "Insert: " END << std::endl;

    //   /* BAsic insert */
    //   // std::cout << (t.insert(ft::make_pair(0, '.')).second ? "Insert 0"
    //   //                                                      : "0 already
    //   //                                                      exists")
    //   //           << std::endl;
    //   // std::cout << (t.insert(ft::make_pair(1, 'A')).second ? "Insert 1"
    //   //                                                      : "1 already
    //   //                                                      exists")
    //   //           << std::endl;
    //   // std::cout << (t.insert(ft::make_pair(5, 'E')).second ? "Insert 5"
    //   //                                                      : "5 already
    //   //                                                      exists")
    //   //           << std::endl;
    //   // std::cout << (t.insert(ft::make_pair(9, 'I')).second ? "Insert 9"
    //   //                                                      : "9 already
    //   //                                                      exists")
    //   //           << std::endl;
    //   // std::cout << (t.insert(ft::make_pair(10, 'J')).second ? "Insert 10"
    //   //                                                       : "10 already
    //   //                                                       exists")
    //   //           << std::endl;
    //   // std::cout << (t.insert(ft::make_pair(12, 'K')).second ? "Insert 12"
    //   //                                                       : "12 already
    //   //                                                       exists")
    //   //           << std::endl;

    //   /* With hint insert */
    //   t.insert(t.begin(), ft::make_pair(-1, '='));
    //   t.insert(t.begin(), ft::make_pair(5, '#'));

    //   /*With iterators insert */
    //   std::cout << BOLDBLUE "Insert this tree" END << std::endl;

    //   ft::BstTree<int, char> t_insert;
    //   t_insert.insert(ft::pair<int, char>(ft::make_pair(1, '*')));
    //   t_insert.insert(ft::pair<int, char>(ft::make_pair(9, 'i')));
    //   t_insert.insert(ft::pair<int, char>(ft::make_pair(-2, '/')));
    //   t_insert.insert(ft::pair<int, char>(ft::make_pair(18, '%')));
    //   printWithIterators(t);

    //   std::cout << BOLDWHITE << "          ";
    //   printNode(t_insert.getStart());
    //   std::cout << std::endl;

    //   std::cout << "   ";
    //   printNode(t_insert.getStart()->left);
    //   std::cout << "     |    ";
    //   printNode(t_insert.getStart()->right);
    //   std::cout << std::endl;

    //   std::cout << "           |  ";
    //   printNode(t_insert.getStart()->right->left);
    //   std::cout << "  ";
    //   printNode(t_insert.getStart()->right->right);
    //   std::cout << std::endl;

    //   t.insert(t_insert.begin(), t_insert.end());

    //   printWithIterators(t);
    //   printThisTree(t);
    //   std::cout << "                         ";
    //   std::cout << BOLDWHITE;

    //   printNode(t.getStart()->right->right->right->right);
    //   std::cout << END;

    //   std::cout << std::endl;
    //   std::cout << std::endl << BOLDBLUE "Find 0-12: " END;
    //   printNode(t.find(0).node);
    //   std::cout << " ";
    //   printNode(t.find(1).node);
    //   std::cout << " ";
    //   printNode(t.find(2).node);
    //   std::cout << " ";
    //   printNode(t.find(3).node);
    //   std::cout << " ";
    //   printNode(t.find(4).node);
    //   std::cout << " ";
    //   printNode(t.find(5).node);
    //   std::cout << " ";
    //   printNode(t.find(6).node);
    //   std::cout << " ";
    //   printNode(t.find(7).node);
    //   std::cout << " ";
    //   printNode(t.find(8).node);
    //   std::cout << " ";
    //   printNode(t.find(9).node);
    //   std::cout << " ";
    //   printNode(t.find(10).node);
    //   std::cout << " ";
    //   printNode(t.find(11).node);
    //   std::cout << " ";
    //   printNode(t.find(12).node);
    //   std::cout << std::endl;
    //   printWithIterators(t);
    //   printThisTree(t);
    //   std::cout << BOLDMAGENTA "Size: " END << t.size() << std::endl;

    //   std::cout << BOLDRED "Erase :" END << std::endl;
    //   // t.erase(t.begin());
    //   // printWithIterators(t);
    //   // t.erase(t.find(10));  // right node 2 children
    //   // printThisTree(t);
    //   // printWithIterators(t);
    //   t.erase(t.find(6));  // root
    //   printThisTree(t);
    //   printWithIterators(t);
    //   // t.erase(t.find(1));  // left node 2 childre
    //   // printThisTree(t);
    //   // printWithIterators(t);

    //   /****** ELEMENT ACCESS *****/
    //   std::cout << BOLDBLUE "[]: " END;
    //   std::cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << " "
    //             << t[4] << " " << t[5] << " " << t[6] << " " << t[7] << " "
    //             << t[8] << " " << t[9] << " " << t[10] << " " << t[11] << " "
    //             << t[12] << std::endl;
    //   printWithIterators(t);
    //   printThisTree(t);
    //   /*** Modifying with accessors ***/  // OK
    //   t[0] = '@';
    //   t.at(3) = '#';
    //   printWithIterators(t);

    //   try {
    //     std::cout << BOLDBLUE "At: " END;
    //     std::cout << t.at(0) << " " << t.at(1) << " " << t.at(2) << " " <<
    //     t.at(3)
    //               << " " << t.at(4) << " " << t.at(5) << " " << t.at(6) << "
    //               "
    //               << t.at(7) << " " << t.at(8) << " " << t.at(9) << " "
    //               << t.at(10) << " " << t.at(11) << " " << t.at(12) << " "
    //               << t.at(13) << " " << std::endl;
    //   } catch (std::out_of_range& e) {
    //     std::cout << "Out of range" << std::endl;
    //   }
    //   std::cout << std::endl << BOLDBLUE "Count: " END;

    //   std::cout << "1: " << t.count(1) << " "
    //             << "15: " << t.count(15) << " "
    //             << "-5: " << t.count(-5) << std::endl;

    //   /**** clear ***/
    //   printWithIterators(t_insert);

    //   std::cout << BOLDBLUE "Clear:" END << std::endl;
    //   t_insert.clear();
    //   printWithIterators(t_insert);
    //   t.clear();
    //   printWithIterators(t);

    //   std::cout << BOLDBLUE "Reinsert after Clear:" END << std::endl;
    //   t.insert(ft::pair<int, char>(ft::make_pair(7, 'g')));
    //   t.insert(ft::pair<int, char>(ft::make_pair(2, 'b')));
    //   t.insert(ft::pair<int, char>(ft::make_pair(4, 'd')));
    //   printWithIterators(t);

    //   /*
    //   ***********************************************************************
    //   */
    //   /*                           OTHER CONSTRUCTORS */
    //   /*
    //   ***********************************************************************
    //   */
    //   std::cout << BOLDBLUE "*** Operator = *** : " END << std::endl <<
    //   std::endl; ft::BstTree<int, char> t_op_equal = t; std::cout << "Copy :
    //   "; printWithIterators(t_op_equal); std::cout << " Modifying copy  : ";
    //   t_op_equal.insert(ft::pair<int, char>(ft::make_pair(18, '%')));
    //   printWithIterators(t_op_equal);
    //   std::cout << "Verify original : ";
    //   printWithIterators(t);

    //   std::cout << BOLDBLUE "*** Operator = on not empty tree *** : " END
    //             << std::endl
    //             << std::endl;
    //   ft::BstTree<int, char> t_op_equal2;
    //   t_op_equal2.insert(ft::pair<int, char>(ft::make_pair(1, 'a')));
    //   t_op_equal2.insert(ft::pair<int, char>(ft::make_pair(0, '$')));
    //   t_op_equal2.insert(ft::pair<int, char>(ft::make_pair(19, 'y')));
    //   t_op_equal2.insert(ft::pair<int, char>(ft::make_pair(9, '-')));
    //   std::cout << "Not empty tree : ";
    //   printWithIterators(t_op_equal2);
    //   t_op_equal2 = t;
    //   std::cout << "After assignment : ";
    //   printWithIterators(t_op_equal2);
    //   std::cout << "Modifying copy : ";
    //   t_op_equal2.insert(ft::pair<int, char>(ft::make_pair(18, '%')));
    //   printWithIterators(t_op_equal);
    //   std::cout << "Verify original : ";
    //   printWithIterators(t);

    //   ft::BstTree<int, char> t_op_copy(t);
    //   std::cout << BOLDBLUE "*** Copy constructor *** : " END << std::endl
    //             << std::endl;
    //   std::cout << "Copy : ";
    //   printWithIterators(t_op_copy);
    //   std::cout << "Modifying copy : ";
    //   t_op_copy.insert(ft::pair<int, char>(ft::make_pair(5, '@')));
    //   printWithIterators(t_op_copy);
    //   std::cout << "Verify original : ";
    //   printWithIterators(t);

    //   ft::BstTree<int, char> t_it(t.begin(), t.end());
    //   std::cout << BOLDBLUE "*** Constructor from iterators *** : " END
    //             << std::endl
    //             << std::endl;
    //   std::cout << "Newly constructed tree : ";
    //   printWithIterators(t_it);
    //   std::cout << "Modifying tree : ";
    //   t_it.insert(ft::pair<int, char>(ft::make_pair(5, '@')));
    //   printWithIterators(t_it);
    //   std::cout << "Verify original : ";
    //   printWithIterators(t);
    //   std::cout << BOLDRED "Erase begin:" END << std::endl;
    //   t.erase(t.begin());
    //   printWithIterators(t);

    //   ft::BstTree<int, char> t_equal = t;
    //   std::cout << (t_equal == t ? "Equal" : "Not equal") << std::endl;
    //   std::cout << (t_equal == t_it ? "Equal" : "Not equal") << std::endl;

    //   std::cout << "Swap:" << std::endl;
    //   std::cout << "t1 : ";
    //   printWithIterators(t_equal);
    //   std::cout << "t2 : ";
    //   printWithIterators(t_it);
    //   t_equal.swap(t_it);
    //   std::cout << "SWAP" << std::endl << "t1 : ";
    //   printWithIterators(t_equal);
    //   std::cout << "t2 : ";
    //   printWithIterators(t_it);
    //   std::cout << "Modif after Swap:" << std::endl;
    //   t_equal.insert(ft::pair<int, char>(ft::make_pair(0, '$')));
    //   std::cout << "t1 : ";
    //   printWithIterators(t_equal);
    //   std::cout << "t2 : ";
    //   printWithIterators(t_it);
  }
}
