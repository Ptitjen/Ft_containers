#include "containers/map.hpp"
#include "containers/stack.hpp"
#include "containers/vector.hpp"
#include "functions/make_pair.hpp"
#include "tests_utils/chrono_mono.hpp"
#include "tests_utils/utils.hpp"

template <class T> void printVector(ft::vector<T> v) {
  if (v.size() == 0) {
    std::cout << "Empty" << std::endl;
    return;
  }
  for (typename ft::vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <class T> void printStack(ft::stack<T> s) {
  if (s.size() == 0) {
    std::cout << "Empty" << std::endl;
    return;
  }
  ft::stack<T> cpy = s;
  while (!cpy.empty()) {
    std::cout << cpy.top() << " ";
    cpy.pop();
  }
  std::cout << std::endl;
}

template <class T, class U> void printMap(ft::map<T, U> m) {
  if (m.size() == 0) {
    std::cout << "Empty" << std::endl;
    return;
  }
  for (typename ft::map<T, U>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << it->first << " " << it->second << " | ";
  }
  std::cout << std::endl;
}

int main(void) {
  try {
    {
      std::cout
          << BOLDCYAN
          "/*************************************************************/"
          << std::endl
          << "/                            VECTOR                           /"
          << std::endl
          << "/*************************************************************"
             "/" END
          << std::endl;
      /**** PERFORMANCE ****/
      {
        std::cout << std::endl
                  << BOLDGREEN "***** Performance *****" END << std::endl
                  << std::endl;
        ChronoMono chrono;
        chrono.begin();
        ft::vector<int> my_large_v(10000000, 42);
        ft::vector<int> my_large_v2(10000000, 41);
        ft::vector<int> copy(my_large_v);
        my_large_v.push_back(1);
        my_large_v.pop_back();
        my_large_v.insert(my_large_v.begin() + 500000, 43);
        my_large_v.erase(my_large_v.begin() + 500000);
        my_large_v.insert(my_large_v.begin() + 400000, 100000, 43);
        my_large_v.insert(my_large_v.begin() + 5000000, my_large_v2.begin(),
                          my_large_v2.end());
        my_large_v.erase(my_large_v.begin() + 400000,
                         my_large_v.begin() + 500000);
        ft::vector<int> my_large_v_swap(999999, 41);
        my_large_v.swap(my_large_v_swap);
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
        ft::vector<int> my_v1;
        ft::vector<int> my_v2(5);
        ft::vector<int> my_v3(5, 42);
        ft::vector<std::string> my_v4(5, "bla");
        ft::vector<int> my_v5(my_v3.begin(), my_v3.begin() + 2);
        ft::vector<int> my_v6(my_v3);
        ft::vector<int> my_v7 = my_v6; // NOLINT
        ft::vector<int> my_v8(10, 42);
        my_v8.assign(my_v3.begin(), my_v3.begin() + 2);
        ft::vector<int> my_v9(10, 42);
        my_v9.assign(5, 43);
        /* *************** CUSTOM CLASS **************** */
        bli test_complex = bli();
        ft::vector<bli> my_v_complex = ft::vector<bli>(3, test_complex);
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
        ft::vector<int> my_v;
        my_v.push_back(1);
        my_v.push_back(2);
        my_v.push_back(3);
        my_v.push_back(4);
        my_v.push_back(5);

        std::cout << std::endl << "Incrementation : ";
        for (ft::vector<int>::iterator it = my_v.begin(); it != my_v.end();
             it++) {
          std::cout << *it << " ";
        }

        std::cout << std::endl << "Decrementation : ";
        ft::vector<int>::iterator it = my_v.end();
        it--;
        for (; it != my_v.begin(); it--) {
          std::cout << *it << " ";
        }

        std::cout << std::endl << "Addition : ";
        std::cout << *(my_v.begin() + 2) << " ";
        ft::vector<int>::iterator my_it = my_v.begin();
        my_it += 2;

        std::cout << *(my_it) << std::endl;
        std::cout << std::endl << "Substraction : ";
        std::cout << *(my_v.end() - 2) << " ";
        my_it -= 1;
        std::cout << *(my_it) << std::endl;
      }

      /* *************** REVERSE ITERATORS **************** */
      {
        std::cout << std::endl
                  << BOLDBLUE "Reverse iterators :" END << std::endl;
        ft::vector<int> my_v;
        my_v.push_back(1);
        my_v.push_back(2);
        my_v.push_back(3);
        my_v.push_back(4);
        my_v.push_back(5);

        std::cout << "Pre incrementation : ";
        for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
             it != my_v.rend(); ++it) {
          std::cout << *(it) << " ";
        }
        std::cout << std::endl << "Post incrementation : ";
        for (ft::vector<int>::reverse_iterator it = my_v.rbegin();
             it != my_v.rend(); it++) {
          std::cout << *(it) << " ";
        }
        std::cout << std::endl << "Pre decrementation : ";
        ft::vector<int>::reverse_iterator it1 = my_v.rend();
        --it1;
        for (; it1 != my_v.rbegin(); --it1) {
          std::cout << *(it1) << " ";
        }
        std::cout << std::endl << "Post decrementation : ";
        ft::vector<int>::reverse_iterator it2 = my_v.rend();
        it2--;
        for (; it2 != my_v.rbegin(); it2--) {
          std::cout << *(it2) << " ";
        }
        std::cout << std::endl << "Addition : ";
        std::cout << *(my_v.rbegin() + 2) << " ";
        ft::vector<int>::reverse_iterator my_it = my_v.rbegin();
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

        ft::vector<int> my_v;
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
        ft::vector<int> my_v_empty;
        std::cout << (my_v_empty.empty() ? "Empty" : "Not empty") << std::endl;
      }

      /* *************** ACCESS **************** */
      {
        std::cout << std::endl

                  << BOLDBLUE "Access:" END << std::endl;
        ft::vector<int> my_v;
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
        ft::vector<int> my_v;
        my_v.push_back(1);
        my_v.push_back(2);
        my_v.push_back(3);
        my_v.push_back(4);
        my_v.push_back(5);

        ft::vector<int> my_v_insert;
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
        ft::vector<int> my_v1;
        my_v1.push_back(1);
        my_v1.push_back(2);
        my_v1.push_back(3);
        my_v1.push_back(4);
        my_v1.push_back(5);

        ft::vector<int> my_v2;
        my_v2.push_back(1);
        my_v2.push_back(2);
        my_v2.push_back(3);

        ft::vector<int> my_v3;
        my_v3.push_back(8);
        my_v3.push_back(2);
        my_v3.push_back(3);
        my_v3.push_back(4);
        my_v3.push_back(5);
        std::cout << (my_v1 == my_v2 ? "Y" : "N");
        std::cout << (my_v1 == my_v3 ? "Y" : "N");
        std::cout << (my_v1 < my_v2 ? "Y" : "N");
        std::cout << (my_v1 < my_v3 ? "Y" : "N");
        std::cout << (my_v1 != my_v2 ? "Y" : "N");
        std::cout << (my_v1 != my_v3 ? "Y" : "N");
        std::cout << (my_v1 > my_v2 ? "Y" : "N");
        std::cout << (my_v1 > my_v3 ? "Y" : "N");
        std::cout << (my_v1 <= my_v2 ? "Y" : "N");
        std::cout << (my_v1 <= my_v3 ? "Y" : "N");
        std::cout << (my_v1 >= my_v2 ? "Y" : "N");
        std::cout << (my_v1 >= my_v3 ? "Y" : "N");
      }
      /**** CORRECTION ****/
      std::cout << std::endl
                << BOLDGREEN "***** Correction specific requirements ***** " END
                << std::endl;

      std::cout << BOLDBLUE "Iterator and const iterator comparison:" END
                << std::endl;

      ft::vector<int> v1(3, 42);

      ft::vector<int>::iterator it1 = v1.begin();
      ft::vector<int>::const_iterator itc1 = v1.begin() + 1;

      std::cout << (*it1 < *itc1 ? "Comparison works" : "Comparison works ")
                << std::endl;

      std::cout << std::endl << BOLDBLUE "Swap:" END << std::endl;
      ft::vector<int> v2(3, 43);
      ft::vector<int>::iterator it2 = v2.begin();
      const int &r1 = v1[1];
      const int &r2 = v2[1];

      int *p1 = &v1[1];
      int *p2 = &v2[1];

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
    }
    {
      std::cout
          << BOLDCYAN
          "/*************************************************************/"
          << std::endl
          << "/                            MAP                              /"
          << std::endl
          << "/*************************************************************"
             "/" END
          << std::endl;
      /**** PERFORMANCE ****/
      {
        std::cout << std::endl
                  << BOLDGREEN "***** Performance *****" END << std::endl
                  << std::endl;
        ChronoMono chrono;
        chrono.begin();
        ft::map<int, char> my_m1;
        for (int i = 0; i < 1000000; i++) {
          my_m1.insert(ft::pair<int, char>(i, '$'));
        }
        my_m1.erase(1);
        my_m1.erase(50000);
        my_m1.erase(100000);
        my_m1.erase(500000);
        for (int i = 0; i < 1000000; i++) {
          int n = rand() % 10000000;
          my_m1.insert(ft::pair<int, char>(n, '$'));
        }
        ft::map<int, char> my_m2(my_m1);
        chrono.stop();
      }
      ChronoMono chrono;
      chrono.begin();
      {
        std::cout << std::endl
                  << BOLDGREEN "***** Functions *****" END << std::endl
                  << std::endl;

        /* ***************************************************************** */
        /*                          CONSTRUCTORS                             */
        /* ***************************************************************** */
        {
          std::cout << BOLDBLUE "********* Constructors *********" END
                    << std::endl;
          ft::map<int, char> my_m;
          ft::map<int, char> my_m_it;
          for (int i = 0; i < 10; i++) {
            my_m_it.insert(ft::pair<int, char>(i, '@'));
          }
          ft::map<int, char> my_m_it_cpy(my_m_it.begin(), my_m_it.end());
          ft::map<int, char> my_m1;
          my_m1 = my_m;
          ft::map<int, char> my_m2(my_m1);
          printMap(my_m);
          printMap(my_m_it);
          printMap(my_m_it_cpy);
          printMap(my_m1);
          printMap(my_m2);
        }

        /* ***************************************************************** */
        /*                          ITERATORS                                */
        /* ***************************************************************** */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Iterators *********" END
                    << std::endl;
          ft::map<int, char> my_m;
          for (int i = 33; i < 65; i++) {
            my_m.insert(ft::pair<int, char>(i, (char)i));
          }
          printMap(my_m);
          std::cout << std::endl
                    << BOLDCYAN "Iterator increment" END << std::endl;

          for (ft::map<int, char>::iterator it = my_m.begin(); it != my_m.end();
               it++) {
            std::cout << it->first << " " << it->second << " | ";
          }

          std::cout << std::endl
                    << BOLDCYAN "Iterator decrement" END << std::endl;
          for (ft::map<int, char>::iterator it = my_m.end(); it != my_m.begin();
               it--) {
            ft::map<int, char>::iterator itc = it;
            itc--;
            std::cout << itc->first << " " << itc->second << " | ";
          }

          std::cout << std::endl
                    << BOLDCYAN "Reverse iterator increment" END << std::endl;

          for (ft::map<int, char>::reverse_iterator it = my_m.rbegin();
               it != my_m.rend(); it++) {
            std::cout << it->first << " " << it->second << " | ";
          }

          std::cout << std::endl
                    << BOLDCYAN "Reverse iterator decrement" END << std::endl;

          for (ft::map<int, char>::reverse_iterator it = my_m.rend();
               it != my_m.rbegin(); it--) {
            ft::map<int, char>::reverse_iterator itc = it;
            itc--;
            std::cout << itc->first << " " << itc->second << " | ";
          }
        }
        /* *****************************************************************
         */
        /*                          CAPACITY */
        /* *****************************************************************
         */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Capacity *********" END << std::endl;
          ft::map<int, char> my_m;
          std::cout << "Empty: ";
          std::cout << (my_m.empty() ? "Empty" : "Not empty") << std::endl;

          for (int i = 33; i < 65; i++) {
            my_m.insert(ft::pair<int, char>(i, (char)i));
          }
          std::cout << (my_m.empty() ? "Empty" : "Not empty") << std::endl;
          std::cout << "Size: ";
          std::cout << my_m.size() << std::endl;
        }
        /* *****************************************************************
         */
        /*                          ELEMENT ACCESS */
        /* *****************************************************************
         */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Element access *********" END
                    << std::endl;
          ft::map<int, char> my_m;
          for (int i = 33; i < 65; i++) {
            my_m.insert(ft::pair<int, char>(i, (char)i));
          }
          std::cout << "Size before access [] to not existing element => adds "
                       "element :"
                    << my_m.size() << std::endl;

          std::cout << my_m[32];
          std::cout << std::endl
                    << "Size after => added element :" << my_m.size()
                    << std::endl;
          std::cout << my_m[33];
          my_m[75] = 'A';
          printMap(my_m);
        }
        /* *****************************************************************
         */
        /*                              MODIFIERS */
        /* *****************************************************************
         */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Modifiers *********" END
                    << std::endl;
          std::cout << std::endl << BOLDCYAN "Basic insert : " END << std::endl;
          {
            ft::map<int, char> my_m;
            for (int i = 33; i < 55; i += 2) {
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            for (int i = 32; i < 54; i += 2) {
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            std::cout << "Verifying duplicates :" << std::endl;
            my_m.insert(ft::pair<int, char>(34, '@'));
            printMap(my_m);
          }

          std::cout << std::endl << BOLDCYAN "Hint insert : " END << std::endl;
          {
            ft::map<int, char> my_m;

            for (int i = 33; i < 55; i++) {
              i++;
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            for (int i = 33; i < 55; i++) {
              my_m.insert(my_m.find(i - 1), ft::pair<int, char>(i, (char)i));
            }
            printMap(my_m);
          }
          std::cout << std::endl
                    << BOLDCYAN "Iterator insert : " END << std::endl;
          {
            ft::map<int, char> my_m;

            for (int i = 33; i < 55; i++) {
              i++;
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            ft::map<int, char> my_m1;
            for (int i = 32; i < 54; i++) {
              i++;
              my_m1.insert(ft::pair<int, char>(i, (char)i));
            }
            my_m.insert(my_m1.begin(), my_m1.end());
            printMap(my_m);
            std::cout << std::endl
                      << BOLDCYAN "Erase iterator : " END << std::endl;
            my_m.erase(my_m.find(33));
            printMap(my_m);
            printMap(my_m);
            my_m.erase(my_m.find(45));
            printMap(my_m);

            std::cout << std::endl << BOLDCYAN "Erase key : " END << std::endl;
            my_m.erase(47);

            my_m.erase(0);
            printMap(my_m);
          }
          {
            std::cout << std::endl
                      << BOLDCYAN "Erase iterator : " END << std::endl;
            ft::map<int, char> my_m;
            for (int i = 33; i < 55; i++) {
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            my_m.erase(my_m.find(35), my_m.find(45));
            printMap(my_m);
          }

          {
            std::cout << std::endl << BOLDCYAN "Swap : " END << std::endl;
            ft::map<int, char> my_m;
            for (int i = 33; i < 55; i++) {
              i++;
              my_m.insert(ft::pair<int, char>(i, (char)i));
            }
            ft::map<int, char> my_m1;
            for (int i = 32; i < 54; i++) {
              i++;
              my_m1.insert(ft::pair<int, char>(i, (char)i));
            }
            std::cout << "M1: ";
            printMap(my_m);
            std::cout << "M2: ";
            printMap(my_m1);
            std::cout << CYAN "--- Swap ---" END << std::endl;
            swap(my_m, my_m1);
            std::cout << "M1: ";
            printMap(my_m);
            std::cout << "M2: ";
            printMap(my_m1);
            std::cout << std::endl << "Clear : " << std::endl;
            my_m.clear();
            printMap(my_m);
            ft::map<int, char> my_m3;
          }
        }

        /* ********************************************************************
         */
        /*                                 OPERATIONS */
        /* ********************************************************************
         */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Operations *********" END
                    << std::endl;
          std::cout << std::endl << "Find : " << std::endl;

          ft::map<int, char> my_m;
          for (int i = 33; i < 55; i++) {
            my_m.insert(ft::pair<int, char>(i, (char)i));
          }
          std::cout << my_m.find(33)->first << " " << my_m.find(33)->second
                    << std::endl;

          std::cout << std::endl << "Count : " << std::endl;
          std::cout << my_m.count(33) << std::endl;
          std::cout << my_m.count(25) << std::endl;
          std::cout << std::endl << "Lower & Upper Bounds : " << std::endl;
          std::cout << my_m.lower_bound(33)->first << std::endl;
          std::cout << my_m.upper_bound(33)->first << std::endl;
          my_m.erase(45);
          std::cout << my_m.lower_bound(45)->first << std::endl;
          std::cout << my_m.upper_bound(45)->first << std::endl;

          std::cout << std::endl << "Equal range : " << std::endl;

          std::cout << my_m.equal_range(33).first->first << " "
                    << my_m.equal_range(33).first->second << " "
                    << my_m.equal_range(33).second->first << " "
                    << my_m.equal_range(33).second->second << std::endl;
        }

        /* ********************************************************************
         */
        /*                                 NON MEMBER FUNCTIONS */
        /* ********************************************************************
         */
        {
          std::cout << std::endl
                    << BOLDBLUE "********* Non member functions *********" END
                    << std::endl;
          std::cout << std::endl << "Comparison : " << std::endl;
          ft::map<int, char> my_m;
          for (int i = 33; i < 55; i++) {
            my_m.insert(ft::pair<int, char>(i, (char)i));
          }
          ft::map<int, char> my_m1;
          for (int i = 33; i < 55; i++) {
            my_m1.insert(ft::pair<int, char>(i, (char)i));
          }
          std::cout << ((my_m == my_m1) ? "Y" : "N");
          std::cout << ((my_m < my_m1) ? "Y" : "N");
          std::cout << ((my_m <= my_m1) ? "Y" : "N");
          std::cout << ((my_m >= my_m1) ? "Y" : "N");
          std::cout << ((my_m != my_m1) ? "Y" : "N");
          std::cout << ((my_m > my_m1) ? "Y" : "N");
          my_m1.insert(ft::pair<int, char>(98, '@'));
          std::cout << ((my_m == my_m1) ? "Y" : "N");
          std::cout << ((my_m < my_m1) ? "Y" : "N");
          std::cout << ((my_m <= my_m1) ? "Y" : "N");
          std::cout << ((my_m >= my_m1) ? "Y" : "N");
          std::cout << ((my_m != my_m1) ? "Y" : "N");
          std::cout << ((my_m > my_m1) ? "Y" : "N");
          std::cout << std::endl << "Swap : " << std::endl;
          swap(my_m, my_m1);
          printMap(my_m);
          printMap(my_m1);
        }
        chrono.stop();
      }
    }
    {
      std::cout
          << BOLDCYAN
          "/*************************************************************/"
          << std::endl
          << "/                            STACK                             "
             " /"
          << std::endl
          << "/*************************************************************"
             "/" END
          << std::endl;

      /* *************** PERFORMANCE TESTS **************** */ // OK
      {
        std::cout << BOLDBLUE "Performance test : " END << std::endl;
        ChronoMono chrono;
        chrono.begin();
        ft::stack<int> my_large_s = ft::stack<int>();
        for (unsigned long long int i = 0; i < 10000000; i++)
          my_large_s.push(42);
        for (unsigned long long int i = 0; i < 50000; i++)
          my_large_s.pop();
        chrono.stop();
      }
      {
        std::cout << std::endl << BOLDBLUE "Empty : " END << std::endl;
        ft::stack<int> my_v1;
        std::cout << (my_v1.empty() ? "Empty" : "Not empty") << std::endl;

        my_v1.push(1);
        my_v1.push(2);
        my_v1.push(3);
        my_v1.push(4);
        my_v1.push(5);
        printStack(my_v1);
        std::cout << (my_v1.empty() ? "Empty" : "Not empty") << std::endl;
        ft::stack<int> my_v1cpy(my_v1);
        // ft::stack<int>::iterator it;

        std::cout << std::endl << BOLDBLUE "Top : " END << std::endl;
        std::cout << my_v1.top() << std::endl;
        printStack(my_v1);
        std::cout << BOLDBLUE "Pop : " END << std::endl;
        my_v1.pop();
        printStack(my_v1);
      }
      {
        std::cout << std::endl
                  << BOLDBLUE "Comparison operators : " END << std::endl;

        ft::stack<int> my_v1;
        my_v1.push(1);
        my_v1.push(2);
        my_v1.push(3);
        my_v1.push(4);
        my_v1.push(5);

        ft::stack<int> my_v2;
        my_v2.push(1);
        my_v2.push(2);
        my_v2.push(3);

        ft::stack<int> my_v3;
        my_v3.push(8);
        my_v3.push(2);
        my_v3.push(3);
        my_v3.push(4);
        my_v3.push(5);

        std::cout << (my_v1 == my_v2 ? "Y" : "N");
        std::cout << (my_v1 == my_v3 ? "Y" : "N");

        std::cout << (my_v1 < my_v2 ? "Y" : "N");
        std::cout << (my_v1 < my_v3 ? "Y" : "N");

        std::cout << (my_v1 > my_v2 ? "Y" : "N");
        std::cout << (my_v1 > my_v3 ? "Y" : "N");

        std::cout << (my_v1 != my_v2 ? "Y" : "N");
        std::cout << (my_v1 != my_v3 ? "Y" : "N");

        std::cout << (my_v1 <= my_v2 ? "Y" : "N");
        std::cout << (my_v1 <= my_v3 ? "Y" : "N");

        std::cout << (my_v1 >= my_v2 ? "Y" : "N");
        std::cout << (my_v1 >= my_v3 ? "Y" : "N");
      }
    }
    {
      {
        std::cout
            << std::endl
            << std::endl
            << BOLDCYAN
            "/*************************************************************/"
            << std::endl
            << "/                            PAIR                             "
               " /"
            << std::endl
            << "/*************************************************************"
               "/" END
            << std::endl;
      }

      ft::pair<int, char> pair = ft::make_pair(1, 'a');
      ft::pair<int, char> pair2 = ft::make_pair(2, 'b');
      std::cout << pair.first << " " << pair.second << std::endl;
      std::cout << pair2.first << " " << pair2.second << std::endl;
      swap(pair, pair2);
      std::cout << pair.first << " " << pair.second << std::endl;
      std::cout << pair2.first << " " << pair2.second << std::endl;
      std::cout << (pair == pair2 ? "Y" : "N");
      std::cout << (pair != pair2 ? "Y" : "N");
      std::cout << (pair <= pair2 ? "Y" : "N");
      std::cout << (pair >= pair2 ? "Y" : "N");
      std::cout << (pair < pair2 ? "Y" : "N");
      std::cout << (pair > pair2 ? "Y" : "N");
    }
  }

  catch (std::exception &e) {
  };
}