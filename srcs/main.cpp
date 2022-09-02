
#include <exception>
#include <iostream>
#include <iterator>
#include <string>

#include "Chrono.hpp"
#include "make_pair.hpp"
#include "tests_utils.hpp"

// void print_int_ftvector(ft::vector<int> v) {
//   std::cout << BLUE "Size " END << v.size() << std::endl;
//   std::cout << BLUE "Capacity :  " END << v.capacity() << std::endl;
//   std::cout << BLUE "Content : " END;
//   if (v.empty()) return;

//   for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " <<
//   v[i]; std::cout << " |" << std::endl;
// }
// void print_longint_ftvector(ft::vector<long int> v) {
//   std::cout << "Content : ";
//   for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " <<
//   v[i]; std::cout << " |" << std::endl;
// }
// void print_unsignedint_ftvector(ft::vector<unsigned int> v) {
//   std::cout << "Content : ";
//   for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " <<
//   v[i]; std::cout << " |" << std::endl;
// }
// void print_str_ftvector(ft::vector<std::string> v) {
//   std::cout << "Content : ";
//   for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " <<
//   v[i]; std::cout << " |" << std::endl;
// }

// int main(void) {
//   Chrono chrono = Chrono("Small vector functions", "Large vector");
//   chrono.begin();
//   // std::cout << std::endl
//   //           << BOLDMAGENTA "----- My vector -----" END << std::endl;
//   { /* Constructor empty vector => ok */
//     std::cout << BOLDGREEN "******* Vector *******" END << std::endl;

//     std::cout << BOLDCYAN "Default constructor - empty vector" END <<
//     std::endl; ft::vector<int> v = ft::vector<int>(); print_int_ftvector(v);
//     std::cout << CYAN "Max size : " END << v.max_size() << std::endl;
//     std::cout << BOLDCYAN "Push back : " END << std::endl;
//     v.push_back(1);
//     std::cout << "Access [0] : " << v[0] << std::endl;
//     v.push_back(2);
//     print_int_ftvector(v);
//     std::cout << v[1] << std::endl;
//     v.push_back(3);
//     print_int_ftvector(v);
//     v.push_back(4);
//     print_int_ftvector(v);
//     v.push_back(5);
//     print_int_ftvector(v);
//     v.push_back(6);
//     print_int_ftvector(v);
//     v.push_back(7);
//     print_int_ftvector(v);
//     v.push_back(8);
//     print_int_ftvector(v);
//     v.push_back(9);
//     print_int_ftvector(v);
//     std::cout << CYAN "Back : " END << v.back() << std::endl;
//     std::cout << BOLDCYAN "Pop back" END << std::endl;
//     v.pop_back();
//     print_int_ftvector(v);

//     std::cout << CYAN "Back : " END << v.back() << std::endl;
//     std::cout << CYAN "Front : " END << v.front() << std::endl;

//     std::cout << BOLDCYAN "At" END << std::endl;
//     std::cout << "At 1 : " << v.at(1) << std::endl;
//     try {
//       std::cout << "At 80 : " << v.at(80) << std::endl;
//     } catch (std::exception& e) {
//       std::cout << "Exception caught" << std::endl;
//     }

//     std::cout << BOLDCYAN "Begin : " END << *v.begin() << std::endl;

//     std::cout << BOLDCYAN "Resize 15 with 1: " END << std::endl;
//     v.resize(15, 1);
//     print_int_ftvector(v);

//     std::cout << BOLDCYAN "Resize 20 with nothing: " END << std::endl;
//     v.resize(20);
//     print_int_ftvector(v);

//     std::cout << BOLDCYAN "reserve 30 : " END << std::endl;
//     v.reserve(30);
//     print_int_ftvector(v);
//     std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

//     std::cout << BOLDCYAN "Resize to smaller : " END << std::endl;
//     v.resize(8);
//     print_int_ftvector(v);

//     std::cout << "Iterator + : v.begin() + 2 : " << *(v.begin() + 2)
//               << std::endl;
//     std::cout << "Iterator - : v.end() - 2 : " << *(v.end() - 2) <<
//     std::endl;

//     std::cout << BOLDCYAN "Insert :" END << std::endl;

//     std::cout << "Insert one value 42 at begin: " << std::endl;
//     std::cout << "Return value : " RED << *(v.insert(v.begin(), 42)) << END
//               << std::endl;
//     print_int_ftvector(v);

//     std::cout << "Insert one value 42 at position 2: " << std::endl;
//     std::cout << "Return value : " RED << *(v.insert(v.begin() + 2, 42)) <<
//     END
//               << std::endl;
//     print_int_ftvector(v);

//     std::cout << "Insert multiple value 42 42 42 42 at position 7 : "
//               << std::endl;
//     v.insert(v.begin() + 7, 4, 42);
//     print_int_ftvector(v);

//     ft::vector<int> to_insert(3, 42);
//     to_insert[1] = 43;
//     to_insert[2] = 44;
//     std::cout << "Insert vector 42 43 44: " << std::endl;
//     v.insert(v.begin() + 4, to_insert.begin(), to_insert.end());
//     print_int_ftvector(v);

//     std::cout << BOLDCYAN "Erase" END << std::endl;
//     std::cout << CYAN "Erase position 2 : " END << std::endl;
//     std::cout << "Return value : " RED << *(v.erase(v.begin() + 2)) << END
//               << std::endl;
//     print_int_ftvector(v);

//     std::cout << CYAN "Erase begin : " END << std::endl;
//     std::cout << "Return value : " RED << *(v.erase(v.begin())) << END
//               << std::endl;
//     print_int_ftvector(v);

//     std::cout << CYAN "Erase from 2 to 5 (excluding 5): " END << std::endl;
//     std::cout << "Return value : " RED
//               << *(v.erase(v.begin() + 2, v.begin() + 5)) << END <<
//               std::endl;
//     print_int_ftvector(v);

//     std::cout << CYAN "Erase from 5 to 9 (excluding 9): " END << std::endl;
//     std::cout << "Return value : " RED
//               << *(v.erase(v.begin() + 5, v.begin() + 9)) << END <<
//               std::endl;
//     print_int_ftvector(v);

//     std::cout << "Adress of v : " << &v << std::endl;
//     std::cout << "Adress of other : " << &to_insert << std::endl;
//     std::cout << BOLDCYAN "Swap with 42 43 44" END << std::endl;
//     v.swap(to_insert);
//     std::cout << "Adress of v : " << &v << std::endl;
//     std::cout << "New vector : ";
//     print_int_ftvector(v);
//     std::cout << "Other vector : " << std::endl;
//     std::cout << "Adress of other : " << &to_insert << std::endl;
//     print_int_ftvector(to_insert);

//     std::cout << BOLDCYAN "Clear" END << std::endl;
//     v.clear();
//     print_int_ftvector(v);
//     std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

//     ft::vector<int> to_assign;

//     to_assign.push_back(5);
//     to_assign.push_back(4);
//     to_assign.push_back(3);
//     to_assign.push_back(2);
//     to_assign.push_back(1);

//     std::cout << BOLDCYAN "Assign on empty vector: " END << std::endl;
//     std::cout << "on empty vector with other vector 5 4 3 2 1 (5 values): "
//               << std::endl;
//     v.assign(to_assign.begin(), to_assign.begin() + 5);
//     print_int_ftvector(v);

//     std::cout << "on not empty vector with other vector 5 4 3 2 1 (2 values):
//     "
//               << std::endl;
//     v.assign(to_assign.begin(), to_assign.begin() + 2);
//     print_int_ftvector(v);

//     std::cout << "on not empty vector with value 42 (5 values): " <<
//     std::endl; v.assign(5, 42); print_int_ftvector(v);

//     std::cout << BOLDCYAN "Reverse iterator" END << std::endl;
//     ft::vector<int> myvector;  // 5 default-constructed ints
//     myvector.push_back(1);
//     myvector.push_back(2);
//     myvector.push_back(3);
//     myvector.push_back(4);
//     myvector.push_back(5);
//     std::cout << "My vector : " << std::endl;
//     print_int_ftvector(myvector);

//     std::cout << "Printing vector with iterator : " << std::endl;
//     for (ft::vector<int>::iterator it = myvector.begin(); it !=
//     myvector.end();
//          ++it) {
//       std::cout << *it << std::endl;
//     }  // ok

//     std::cout << "Reverse printing vector with iterator : " << std::endl;
//     for (ft::vector<int>::iterator it = myvector.end(); it !=
//     myvector.begin();
//          --it) {
//       std::cout << *(it - 1) << std::endl;
//     }  // ok

//     std::cout << "Printing vector with reverse iterator : " << std::endl;
//     std::cout << "End adress : " << &*(myvector.end()) << std::endl;
//     std::cout << "Rbegin adress : " << &*(myvector.rbegin()) << std::endl;
//     for (ft::vector<int>::reverse_iterator it = myvector.rend();
//          it != myvector.rbegin(); --it) {
//       std::cout << *(it - 1) << std::endl;
//     }
//     std::cout << "Reverse printing vector with reverse iterator : "
//               << std::endl;
//     for (ft::vector<int>::reverse_iterator it = myvector.rbegin();
//          it != myvector.rend(); ++it) {
//       std::cout << *it << std::endl;
//     }

//     std::cout << std::endl;
//     /* Operateur d'affectation */
//     ft::vector<int> cpy;
//     cpy = v;
//     std::cout << BOLDCYAN "Affectation operator : " END << std::endl;
//     print_int_ftvector(cpy);
//     cpy[0] = 100;
//     print_int_ftvector(cpy);
//     std::cout << "Verifying original : " << std::endl;
//     print_int_ftvector(v);
//     std::cout << std::endl;

//     /* Constructeur de recopie */
//     std::cout << BOLDCYAN "Copy constructor : " END << std::endl;
//     ft::vector<int> cpy2(v);
//     print_int_ftvector(cpy2);
//     cpy2[0] = 200;
//     print_int_ftvector(cpy2);
//     std::cout << "Verifying original : " << std::endl;
//     print_int_ftvector(v);
//   }

//   /***** Constructor vector(nb elem) *****/
//   {
//     std::cout << BOLDCYAN "Vector of 4 int without value : " END <<
//     std::endl; ft::vector<int> v = ft::vector<int>(4); print_int_ftvector(v);
//     v[0] = 1;
//     print_int_ftvector(v);
//   }

//   /***** Constructor vector(nb elem, value) *****/
//   {
//     std::cout << BOLDCYAN "Vector of 10 unsigned int with value 42 : " END
//               << std::endl;
//     unsigned int i = 42;
//     ft::vector<unsigned int> v = ft::vector<unsigned int>(10, i);
//     std::cout << v.size() << std::endl;
//     std::cout << v.max_size() << std::endl;
//     std::cout << v.capacity() << std::endl;
//     print_unsignedint_ftvector(v);
//   }
//   {
//     std::cout << BOLDCYAN "Vector of 10 int with value 42 : " END <<
//     std::endl; int i = 42; ft::vector<int> v = ft::vector<int>(10, i);
//     print_int_ftvector(v);
//   }
//   {
//     std::cout << BOLDCYAN "Vector of 10 string with value bla : " END
//               << std::endl;
//     ft::vector<std::string> v = ft::vector<std::string>(10, "bla");
//     print_str_ftvector(v);
//   }
//   // TODO
//   /*****Iterator constructor *****/
//   {
//     std::cout << BOLDCYAN "Constructor using iterators :" END << std::endl;

//     ft::vector<int> v = ft::vector<int>(3, 1);
//     ft::vector<int> my_v(v.begin(), v.end());
//     print_int_ftvector(v);
//     print_int_ftvector(my_v);
//     my_v[0] = 42;
//     print_int_ftvector(v);
//     print_int_ftvector(my_v);
//   }
//   chrono.stop();

//   std::cout << BOLDCYAN "Performance - vector of 1000000 int" END <<
//   std::endl; std::cout << "Large vector : " << std::endl; ft::vector<int>
//   large_v = ft::vector<int>(1000000, 42); large_v.push_back(1);
//   large_v.pop_back();
//   std::cout << "Accessor : " << large_v[888888] << std::endl;
//   std::cout << "At : " << large_v.at(500000) << std::endl;
//   std::cout << "Size : " << large_v.size() << std::endl;
//   std::cout << "Begin : " << *large_v.begin() << std::endl;
//   large_v.insert(large_v.begin() + 500000, 43);
//   std::cout << "insert at 500000 : " << large_v[500000] << std::endl;
//   large_v.erase(large_v.begin() + 500000);
//   std::cout << "insert at 500000 : " << large_v[500000] << std::endl;

//   ft::vector<int> large_v_swap = ft::vector<int>(999999, 41);
//   large_v.swap(large_v_swap);
//   std::cout << "After swap with 999999 vector of 41 :" << std::endl
//             << "Accessor :" << large_v[450000] << std::endl
//             << "Size : " << large_v.size() << std::endl;
//   std::cout << "Other swapped vector :" << std::endl
//             << "Accessor :" << large_v_swap[450000] << std::endl
//             << "Size : " << large_v_swap.size() << std::endl;

//   chrono.stop();
//   {
//     std::cout << BOLDCYAN "Comparison operators : non member functions" END
//               << std::endl;
//     ft::vector<std::string> v1 = ft::vector<std::string>(3, "bla");
//     ft::vector<std::string> v2 = ft::vector<std::string>(3, "bla");
//     std::cout << "Equal : " << (v1 == v2 ? "Equal" : "Not equal") <<
//     std::endl; std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") <<
//     std::endl; std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False") <<
//     std::endl; v2.push_back("bla"); std::cout << "Not Equal (size): " << (v1
//     == v2 ? "Equal" : "Not equal")
//               << std::endl;
//     std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") << std::endl;
//     std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False") << std::endl;

//     v2.pop_back();
//     std::cout << "Equal : " << (v1 == v2 ? "Equal" : "Not equal") <<
//     std::endl;

//     v2[0] = "bli";
//     std::cout << "Not Equal (content): " << (v1 == v2 ? "Equal" : "Not
//     equal")
//               << std::endl;
//     std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False") << std::endl;

//     std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") << std::endl;
//     std::cout << "v1 > v2 " << (v1 > v2 ? "True" : "False") << std::endl;
//     std::cout << "v1 <= v2 " << (v1 <= v2 ? "True" : "False") << std::endl;
//     std::cout << "v1 >= v2 " << (v1 >= v2 ? "True" : "False") << std::endl;
//   }

//   {
//     std::cout << BOLDCYAN "Testing vector with custom complex type : " END
//               << std::endl;
//     complex test_complex = complex();
//     ft::vector<complex> v_complex = ft::vector<complex>(3, test_complex);
//     v_complex.push_back(test_complex);
//     print_ftcomplex(v_complex);
//   }
//   {
//     std::cout << BOLDGREEN "******* Pair & makepair *******" << END
//               << std::endl;
//     ft::pair<int, int> p1 = ft::make_pair(1, 2);

//     std::cout << "First : " << p1.first << std::endl
//               << "Second : " << p1.second << std::endl;

//     ft::pair<int, int> p2 = ft::make_pair(3, 4);
//     std::cout << "(1, 2) < (3, 4)? " << ((p1 < p2) ? "True" : "False")
//               << std::endl;
//     ft::pair<int, int> p3 = ft::make_pair(1, 2);
//     std::cout << "(1, 2) > (1, 2)? " << ((p3 > p1) ? "True" : "False")
//               << std::endl;

//     std::cout << "(1, 2) == (1, 2)? " << ((p3 == p1) ? "True" : "False")
//               << std::endl;
//   }
// }

int main(void) {
  /* *************** PERFORMANCE TESTS **************** */  // OK
  {
      // std::cout << BOLDBLUE "Performance test : " END << std::endl;
      // // "Vector of 10 000 000 - Push - Pop - Insert - Erase - Swap"
      // Chrono chrono = Chrono("My vector", "Std vector");
      // chrono.begin();
      // ft::vector<int> my_large_v = ft::vector<int>(10000000, 42);
      // my_large_v.push_back(1);
      // my_large_v.pop_back();
      // my_large_v.insert(my_large_v.begin() + 500000, 43);
      // my_large_v.erase(my_large_v.begin() + 500000);
      // my_large_v.insert(my_large_v.begin() + 400000, 100000, 43);
      // my_large_v.erase(my_large_v.begin() + 400000, my_large_v.begin() +
      // 500000); ft::vector<int> my_large_v_swap = ft::vector<int>(999999, 41);
      // my_large_v.swap(my_large_v_swap);
      // chrono.stop();
      // std::vector<int> large_v = std::vector<int>(10000000, 42);
      // large_v.push_back(1);
      // large_v.pop_back();
      // large_v.insert(large_v.begin() + 500000, 43);
      // large_v.erase(large_v.begin() + 500000);
      // large_v.insert(large_v.begin() + 400000, 100000, 43);
      // large_v.erase(large_v.begin() + 400000, large_v.begin() + 500000);
      // std::vector<int> large_v_swap = std::vector<int>(999999, 41);
      // large_v.swap(large_v_swap);
      // chrono.stop();
      // printDiffVector(my_large_v, large_v);
  }

  /* *************** CONSTRUCTOR AND ASSIGNMENT TESTS **************** */
  {
    std::cout << std::endl << BOLDBLUE "Constructor tests : " END << std::endl;
    ft::vector<int> my_v1 = ft::vector<int>();
    ft::vector<int> my_v2 = ft::vector<int>(5);
    ft::vector<int> my_v3 = ft::vector<int>(5, 42);
    ft::vector<std::string> my_v4 = ft::vector<std::string>(5, "bla");
    ft::vector<int> my_v5 = ft::vector<int>(my_v3.begin(), my_v3.begin() + 2);
    ft::vector<int> my_v6 = ft::vector<int>(my_v3);
    ft::vector<int> my_v7 = my_v6;  // NOLINT
    ft::vector<int> my_v8 = ft::vector<int>(10, 42);
    my_v8.assign(my_v3.begin(), my_v3.begin() + 2);
    ft::vector<int> my_v9 = ft::vector<int>(10, 42);
    my_v9.assign(5, 43);

    std::vector<int> v1 = std::vector<int>();
    std::vector<int> v2 = std::vector<int>(5);
    std::vector<int> v3 = std::vector<int>(5, 42);
    std::vector<std::string> v4 = std::vector<std::string>(5, "bla");
    std::vector<int> v5 = std::vector<int>(v3.begin(), v3.begin() + 2);
    std::vector<int> v6 = std::vector<int>(v3);
    std::vector<int> v7 = v6;  // NOLINT
    std::vector<int> v8 = std::vector<int>(10, 42);
    v8.assign(v3.begin(), v3.begin() + 2);
    std::vector<int> v9 = std::vector<int>(10, 42);
    v9.assign(5, 43);

    printDiffVector(my_v1, v1);
    printDiffVector(my_v2, v2);
    printDiffVector(my_v3, v3);
    printDiffVector(my_v4, v4);
    printDiffVector(my_v5, v5);
    printDiffVector(my_v6, v6);
    printDiffVector(my_v7, v7);
    printDiffVector(my_v8, v8);
    printDiffVector(my_v9, v9);
  }
  /* *************** ITERATORS **************** */
  {
    std::cout << std::endl
              << std::endl
              << BOLDBLUE "Iterators :" END << std::endl;
    ft::vector<int> my_v;
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::string my_buffer;
    std::string buffer;
    std::cout << "Pre incrementation : ";
    for (ft::vector<int>::iterator it = my_v.begin(); it != my_v.end(); ++it) {
      my_buffer += std::to_string(*it);
      my_buffer += " ";
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
      buffer += std::to_string(*it);
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    my_buffer = "";
    buffer = "";
    std::cout << std::endl << "Post incrementation : ";
    for (ft::vector<int>::iterator it = my_v.begin(); it != my_v.end(); it++) {
      my_buffer += std::to_string(*it);
      my_buffer += " ";
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      buffer += std::to_string(*it);
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    my_buffer = "";
    buffer = "";
    std::cout << std::endl << "Pre decrementation : ";
    for (ft::vector<int>::iterator it = my_v.end(); it != my_v.begin(); --it) {
      my_buffer += std::to_string(*(it - 1));
      my_buffer += " ";
    }
    for (std::vector<int>::iterator it = v.end(); it != v.begin(); --it) {
      buffer += std::to_string(*(it - 1));
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    std::cout << std::endl << "Post decrementation : ";
    for (ft::vector<int>::iterator it = my_v.end(); it != my_v.begin(); it--) {
      my_buffer += std::to_string(*(it - 1));
      my_buffer += " ";
    }
    for (std::vector<int>::iterator it = v.end(); it != v.begin(); it--) {
      buffer += std::to_string(*(it - 1));
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    std::cout << std::endl << "Addition : ";
    if (*(my_v.begin() + 2) == *(v.begin() + 2))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    ft::vector<int>::iterator my_it = my_v.begin();
    my_it += 2;
    std::vector<int>::iterator it = v.begin();
    it += 2;
    if (*(my_it) == *(it))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
    std::cout << std::endl << "Substraction : ";
    if (*(my_v.end() - 2) == *(v.end() - 2))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    my_it -= 1;
    it -= 1;
    if (*(my_it) == *(it))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
  }

  /* *************** REVERSE ITERATORS **************** */
  {
    std::cout << std::endl
              << std::endl
              << BOLDBLUE "Reverse iterators :" END << std::endl;
    ft::vector<int> my_v;
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::string my_buffer;
    std::string buffer;
    std::cout << "Pre incrementation : ";
    for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
         it != my_v.rend(); ++it) {
      my_buffer += std::to_string(*it);
      my_buffer += " ";
    }
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();
         ++it) {
      buffer += std::to_string(*it);
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    my_buffer = "";
    buffer = "";
    std::cout << std::endl << "Post incrementation : ";
    for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
         it != my_v.rend(); it++) {
      my_buffer += std::to_string(*it);
      my_buffer += " ";
    }
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend();
         it++) {
      buffer += std::to_string(*it);
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    my_buffer = "";
    buffer = "";
    std::cout << std::endl << "Pre decrementation : ";
    for (ft::vector<int>::reverse_iterator it = my_v.rend();
         it != my_v.rbegin(); --it) {
      my_buffer += std::to_string(*(it - 1));
      my_buffer += " ";
    }
    for (std::vector<int>::reverse_iterator it = v.rend(); it != v.rbegin();
         --it) {
      buffer += std::to_string(*(it - 1));
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    std::cout << std::endl << "Post decrementation : ";
    for (ft::vector<int>::reverse_iterator it = my_v.rend();
         it != my_v.rbegin(); it--) {
      my_buffer += std::to_string(*(it - 1));
      my_buffer += " ";
    }
    for (std::vector<int>::reverse_iterator it = v.rend(); it != v.rbegin();
         it--) {
      buffer += std::to_string(*(it - 1));
      buffer += " ";
    }
    if (buffer == my_buffer)
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;

    std::cout << std::endl << "Addition : ";
    if (*(my_v.rbegin() + 2) == *(v.rbegin() + 2))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    ft::vector<int>::reverse_iterator my_it = my_v.rbegin();
    my_it += 2;
    std::vector<int>::reverse_iterator it = v.rbegin();
    it += 2;
    if (*(my_it) == *(it))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
    std::cout << std::endl << "Substraction : ";
    if (*(my_v.rend() - 2) == *(v.rend() - 2))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    my_it -= 1;
    it -= 1;
    if (*(my_it) == *(it))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
  }

  /**************** CAPACITY *****************/
  {
    std::cout << std::endl
              << std::endl
              << BOLDBLUE "Capacity :" END << std::endl;

    ft::vector<int> my_v;
    std::vector<int> v;
    v.push_back(1);
    my_v.push_back(1);
    my_v.push_back(2);
    v.push_back(2);
    printDiffVector(my_v, v);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    printDiffVector(my_v, v);
    my_v.resize(50);
    v.resize(50);
    printDiffVector(my_v, v);
    my_v.resize(3);
    v.resize(3);
    my_v.reserve(2);
    v.reserve(2);
    printDiffVector(my_v, v);
    v.reserve(80);
    my_v.reserve(80);
    if (my_v.empty() == v.empty())
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
    ft::vector<int> my_v_empty;
    std::vector<int> v_empty;
    if (my_v_empty.empty() == v_empty.empty())
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO" END;
  }

  /* *************** ACCESS **************** */
  {
    std::cout << std::endl << std::endl << BOLDBLUE "Access :" END << std::endl;
    ft::vector<int> my_v;
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    if (my_v[0] == v[0])
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    v[1] = 42;
    my_v[1] = 42;
    if (my_v[1] == v[1])
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;

    if (my_v.at(3) == v.at(3))
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;

    // exception test
    bool success = false;
    try {
      my_v.at(80);  // NOLINT
      std::cout << BOLDRED "KO " END;
    } catch (std::exception& e) {
      success = true;
    }
    try {
      v.at(80);  // NOLINT
      std::cout << BOLDRED "KO " END;
    } catch (std::exception& e) {
      if (success) std::cout << BOLDGREEN "OK " END;
    }

    if (my_v.front() == v.front())
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
    if (my_v.back() == v.back())
      std::cout << BOLDGREEN "OK " END;
    else
      std::cout << BOLDRED "KO " END;
  }

  /* *************** MODIFIERS **************** */
  {
    std::cout << std::endl
              << std::endl
              << BOLDBLUE "Modifiers :" END << std::endl;
    ft::vector<int> my_v;
    my_v.push_back(1);
    my_v.push_back(2);
    my_v.push_back(3);
    my_v.push_back(4);
    my_v.push_back(5);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    ft::vector<int> my_v_insert;
    my_v_insert.push_back(1);
    my_v_insert.push_back(2);
    my_v_insert.push_back(3);

    std::vector<int> v_insert;
    v_insert.push_back(1);
    v_insert.push_back(2);
    v_insert.push_back(3);

    printDiffVector(my_v, v);
    my_v.pop_back();
    v.pop_back();
    printDiffVector(my_v, v);

    my_v.insert(my_v.begin(), 0);
    v.insert(v.begin(), 0);
    printDiffVector(my_v, v);

    my_v.insert(my_v.begin() + 2, 0);
    v.insert(v.begin() + 2, 0);
    printDiffVector(my_v, v);

    my_v.insert(my_v.begin() + 2, 5, 42);
    v.insert(v.begin() + 2, 5, 42);
    printDiffVector(my_v, v);

    my_v.insert(my_v.begin() + 2, my_v_insert.begin(), my_v_insert.end());
    v.insert(v.begin() + 2, v_insert.begin(), v_insert.end());
    printDiffVector(my_v, v);

    my_v.erase(my_v.begin() + 4);
    v.erase(v.begin() + 4);
    printDiffVector(my_v, v);

    my_v.erase(my_v.begin() + 2, my_v.begin() + 4);
    v.erase(v.begin() + 2, v.begin() + 4);
    printDiffVector(my_v, v);

    my_v.swap(my_v_insert);
    v.swap(v_insert);
    printDiffVector(my_v, v);
    printDiffVector(my_v_insert, v_insert);

    my_v.clear();
    v.clear();
    printDiffVector(my_v, v);
  }

  /* ***************** NON MEMBER FUNCTIONS ****************** */

  //
  //   {
  //     std::cout << BOLDCYAN "Comparison operators : non member functions"
  //     END
  //               << std::endl;
  //     ft::vector<std::string> v1 = ft::vector<std::string>(3, "bla");
  //     ft::vector<std::string> v2 = ft::vector<std::string>(3, "bla");
  //     std::cout << "Equal : " << (v1 == v2 ? "Equal" : "Not equal") <<
  //     std::endl; std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") <<
  //     std::endl; std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False")
  //     << std::endl; v2.push_back("bla"); std::cout << "Not Equal (size): "
  //     << (v1 == v2 ? "Equal" : "Not equal")
  //               << std::endl;
  //     std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") << std::endl;
  //     std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False") <<
  //     std::endl;

  //     v2.pop_back();
  //     std::cout << "Equal : " << (v1 == v2 ? "Equal" : "Not equal") <<
  //     std::endl;

  //     v2[0] = "bli";
  //     std::cout << "Not Equal (content): " << (v1 == v2 ? "Equal" : "Not
  //     equal")
  //               << std::endl;
  //     std::cout << "v1 != v2 " << (v1 != v2 ? "True" : "False") <<
  //     std::endl;

  //     std::cout << "v1 < v2 " << (v1 < v2 ? "True" : "False") << std::endl;
  //     std::cout << "v1 > v2 " << (v1 > v2 ? "True" : "False") << std::endl;
  //     std::cout << "v1 <= v2 " << (v1 <= v2 ? "True" : "False") <<
  //     std::endl; std::cout << "v1 >= v2 " << (v1 >= v2 ? "True" : "False")
  //     << std::endl;
  //   }

  //   {
  //     std::cout << BOLDCYAN "Testing vector with custom complex type : "
  //     END
  //               << std::endl;
  //     complex test_complex = complex();
  //     ft::vector<complex> v_complex = ft::vector<complex>(3, test_complex);
  //     v_complex.push_back(test_complex);
  //     print_ftcomplex(v_complex);
  //   }
  //   {
  //     std::cout << BOLDGREEN "******* Pair & makepair *******" << END
  //               << std::endl;
  //     ft::pair<int, int> p1 = ft::make_pair(1, 2);

  //     std::cout << "First : " << p1.first << std::endl
  //               << "Second : " << p1.second << std::endl;

  //     ft::pair<int, int> p2 = ft::make_pair(3, 4);
  //     std::cout << "(1, 2) < (3, 4)? " << ((p1 < p2) ? "True" : "False")
  //               << std::endl;
  //     ft::pair<int, int> p3 = ft::make_pair(1, 2);
  //     std::cout << "(1, 2) > (1, 2)? " << ((p3 > p1) ? "True" : "False")
  //               << std::endl;

  //     std::cout << "(1, 2) == (1, 2)? " << ((p3 == p1) ? "True" : "False")
  //               << std::endl;
  //   }
}

// to test guarantee : create class which throws in constructor / destructor /
// randomly in constructor