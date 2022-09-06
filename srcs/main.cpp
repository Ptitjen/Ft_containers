
#include <exception>
#include <iostream>
#include <iterator>
#include <string>

#include "Chrono.hpp"
#include "make_pair.hpp"
#include "tests_utils.hpp"
#include "vector.hpp"

int main(void) {
  /* ********************** VECTOR *********************** */
  std::cout << BOLDMAGENTA "*********** VECTOR **********" END << std::endl;
  {
    // /* *************** PERFORMANCE TESTS **************** */  // OK
    // {
    //   std::cout << BOLDBLUE "Performance test : " END << std::endl;
    //   // "Vector of 10 000 000 - Push - Pop - Insert - Erase - Swap"
    //   Chrono chrono = Chrono("My vector", "Std vector");
    //   chrono.begin();
    //   ft::vector<int> my_large_v = ft::vector<int>(10000000, 42);
    //   ft::vector<int> my_large_v2 = ft::vector<int>(10000000, 41);

    //   my_large_v.push_back(1);
    //   my_large_v.pop_back();
    //   my_large_v.insert(my_large_v.begin() + 500000, 43);
    //   my_large_v.erase(my_large_v.begin() + 500000);
    //   my_large_v.insert(my_large_v.begin() + 400000, 100000, 43);
    //   my_large_v.insert(my_large_v.begin() + 5000000, my_large_v2.begin(),
    //                     my_large_v2.end());

    //   my_large_v.erase(my_large_v.begin() + 400000,
    //                    my_large_v.begin() + 500000);
    //   ft::vector<int> my_large_v_swap = ft::vector<int>(999999, 41);
    //   my_large_v.swap(my_large_v_swap);
    //   chrono.stop();
    //   std::vector<int> large_v = std::vector<int>(10000000, 42);
    //   std::vector<int> large_v2 = std::vector<int>(10000000, 41);
    //   large_v.push_back(1);
    //   large_v.pop_back();
    //   large_v.insert(large_v.begin() + 500000, 43);
    //   large_v.erase(large_v.begin() + 500000);
    //   large_v.insert(large_v.begin() + 400000, 100000, 43);
    //   large_v.insert(large_v.begin() + 5000000, large_v2.begin(),
    //                  large_v2.end());
    //   large_v.erase(large_v.begin() + 400000, large_v.begin() + 500000);
    //   std::vector<int> large_v_swap = std::vector<int>(999999, 41);
    //   large_v.swap(large_v_swap);
    //   chrono.stop();
    //   printDiffVector(my_large_v, large_v);
    // }

    // /* *************** CONSTRUCTOR AND ASSIGNMENT TESTS **************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Constructor tests : " END << std::endl;
    //   ft::vector<int> my_v1 = ft::vector<int>();
    //   ft::vector<int> my_v2 = ft::vector<int>(5);
    //   ft::vector<int> my_v3 = ft::vector<int>(5, 42);
    //   ft::vector<std::string> my_v4 = ft::vector<std::string>(5, "bla");
    //   ft::vector<int> my_v5 = ft::vector<int>(my_v3.begin(), my_v3.begin() +
    //   2); ft::vector<int> my_v6 = ft::vector<int>(my_v3); ft::vector<int>
    //   my_v7 = my_v6;  // NOLINT ft::vector<int> my_v8 = ft::vector<int>(10,
    //   42); my_v8.assign(my_v3.begin(), my_v3.begin() + 2); ft::vector<int>
    //   my_v9 = ft::vector<int>(10, 42); my_v9.assign(5, 43);

    //   std::vector<int> v1 = std::vector<int>();
    //   std::vector<int> v2 = std::vector<int>(5);
    //   std::vector<int> v3 = std::vector<int>(5, 42);
    //   std::vector<std::string> v4 = std::vector<std::string>(5, "bla");
    //   std::vector<int> v5 = std::vector<int>(v3.begin(), v3.begin() + 2);
    //   std::vector<int> v6 = std::vector<int>(v3);
    //   std::vector<int> v7 = v6;  // NOLINT
    //   std::vector<int> v8 = std::vector<int>(10, 42);
    //   v8.assign(v3.begin(), v3.begin() + 2);
    //   std::vector<int> v9 = std::vector<int>(10, 42);
    //   v9.assign(5, 43);

    //   printDiffVector(my_v1, v1);
    //   printDiffVector(my_v2, v2);
    //   printDiffVector(my_v3, v3);
    //   printDiffVector(my_v4, v4);
    //   printDiffVector(my_v5, v5);
    //   printDiffVector(my_v6, v6);
    //   printDiffVector(my_v7, v7);
    //   printDiffVector(my_v8, v8);
    //   printDiffVector(my_v9, v9);
    // }

    // /* *************** CUSTOM CLASS **************** */

    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Custom complex type : " END << std::endl;
    //   bli test_complex = bli();
    //   ft::vector<bli> my_v_complex = ft::vector<bli>(3, test_complex);
    //   my_v_complex.push_back(test_complex);
    //   std::vector<bli> v_complex = std::vector<bli>(3, test_complex);
    //   v_complex.push_back(test_complex);
    //   printDiffVector(my_v_complex, v_complex);
    // }

    // /* *************** ITERATORS **************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Iterators :" END << std::endl;
    //   ft::vector<int> my_v;
    //   my_v.push_back(1);
    //   my_v.push_back(2);
    //   my_v.push_back(3);
    //   my_v.push_back(4);
    //   my_v.push_back(5);

    //   std::vector<int> v;
    //   v.push_back(1);
    //   v.push_back(2);
    //   v.push_back(3);
    //   v.push_back(4);
    //   v.push_back(5);

    //   std::string my_buffer;
    //   std::string buffer;
    //   std::cout << "Pre incrementation : ";
    //   for (ft::vector<int>::iterator it = my_v.begin(); it != my_v.end();
    //        ++it) {
    //     my_buffer += std::to_string(*it);
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //     buffer += std::to_string(*it);
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   my_buffer = "";
    //   buffer = "";
    //   std::cout << std::endl << "Post incrementation : ";
    //   for (ft::vector<int>::iterator it = my_v.begin(); it != my_v.end();
    //        it++) {
    //     my_buffer += std::to_string(*it);
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    //     buffer += std::to_string(*it);
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   my_buffer = "";
    //   buffer = "";
    //   std::cout << std::endl << "Pre decrementation : ";
    //   for (ft::vector<int>::iterator it = my_v.end(); it != my_v.begin();
    //        --it) {
    //     my_buffer += std::to_string(*(it - 1));
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::iterator it = v.end(); it != v.begin(); --it) {
    //     buffer += std::to_string(*(it - 1));
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   std::cout << std::endl << "Post decrementation : ";
    //   for (ft::vector<int>::iterator it = my_v.end(); it != my_v.begin();
    //        it--) {
    //     my_buffer += std::to_string(*(it - 1));
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::iterator it = v.end(); it != v.begin(); it--) {
    //     buffer += std::to_string(*(it - 1));
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   std::cout << std::endl << "Addition : ";
    //   if (*(my_v.begin() + 2) == *(v.begin() + 2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   ft::vector<int>::iterator my_it = my_v.begin();
    //   my_it += 2;
    //   std::vector<int>::iterator it = v.begin();
    //   it += 2;
    //   if (*(my_it) == *(it))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    //   std::cout << std::endl << "Substraction : ";
    //   if (*(my_v.end() - 2) == *(v.end() - 2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   my_it -= 1;
    //   it -= 1;
    //   if (*(my_it) == *(it))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    // }

    // /* *************** REVERSE ITERATORS **************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Reverse iterators :" END << std::endl;
    //   ft::vector<int> my_v;
    //   my_v.push_back(1);
    //   my_v.push_back(2);
    //   my_v.push_back(3);
    //   my_v.push_back(4);
    //   my_v.push_back(5);

    //   std::vector<int> v;
    //   v.push_back(1);
    //   v.push_back(2);
    //   v.push_back(3);
    //   v.push_back(4);
    //   v.push_back(5);

    //   std::string my_buffer;
    //   std::string buffer;
    //   std::cout << "Pre incrementation : ";
    //   for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
    //        it != my_v.rend(); ++it) {
    //     my_buffer += std::to_string(*it);
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::reverse_iterator it = v.rbegin(); it !=
    //   v.rend();
    //        ++it) {
    //     buffer += std::to_string(*it);
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   my_buffer = "";
    //   buffer = "";
    //   std::cout << std::endl << "Post incrementation : ";
    //   for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
    //        it != my_v.rend(); it++) {
    //     my_buffer += std::to_string(*it);
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::reverse_iterator it = v.rbegin(); it !=
    //   v.rend();
    //        it++) {
    //     buffer += std::to_string(*it);
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   my_buffer = "";
    //   buffer = "";
    //   std::cout << std::endl << "Pre decrementation : ";
    //   for (ft::vector<int>::reverse_iterator it = my_v.rend();
    //        it != my_v.rbegin(); --it) {
    //     my_buffer += std::to_string(*(it - 1));
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::reverse_iterator it = v.rend(); it !=
    //   v.rbegin();
    //        --it) {
    //     buffer += std::to_string(*(it - 1));
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   std::cout << std::endl << "Post decrementation : ";
    //   for (ft::vector<int>::reverse_iterator it = my_v.rend();
    //        it != my_v.rbegin(); it--) {
    //     my_buffer += std::to_string(*(it - 1));
    //     my_buffer += " ";
    //   }
    //   for (std::vector<int>::reverse_iterator it = v.rend(); it !=
    //   v.rbegin();
    //        it--) {
    //     buffer += std::to_string(*(it - 1));
    //     buffer += " ";
    //   }
    //   if (buffer == my_buffer)
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;

    //   std::cout << std::endl << "Addition : ";
    //   if (*(my_v.rbegin() + 2) == *(v.rbegin() + 2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   ft::vector<int>::reverse_iterator my_it = my_v.rbegin();
    //   my_it += 2;
    //   std::vector<int>::reverse_iterator it = v.rbegin();
    //   it += 2;
    //   if (*(my_it) == *(it))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    //   std::cout << std::endl << "Substraction : ";
    //   if (*(my_v.rend() - 2) == *(v.rend() - 2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   my_it -= 1;
    //   it -= 1;
    //   if (*(my_it) == *(it))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    // }

    // /**************** CAPACITY *****************/
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Capacity :" END << std::endl;

    //   ft::vector<int> my_v;
    //   std::vector<int> v;
    //   v.push_back(1);
    //   my_v.push_back(1);
    //   my_v.push_back(2);
    //   v.push_back(2);
    //   printDiffVector(my_v, v);
    //   my_v.push_back(3);
    //   my_v.push_back(4);
    //   my_v.push_back(5);
    //   v.push_back(3);
    //   v.push_back(4);
    //   v.push_back(5);
    //   printDiffVector(my_v, v);
    //   my_v.resize(50);
    //   v.resize(50);
    //   my_v.push_back(2);
    //   v.push_back(2);
    //   printDiffVector(my_v, v);
    //   my_v.resize(3);
    //   v.resize(3);
    //   my_v.reserve(2);
    //   v.reserve(2);
    //   printDiffVector(my_v, v);
    //   v.reserve(80);
    //   my_v.reserve(80);
    //   my_v.push_back(2);
    //   v.push_back(2);
    //   printDiffVector(my_v, v);
    //   if (my_v.empty() == v.empty())
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    //   ft::vector<int> my_v_empty;
    //   std::vector<int> v_empty;
    //   if (my_v_empty.empty() == v_empty.empty())
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO" END;
    // }

    // /* *************** ACCESS **************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Access :" END << std::endl;
    //   ft::vector<int> my_v;
    //   my_v.push_back(1);
    //   my_v.push_back(2);
    //   my_v.push_back(3);
    //   my_v.push_back(4);
    //   my_v.push_back(5);

    //   std::vector<int> v;
    //   v.push_back(1);
    //   v.push_back(2);
    //   v.push_back(3);
    //   v.push_back(4);
    //   v.push_back(5);

    //   if (my_v[0] == v[0])
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   v[1] = 42;
    //   my_v[1] = 42;
    //   if (my_v[1] == v[1])
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if (my_v.at(3) == v.at(3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   my_v.at(3) = 8;
    //   v.at(3) = 8;
    //   printDiffVector(my_v, v);

    //   bool success = false;
    //   try {
    //     my_v.at(80);  // NOLINT
    //     std::cout << BOLDRED "KO " END;
    //   } catch (std::exception& e) {
    //     success = true;
    //   }
    //   try {
    //     v.at(80);  // NOLINT
    //     std::cout << BOLDRED "KO " END;
    //   } catch (std::exception& e) {
    //     if (success) std::cout << BOLDGREEN "OK " END;
    //   }

    //   if (my_v.front() == v.front())
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    //   if (my_v.back() == v.back())
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    // }

    // /* *************** MODIFIERS **************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Modifiers :" END << std::endl;
    //   ft::vector<int> my_v;
    //   my_v.push_back(1);
    //   my_v.push_back(2);
    //   my_v.push_back(3);
    //   my_v.push_back(4);
    //   my_v.push_back(5);

    //   std::vector<int> v;
    //   v.push_back(1);
    //   v.push_back(2);
    //   v.push_back(3);
    //   v.push_back(4);
    //   v.push_back(5);
    //   printDiffVector(my_v, v);

    //   ft::vector<int> my_v_insert;
    //   my_v_insert.push_back(1);
    //   my_v_insert.push_back(2);
    //   my_v_insert.push_back(3);
    //   my_v_insert.push_back(1);
    //   my_v_insert.push_back(2);
    //   my_v_insert.push_back(3);

    //   my_v_insert.push_back(1);
    //   my_v_insert.push_back(2);
    //   my_v_insert.push_back(3);

    //   std::vector<int> v_insert;
    //   v_insert.push_back(1);
    //   v_insert.push_back(2);
    //   v_insert.push_back(3);
    //   v_insert.push_back(1);
    //   v_insert.push_back(2);
    //   v_insert.push_back(3);
    //   v_insert.push_back(1);
    //   v_insert.push_back(2);
    //   v_insert.push_back(3);

    //   printDiffVector(my_v, v);
    //   my_v.pop_back();
    //   v.pop_back();
    //   printDiffVector(my_v, v);

    //   my_v.insert(my_v.begin(), 0);
    //   v.insert(v.begin(), 0);
    //   printDiffVector(my_v, v);

    //   my_v.insert(my_v.begin() + 2, 0);
    //   v.insert(v.begin() + 2, 0);
    //   printDiffVector(my_v, v);

    //   my_v.insert(my_v.begin() + 2, 5, 42);
    //   v.insert(v.begin() + 2, 5, 42);
    //   printDiffVector(my_v, v);

    //   my_v.insert(my_v.begin() + 2, my_v_insert.begin(), my_v_insert.end());
    //   v.insert(v.begin() + 2, v_insert.begin(), v_insert.end());
    //   printDiffVector(my_v, v);

    //   my_v.erase(my_v.begin() + 4);
    //   v.erase(v.begin() + 4);
    //   printDiffVector(my_v, v);

    //   my_v.erase(my_v.begin() + 2, my_v.begin() + 4);
    //   v.erase(v.begin() + 2, v.begin() + 4);
    //   printDiffVector(my_v, v);

    //   my_v.swap(my_v_insert);
    //   v.swap(v_insert);
    //   printDiffVector(my_v, v);
    //   printDiffVector(my_v_insert, v_insert);

    //   my_v.clear();
    //   v.clear();
    //   printDiffVector(my_v, v);
    // }

    // /* ***************** NON MEMBER FUNCTIONS ****************** */
    // {
    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Comparison operators : " END << std::endl;
    //   ft::vector<int> my_v1;
    //   my_v1.push_back(1);
    //   my_v1.push_back(2);
    //   my_v1.push_back(3);
    //   my_v1.push_back(4);
    //   my_v1.push_back(5);

    //   std::vector<int> v1;
    //   v1.push_back(1);
    //   v1.push_back(2);
    //   v1.push_back(3);
    //   v1.push_back(4);
    //   v1.push_back(5);

    //   ft::vector<int> my_v2;
    //   my_v2.push_back(1);
    //   my_v2.push_back(2);
    //   my_v2.push_back(3);

    //   std::vector<int> v2;
    //   v2.push_back(1);
    //   v2.push_back(2);
    //   v2.push_back(3);

    //   ft::vector<int> my_v3;
    //   my_v3.push_back(8);
    //   my_v3.push_back(2);
    //   my_v3.push_back(3);
    //   my_v3.push_back(4);
    //   my_v3.push_back(5);

    //   std::vector<int> v3;
    //   v3.push_back(8);
    //   v3.push_back(2);
    //   v3.push_back(3);
    //   v3.push_back(4);
    //   v3.push_back(5);

    //   if ((my_v1 == my_v2) == (v1 == v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 == my_v3) == (v1 == v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 < my_v2) == (v1 < v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 < my_v3) == (v1 < v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 != my_v2) == (v1 != v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 != my_v3) == (v1 != v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 > my_v2) == (v1 > v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 > my_v3) == (v1 > v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 >= my_v2) == (v1 >= v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 >= my_v3) == (v1 >= v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 <= my_v2) == (v1 <= v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 <= my_v3) == (v1 <= v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    // }
  }
  /* ********************** STACK *********************** */
  std::cout << BOLDMAGENTA "*********** STACK **********" END << std::endl;
  {
    /* *************** PERFORMANCE TESTS **************** */  // OK
    {
      std::cout << BOLDBLUE "Performance test : " END << std::endl;
      // "Vector of 10 000 000 - Push - Pop - Insert - Erase - Swap"
      Chrono chrono = Chrono("My stack", "Std stack");
      chrono.begin();
      ft::stack<int> my_large_s = ft::stack<int>();
      for (unsigned long long int i = 0; i < 100; i++) my_large_s.push(42);
      for (unsigned long long int i = 0; i < 50; i++) my_large_s.pop();

      chrono.stop();
      std::stack<int> large_s = std::stack<int>();
      for (unsigned long long int i = 0; i < 100; i++) large_s.push(42);
      for (unsigned long long int i = 0; i < 50; i++) large_s.pop();
      chrono.stop();

      printDiffStack(my_large_s, large_s);
    }
    {
      std::cout << std::endl
                << std::endl
                << BOLDBLUE "Empty : " END << std::endl;
      ft::stack<int> my_v1;
      if (my_v1.empty())
        std::cout << BOLDGREEN "OK " END;
      else
        std::cout << BOLDRED "KO " END;

      my_v1.push(1);
      my_v1.push(2);
      my_v1.push(3);
      my_v1.push(4);
      my_v1.push(5);
      if (!my_v1.empty())
        std::cout << BOLDGREEN "OK " END;
      else
        std::cout << BOLDRED "KO " END;

      std::stack<int> v1;
      v1.push(1);
      v1.push(2);
      v1.push(3);
      v1.push(4);
      v1.push(5);
      std::cout << std::endl
                << std::endl
                << BOLDBLUE "Push : " END << std::endl;

      printDiffStack(my_v1, v1);
    }
    // my_v1.pop();
    // v1.pop();
    // printDiffStack(my_v1, v1);

    // ft::stack<int> my_v2;
    // my_v2.push(1);
    // my_v2.push(2);
    // my_v2.push(3);

    // std::stack<int> v2;
    // v2.push(1);
    // v2.push(2);
    // v2.push(3);

    // ft::stack<int> my_v3;
    // my_v3.push(8);
    // my_v3.push(2);
    // my_v3.push(3);
    // my_v3.push(4);
    // my_v3.push(5);

    // std::stack<int> v3;
    // v3.push(8);
    // v3.push(2);
    // v3.push(3);
    // v3.push(4);
    // v3.push(5);

    //   std::cout << std::endl
    //             << std::endl
    //             << BOLDBLUE "Comparison operators : " END << std::endl;
    //   if ((my_v1 == my_v2) == (v1 == v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 == my_v3) == (v1 == v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 < my_v2) == (v1 < v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 < my_v3) == (v1 < v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 != my_v2) == (v1 != v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 != my_v3) == (v1 != v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 > my_v2) == (v1 > v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 > my_v3) == (v1 > v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 >= my_v2) == (v1 >= v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 >= my_v3) == (v1 >= v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 <= my_v2) == (v1 <= v2))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;

    //   if ((my_v1 <= my_v3) == (v1 <= v3))
    //     std::cout << BOLDGREEN "OK " END;
    //   else
    //     std::cout << BOLDRED "KO " END;
    // }
  }

  /* ********************** PAIR & MAKEPAIR *********************** */
  std::cout << BOLDMAGENTA "*********** PAIR & MAKEPAIR **********" END
            << std::endl;
  {
    // std::cout << BOLDBLUE "Performance test : " END << std::endl;

    // Chrono chrono = Chrono("My pair", "Std pair");
    // chrono.begin();
    // for (int i = 0; i < 10000000; i++) {
    //   ft::pair<int, int> my_p1 = ft::make_pair(1, 2);
    //   ft::pair<int, int> my_p2 = ft::make_pair(3, 4);
    //   swap(my_p1, my_p2);
    // }
    // chrono.stop();
    // for (int i = 0; i < 10000000; i++) {
    //   std::pair<int, int> p1 = std::make_pair(1, 2);
    //   std::pair<int, int> p2 = std::make_pair(3, 4);
    //   swap(p1, p2);
    // }
    // chrono.stop();

    // std::cout << BOLDBLUE "Make pair : " END << std::endl;

    // ft::pair<int, int> my_p1 = ft::make_pair(1, 2);
    // std::pair<int, int> p1 = std::make_pair(1, 2);

    // ft::pair<int, int> my_p2 = ft::make_pair(3, 4);
    // std::pair<int, int> p2 = std::make_pair(3, 4);
    // printDiffPair(my_p1, p1);
    // printDiffPair(my_p2, p2);
    // std::cout << std::endl << BOLDBLUE "Swap : " END << std::endl;

    // swap(my_p1, my_p2);
    // swap(p1, p2);
    // printDiffPair(my_p1, p1);
    // printDiffPair(my_p2, p2);
    // my_p1.swap(my_p2);
    // p1.swap(p2);
    // printDiffPair(my_p1, p1);
    // printDiffPair(my_p2, p2);
    // std::cout << std::endl
    //           << BOLDBLUE "Comparison operators : " END << std::endl;
    // if ((my_p1 == my_p2) == (p1 == p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
    // if ((my_p1 != my_p2) == (p1 != p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
    // if ((my_p1 < my_p2) == (p1 < p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
    // if ((my_p1 <= my_p2) == (p1 <= p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
    // if ((my_p1 > my_p2) == (p1 > p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
    // if ((my_p1 >= my_p2) == (p1 >= p2))
    //   std::cout << BOLDGREEN "OK " END;
    // else
    //   std::cout << BOLDRED "KO " END;
  }
}
}

// to test guarantee : create class which throws in constructor / destructor /
// randomly in constructor