#include <iterator>
#include <vector>

#include "tests_utils/chrono_mono.hpp"
#include "tests_utils/tests_utils.hpp"

template <class T>
void printVector(std::vector<T> v) {
  if (v.size() == 0) {
    std::cout << "Empty" << std::endl;
    return;
  }
  for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main(void) {
  try {
    std::cout
        << BOLDCYAN
        "/*************************************************************/"
        << std::endl
        << "/                            VECTOR                           /"
        << std::endl
        << "/*************************************************************/" END
        << std::endl;
    /**** PERFORMANCE ****/
    {
      std::cout << std::endl
                << BOLDGREEN "***** Performance *****" END << std::endl
                << std::endl;
      ChronoMono chrono;
      chrono.begin();
      std::vector<int> my_large_v(10000000, 42);
      std::vector<int> my_large_v2(10000000, 41);
      std::vector<int> copy(my_large_v);
      my_large_v.push_back(1);
      my_large_v.pop_back();
      my_large_v.insert(my_large_v.begin() + 500000, 43);
      my_large_v.erase(my_large_v.begin() + 500000);
      my_large_v.insert(my_large_v.begin() + 400000, 100000, 43);
      my_large_v.insert(my_large_v.begin() + 5000000, my_large_v2.begin(),
                        my_large_v2.end());
      my_large_v.erase(my_large_v.begin() + 400000,
                       my_large_v.begin() + 500000);
      std::vector<int> my_large_v_swap(999999, 41);
      my_large_v.swap(my_large_v_swap);
      std::vector<int> large_v = std::vector<int>(10000000, 42);
      std::vector<int> large_v2 = std::vector<int>(10000000, 41);
      large_v.push_back(1);
      large_v.pop_back();
      large_v.insert(large_v.begin() + 500000, 43);
      large_v.erase(large_v.begin() + 500000);
      large_v.insert(large_v.begin() + 400000, 100000, 43);
      large_v.insert(large_v.begin() + 5000000, large_v2.begin(),
                     large_v2.end());
      large_v.erase(large_v.begin() + 400000, large_v.begin() + 500000);
      std::vector<int> large_v_swap = std::vector<int>(999999, 41);
      large_v.swap(large_v_swap);
      chrono.stop();
    }
    /**** TESTS ****/
    ChronoMono chrono1;
    chrono1.begin();
    std::cout << std::endl
              << BOLDGREEN "***** Functions *****" END << std::endl;
    /* *************** CONSTRUCTORS **************** */
    {
      std::cout << std::endl
                << std::endl
                << BOLDBLUE "Constructors: " END << std::endl;
      std::vector<int> my_v1;
      std::vector<int> my_v2(5);
      std::vector<int> my_v3(5, 42);
      std::vector<std::string> my_v4(5, "bla");
      std::vector<int> my_v5(my_v3.begin(), my_v3.begin() + 2);
      std::vector<int> my_v6(my_v3);
      std::vector<int> my_v7 = my_v6;  // NOLINT
      std::vector<int> my_v8(10, 42);
      my_v8.assign(my_v3.begin(), my_v3.begin() + 2);
      std::vector<int> my_v9(10, 42);
      my_v9.assign(5, 43);
      /* *************** CUSTOM CLASS **************** */
      bli test_complex = bli();
      std::vector<bli> my_v_complex = std::vector<bli>(3, test_complex);
      printVector(my_v3);
      printVector(my_v4);
      printVector(my_v6);
      printVector(my_v7);
      printVector(my_v8);
      printVector(my_v9);
      printVector(my_v_complex);
    }
    /* *************** ITERATORS **************** */
    {
      std::cout << std::endl << BOLDBLUE "Iterators:" END << std::endl;
      std::vector<int> my_v;
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

      std::cout << "Pre incrementation : ";
      for (std::vector<int>::iterator it = my_v.begin(); it != my_v.end();
           ++it) {
        std::cout << *it << " ";
      }

      std::cout << std::endl << "Post incrementation : ";
      for (std::vector<int>::iterator it = my_v.begin(); it != my_v.end();
           it++) {
        std::cout << *it << " ";
      }

      std::cout << std::endl << "Pre decrementation : ";
      for (std::vector<int>::iterator it = my_v.end(); it != my_v.begin();
           --it) {
        std::cout << *it << " ";
      }

      std::cout << std::endl << "Post decrementation : ";
      for (std::vector<int>::iterator it = my_v.end(); it != my_v.begin();
           it--) {
        std::cout << *it << " ";
      }

      std::cout << std::endl << "Addition : ";
      std::cout << *(my_v.begin() + 2) << " ";
      std::vector<int>::iterator my_it = my_v.begin();
      my_it += 2;
      std::vector<int>::iterator it = v.begin();
      it += 2;
      std::cout << *(my_it) << std::endl;
      std::cout << std::endl << "Substraction : ";
      std::cout << *(my_v.end() - 2) << " ";
      my_it -= 1;
      std::cout << *(my_it) << std::endl;
    }

    /* *************** REVERSE ITERATORS **************** */
    {
      std::cout << std::endl << BOLDBLUE "Reverse iterators :" END << std::endl;
      std::vector<int> my_v;
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

      std::cout << "Pre incrementation : ";
      for (std::vector<int>::reverse_iterator it = my_v.rbegin();
           it != my_v.rend(); ++it) {
        std::cout << *(it) << " ";
      }
      std::cout << std::endl << "Post incrementation : ";
      for (std::vector<int>::reverse_iterator it = my_v.rbegin();
           it != my_v.rend(); it++) {
        std::cout << *(it) << " ";
      }
      std::cout << std::endl << "Pre decrementation : ";
      std::vector<int>::reverse_iterator it1 = my_v.rend();
      --it1;
      for (; it1 != my_v.rbegin(); --it1) {
        std::cout << *(it1) << " ";
      }
      std::cout << std::endl << "Post decrementation : ";
      std::vector<int>::reverse_iterator it2 = my_v.rend();
      it2--;
      for (; it2 != my_v.rbegin(); it2--) {
        std::cout << *(it2) << " ";
      }
      std::cout << std::endl << "Addition : ";
      std::cout << *(my_v.rbegin() + 2) << " ";
      std::vector<int>::reverse_iterator my_it = my_v.rbegin();
      my_it += 2;
      std::cout << *(my_it) << std::endl;

      std::cout << std::endl << "Substraction : ";
      std::cout << *(my_v.rend() - 2) << " ";
      my_it -= 1;
      std::cout << *(my_it) << std::endl;
    }

    /**************** CAPACITY *****************/
    {
      std::cout << std::endl
                << BOLDBLUE "Size, Capacity & Empty:" END << std::endl;

      std::vector<int> my_v;
      my_v.push_back(1);
      my_v.push_back(2);
      printVector(my_v);
      std::cout << my_v.size() << " " << my_v.capacity() << std::endl;
      my_v.push_back(3);
      my_v.push_back(4);
      my_v.push_back(5);
      my_v.resize(50);
      printVector(my_v);
      std::cout << my_v.size() << " " << my_v.capacity() << std::endl;
      my_v.push_back(2);
      my_v.resize(3);
      printVector(my_v);
      std::cout << my_v.size() << " " << my_v.capacity() << std::endl;
      my_v.reserve(2);
      printVector(my_v);
      std::cout << my_v.size() << " " << my_v.capacity() << std::endl;

      my_v.reserve(80);
      my_v.push_back(2);
      printVector(my_v);
      std::cout << my_v.size() << " " << my_v.capacity() << std::endl;
      std::cout << (my_v.empty() ? "Empty" : "Not empty") << std::endl;
      std::vector<int> my_v_empty;
      std::cout << (my_v_empty.empty() ? "Empty" : "Not empty") << std::endl;
    }

    /* *************** ACCESS **************** */
    {
      std::cout << std::endl

                << BOLDBLUE "Access:" END << std::endl;
      std::vector<int> my_v;
      my_v.push_back(1);
      my_v.push_back(2);
      my_v.push_back(3);
      my_v.push_back(4);
      my_v.push_back(5);

      std::cout << my_v[0] << std::endl;
      my_v[1] = 42;
      std::cout << my_v[1] << std::endl;
      std::cout << my_v.at(3) << std::endl;
      my_v.at(3) = 8;
      std::cout << my_v.at(3) << std::endl;
      std::cout << my_v.front() << std::endl;
      std::cout << my_v.back() << std::endl;
    }

    /* *************** MODIFIERS **************** */
    {
      std::cout << std::endl << BOLDBLUE "Modifiers :" END << std::endl;
      std::vector<int> my_v;
      my_v.push_back(1);
      my_v.push_back(2);
      my_v.push_back(3);
      my_v.push_back(4);
      my_v.push_back(5);

      std::vector<int> my_v_insert;
      my_v_insert.push_back(1);
      my_v_insert.push_back(2);
      my_v_insert.push_back(3);
      my_v_insert.push_back(1);
      my_v_insert.push_back(2);
      my_v_insert.push_back(3);
      my_v_insert.push_back(1);
      my_v_insert.push_back(2);
      my_v_insert.push_back(3);
      printVector(my_v);
      my_v.pop_back();
      printVector(my_v);
      my_v.insert(my_v.begin(), 0);
      printVector(my_v);
      my_v.insert(my_v.begin() + 2, 0);
      printVector(my_v);
      my_v.insert(my_v.begin() + 2, 5, 42);
      printVector(my_v);
      my_v.insert(my_v.begin() + 2, my_v_insert.begin(), my_v_insert.end());
      printVector(my_v);
      my_v.erase(my_v.begin() + 4);
      printVector(my_v);
      my_v.erase(my_v.begin() + 2, my_v.begin() + 4);
      printVector(my_v);
      my_v.swap(my_v_insert);
      printVector(my_v);
      printVector(my_v_insert);
      my_v.clear();
      printVector(my_v);
    }

    /* ***************** NON MEMBER FUNCTIONS ****************** */
    {
      std::cout << std::endl
                << BOLDBLUE "Comparison operators : " END << std::endl;
      std::vector<int> my_v1;
      my_v1.push_back(1);
      my_v1.push_back(2);
      my_v1.push_back(3);
      my_v1.push_back(4);
      my_v1.push_back(5);

      std::vector<int> my_v2;
      my_v2.push_back(1);
      my_v2.push_back(2);
      my_v2.push_back(3);

      std::vector<int> my_v3;
      my_v3.push_back(8);
      my_v3.push_back(2);
      my_v3.push_back(3);
      my_v3.push_back(4);
      my_v3.push_back(5);
      std::cout << (my_v1 == my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 == my_v3 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 < my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 < my_v3 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 != my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 != my_v3 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 > my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 > my_v3 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 <= my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 <= my_v3 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 >= my_v2 ? "Y" : "N") << std::endl;
      std::cout << (my_v1 >= my_v3 ? "Y" : "N") << std::endl;
    }
    /**** CORRECTION ****/
    std::cout << std::endl
              << BOLDGREEN "***** Correction specific requirements ***** " END
              << std::endl;

    // iterator comparison
    std::cout << BOLDBLUE "Iterator and const iterator comparison:" END
              << std::endl;

    std::vector<int> v1(3, 42);

    std::vector<int>::iterator it1 = v1.begin();
    std::vector<int>::const_iterator itc1 = v1.begin() + 1;

    std::cout << (*it1 < *itc1 ? "Comparison works" : "Comparison works ")
              << std::endl;

    // swap
    std::cout << std::endl << BOLDBLUE "Swap:" END << std::endl;
    std::vector<int> v2(3, 43);
    std::vector<int>::iterator it2 = v2.begin();
    const int& r1 = v1[1];
    const int& r2 = v2[1];

    int* p1 = &v1[1];
    int* p2 = &v2[1];

    std::cout << "Before Swap :" << std::endl << "V1: ";
    printVector(v1);
    std::cout << "Iterator, ref and pointer 1: ";
    std::cout << *it1 << " " << r1 << " " << *p1 << std::endl << std::endl;
    std::cout << "V2: ";
    printVector(v2);
    std::cout << "Iterator, ref and pointer 2: ";
    std::cout << *it2 << " " << r2 << " " << *p2 << std::endl;
    std::cout << std::endl
              << CYAN "--- Swapping v1 - v2 ---" END << std::endl
              << std::endl;
    swap(v1, v2);
    std::cout << "V1: ";
    printVector(v1);
    std::cout << "Iterator, ref and pointer 1 (must remain the same): ";
    std::cout << *it1 << " " << r1 << " " << *p1 << std::endl << std::endl;
    std::cout << "V2: ";
    printVector(v2);
    std::cout << "Iterator, ref and pointer 2 (must remain the same): ";
    std::cout << *it2 << " " << r2 << " " << *p2 << std::endl << std::endl;
    ;
    std::cout << "Iterator 1 iterating in new 2: ";
    for (; it1 != v2.end(); it1++) {
      std::cout << *it1 << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterator 2 iterating in new 1: ";
    for (; it2 != v1.end(); it2++) {
      std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    chrono1.stop();
  } catch (std::exception& e) {
  };
}