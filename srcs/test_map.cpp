#include <map>
#include <stdexcept>

#include "bstree.hpp"
#include "chrono.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "tests_utils.hpp"

template <class T, class U>
void printMap(ft::map<T, U>& my_m, std::map<T, U>& m) {
  bool success = true;

  for (typename ft::map<T, U>::iterator it = my_m.begin(); it != my_m.end();
       it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  for (typename std::map<T, U>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}

template <class T, class U>
void printDiffMap(ft::map<T, U>& my_m, std::map<T, U>& m) {
  bool success = true;
  if (my_m.size() != m.size()) {
    std::cout << BOLDRED "KO - Size " END;
    success = false;
  }
  typename std::map<T, U>::iterator itm = m.begin();
  for (typename ft::map<T, U>::iterator it = my_m.begin(); it != my_m.end();
       it++) {
    if (it->first != itm->first || it->second != itm->second) {
      std::cout << BOLDRED "KO Content " END;
      success = false;
    }
    itm++;
  }
  if (success) std::cout << BOLDGREEN "OK " END;
}

int main(void) {
  Chrono chrono = Chrono("My map", "Std map");
  {
    std::cout << BOLDBLUE "********* Basic tests *********" END << std::endl;
    /* SOME BASIC TESTS */
    ft::map<int, char> my_m;
    std::map<int, char> m;
    printDiffMap(my_m, m);
    my_m.insert(ft::pair<int, char>(1, 'a'));
    m.insert(std::pair<int, char>(1, 'a'));
    printDiffMap(my_m, m);
    for (int i = 0; i < 10000; i++) {
      int n = rand() % 1000;
      my_m.insert(ft::pair<int, char>(n, '@'));
      m.insert(std::pair<int, char>(n, '@'));
    }
    for (int i = 0; i < 5000; i++) {
      int n = rand() % 1000;
      my_m.insert(ft::pair<int, char>(n, '#'));
      m.insert(std::pair<int, char>(n, '#'));
    }
    printDiffMap(my_m, m);
  }
  std::cout << std::endl;
  /* ***************************************************************** */
  /*                          PERFORMANCE                              */
  /* ***************************************************************** */
  {
    std::cout << BOLDBLUE "********* Performance *********" END << std::endl;
    {
      /* PERF TEST : INSERT */
      std::cout << "Insert: ";

      Chrono chrono = Chrono("My map", "Std map");

      ft::map<int, char> my_m;
      std::map<int, char> m;
      chrono.begin();
      for (int i = 0; i < 1000000; i++) {
        int n = rand() % 1000000;
        my_m.insert(ft::pair<int, char>(n, '$'));
      }
      chrono.stop();
      for (int i = 0; i < 1000000; i++) {
        int n = rand() % 1000000;
        m.insert(std::pair<int, char>(n, '$'));
      }
      chrono.stop();
    }
    /* PERF TEST : ERASE */
    {
      std::cout << "Erase: ";

      Chrono chrono = Chrono("My map", "Std map");

      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 0; i < 1000000; i++) {
        my_m.insert(ft::pair<int, char>(i, '$'));
      }
      for (int i = 0; i < 1000000; i++) {
        m.insert(std::pair<int, char>(i, '$'));
      }
      chrono.begin();
      my_m.erase(1);
      my_m.erase(50000);
      my_m.erase(100000);
      my_m.erase(500000);
      chrono.stop();
      m.erase(1);
      m.erase(50000);
      m.erase(100000);
      m.erase(500000);
      chrono.stop();
    }
    /* PERF TEST : FIND */
    {
      std::cout << "Find: ";

      Chrono chrono = Chrono("My map", "Std map");

      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 0; i < 1000000; i++) {
        my_m.insert(ft::pair<int, char>(i, '$'));
      }
      for (int i = 0; i < 1000000; i++) {
        m.insert(std::pair<int, char>(i, '$'));
      }
      chrono.begin();
      for (int i = 0; i < 1000000; i++) {
        my_m.find(i);
      }
      chrono.stop();
      for (int i = 0; i < 1000000; i++) {
        my_m.find(i);
      }
      chrono.stop();
    }
  }
  /* ***************************************************************** */
  /*                          CONSTRUCTORS                             */
  /* ***************************************************************** */
  {
    std::cout << BOLDBLUE "********* Constructors *********" END << std::endl;

    /* default */
    ft::map<int, char> my_m;
    std::map<int, char> m;
    printDiffMap(my_m, m);

    /* iterators */  // PB
    ft::map<int, char> my_m_it;
    std::map<int, char> m_it;
    for (int i = 0; i < 100; i++) {
      int n = rand() % 100;
      my_m_it.insert(ft::pair<int, char>(n, '@'));
      m_it.insert(std::pair<int, char>(n, '@'));
    }

    /**************** TO DO *******************/
    // ft::map<int, char> my_m_it_cpy(my_m_it.begin(), my_m_it.end());
    // std::map<int, char> m_it_cpy(m_it.begin(), m_it.end());
    // printDiffMap(my_m, m);

    /* = */
    my_m.insert(ft::pair<int, char>(0, '#'));
    m.insert(std::pair<int, char>(0, '#'));
    my_m.insert(ft::pair<int, char>(9, '&'));
    m.insert(std::pair<int, char>(9, '&'));
    ft::map<int, char> my_m1;
    my_m1 = my_m;
    std::map<int, char> m1;
    m1 = m;
    printDiffMap(my_m1, m1);
    my_m1.insert(ft::pair<int, char>(1, 'a'));
    m1.insert(std::pair<int, char>(1, 'a'));
    printDiffMap(my_m, m);
    printDiffMap(my_m1, m1);

    /* () */
    ft::map<int, char> my_m2(my_m1);
    std::map<int, char> m2(m1);
    printDiffMap(my_m2, m2);
    my_m2.insert(ft::pair<int, char>(2, 'b'));
    m2.insert(std::pair<int, char>(2, 'b'));
    printDiffMap(my_m, m);
    printDiffMap(my_m1, m1);
    printDiffMap(my_m2, m2);
  }

  /* ***************************************************************** */
  /*                          ITERATORS                                */
  /* ***************************************************************** */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Iterators *********" END << std::endl;
    ft::map<int, char> my_m;
    std::map<int, char> m;

    for (int i = 33; i < 65; i++) {
      my_m.insert(ft::pair<int, char>(i, (char)i));
      m.insert(std::pair<int, char>(i, (char)i));
    }
    printDiffMap(my_m, m);

    std::cout << std::endl << BOLDCYAN "Iterator increment" END << std::endl;

    std::map<int, char>::iterator itm = m.begin();
    bool success = true;
    for (ft::map<int, char>::iterator it = my_m.begin(); it != my_m.end();
         it++) {
      if (it->first != itm->first || it->second != itm->second) {
        std::cout << BOLDRED "KO " END;
        success = false;
        break;
      }
      itm++;
    }
    if (success) std::cout << BOLDGREEN "OK " END;
    success = true;
    std::cout << std::endl << BOLDCYAN "Iterator decrement" END << std::endl;
    std::map<int, char>::iterator itme = m.end();
    for (ft::map<int, char>::iterator it = my_m.end(); it != my_m.begin();
         it--) {
      ft::map<int, char>::iterator itc = it;
      itc--;
      itme--;
      if (itc->first != itme->first || itc->second != itme->second) {
        std::cout << BOLDRED "KO " END;
        success = false;

        break;
      }
    }
    if (success) std::cout << BOLDGREEN "OK " END;
    success = true;
    std::cout << std::endl
              << BOLDCYAN "Reverse iterator increment" END << std::endl;
    std::map<int, char>::reverse_iterator ritm = m.rbegin();
    for (ft::map<int, char>::reverse_iterator it = my_m.rbegin();
         it != my_m.rend(); it++) {
      if (it->first != ritm->first || it->second != ritm->second) {
        std::cout << BOLDRED "KO " END;
        success = false;
        break;
      }
      ritm++;
    }
    if (success) std::cout << BOLDGREEN "OK " END;
    success = true;
    std::cout << std::endl
              << BOLDCYAN "Reverse iterator decrement" END << std::endl;
    std::map<int, char>::reverse_iterator ritme = m.rend();
    for (ft::map<int, char>::reverse_iterator it = my_m.rend();
         it != my_m.rbegin(); it--) {
      ft::map<int, char>::reverse_iterator itc = it;
      itc--;
      ritme--;
      if (itc->first != ritme->first || itc->second != ritme->second) {
        std::cout << BOLDRED "KO " END;
        success = false;
        break;
      }
    }
    if (success) std::cout << BOLDGREEN "OK " END;
  }
  /* ***************************************************************** */
  /*                          CAPACITY                                 */
  /* ***************************************************************** */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Capacity *********" END << std::endl;
    ft::map<int, char> my_m;
    std::map<int, char> m;
    std::cout << "Empty: ";
    std::cout << (m.empty() == my_m.empty() ? BOLDGREEN "OK " END
                                            : BOLDRED "KO " END);

    for (int i = 33; i < 65; i++) {
      my_m.insert(ft::pair<int, char>(i, (char)i));
      m.insert(std::pair<int, char>(i, (char)i));
    }
    std::cout << (m.empty() == my_m.empty() ? BOLDGREEN "OK " END
                                            : BOLDRED "KO " END);
    std::cout << std::endl;
    std::cout << "Size: ";
    std::cout << (m.size() == my_m.size() ? BOLDGREEN "OK " END
                                          : BOLDRED "KO " END);
  }
  /* ***************************************************************** */
  /*                          ELEMENT ACCESS                           */
  /* ***************************************************************** */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Element access *********" END << std::endl;
    ft::map<int, char> my_m;
    std::map<int, char> m;
    for (int i = 33; i < 65; i++) {
      my_m.insert(ft::pair<int, char>(i, (char)i));
      m.insert(std::pair<int, char>(i, (char)i));
    }
    std::cout
        << "Size before access [] to not existing element => adds element :"
        << m.size() << " " << my_m.size() << std::endl;

    std::cout << (my_m[32] == m[32] ? BOLDGREEN "OK " END
                                    : BOLDRED
                      "KO " END);  // does not exist : add
    std::cout << std::endl
              << "Size after => added element :" << m.size() << " "
              << my_m.size() << std::endl;
    std::cout << (my_m[33] == m[33] ? BOLDGREEN "OK " END : BOLDRED "KO " END);
    std::cout << (my_m[61] == m[61] ? BOLDGREEN "OK " END : BOLDRED "KO " END);
    std::cout << (my_m[75] == m[75] ? BOLDGREEN "OK " END : BOLDRED "KO " END);
    printDiffMap(my_m, m);
    my_m[75] = 'A';
    m[75] = 'A';
    printDiffMap(my_m, m);
    my_m[87] = 'B';
    m[87] = 'B';
    my_m[60] = 'C';
    m[60] = 'C';
    printDiffMap(my_m, m);
  }
  /* ***************************************************************** */
  /*                              MODIFIERS                            */
  /* ***************************************************************** */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Modifiers *********" END << std::endl;
    std::cout << std::endl << "Basic insert : " << std::endl;
    {
      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 33; i < 65; i++) {
        int n = rand() % 32 + 33;
        my_m.insert(ft::pair<int, char>(n, (char)n));
        m.insert(std::pair<int, char>(n, (char)n));
      }
      for (int i = 33; i < 65; i++) {
        int n = rand() % 32 + 33;
        my_m.insert(ft::pair<int, char>(n, (char)n));
        m.insert(std::pair<int, char>(n, (char)n));
      }
      printDiffMap(my_m, m);
    }

    std::cout << std::endl << "Hint insert : " << std::endl;
    {
      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 33; i < 65; i++) {
        i++;
        my_m.insert(ft::pair<int, char>(i, (char)i));
        m.insert(std::pair<int, char>(i, (char)i));
      }
      for (int i = 33; i < 65; i++) {
        my_m.insert(my_m.find(i - 1), ft::pair<int, char>(i, (char)i));
        m.insert(m.find(i - 1), std::pair<int, char>(i, (char)i));
      }

      printDiffMap(my_m, m);
    }
    std::cout << std::endl << "Iterator insert : " << std::endl;
    {
      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 33; i < 65; i++) {
        i++;
        my_m.insert(ft::pair<int, char>(i, (char)i));
        m.insert(std::pair<int, char>(i, (char)i));
      }
      ft::map<int, char> my_m1;
      std::map<int, char> m1;
      for (int i = 32; i < 64; i++) {
        i++;
        my_m1.insert(ft::pair<int, char>(i, (char)i));
        m1.insert(std::pair<int, char>(i, (char)i));
      }
      my_m.insert(my_m1.begin(), my_m1.end());
      m.insert(m1.begin(), m1.end());
      printDiffMap(my_m, m);

      std::cout << std::endl << "Erase iterator : " << std::endl;
      my_m.erase(my_m.find(33));
      m.erase(m.find(33));
      printDiffMap(my_m, m);
      my_m.erase(my_m.begin());
      m.erase(m.begin());
      printDiffMap(my_m, m);
      my_m.erase(my_m.find(45));
      m.erase(m.find(45));
      printDiffMap(my_m, m);
      my_m.erase(my_m.find(63));
      m.erase(m.find(63));
      printDiffMap(my_m, m);

      std::cout << std::endl << "Erase key : " << std::endl;
      my_m.erase(47);
      m.erase(47);
      printDiffMap(my_m, m);
      my_m.erase(0);
      m.erase(0);
      printDiffMap(my_m, m);
      my_m.erase(62);
      m.erase(62);
      printDiffMap(my_m, m);
      my_m.erase(51);
      m.erase(51);
      printDiffMap(my_m, m);
    }
    {
      std::cout << std::endl << "Erase iterator : " << std::endl;

      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 33; i < 65; i++) {
        my_m.insert(ft::pair<int, char>(i, (char)i));
        m.insert(std::pair<int, char>(i, (char)i));
      }
      my_m.erase(my_m.find(35), my_m.find(55));
      m.erase(m.find(35), m.find(55));
      printDiffMap(my_m, m);
    }
    {
      std::cout << std::endl << "Swap : " << std::endl;
      ft::map<int, char> my_m;
      std::map<int, char> m;
      for (int i = 33; i < 65; i++) {
        i++;
        my_m.insert(ft::pair<int, char>(i, (char)i));
        m.insert(std::pair<int, char>(i, (char)i));
      }
      ft::map<int, char> my_m1;
      std::map<int, char> m1;
      for (int i = 32; i < 64; i++) {
        i++;
        my_m1.insert(ft::pair<int, char>(i, (char)i));
        m1.insert(std::pair<int, char>(i, (char)i));
      }
      printDiffMap(my_m, m);
      my_m.swap(my_m1);
      m.swap(m1);
      my_m1.insert(ft::pair<int, char>(8, '*'));
      m1.insert(std::pair<int, char>(8, '*'));
      my_m.insert(ft::pair<int, char>(7, '~'));
      m.insert(std::pair<int, char>(7, '~'));
      printDiffMap(my_m, m);
      printDiffMap(my_m1, m1);

      std::cout << std::endl << "Clear : " << std::endl;

      my_m.clear();
      m.clear();
      printDiffMap(my_m, m);

      ft::map<int, char> my_m3;
      std::map<int, char> m3;
      my_m3.clear();
      m3.clear();
      printDiffMap(my_m3, m3);
    }
  }

  /* ********************************************************************  */
  /*                                 OPERATIONS                            */
  /* ********************************************************************  */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Operations *********" END << std::endl;
    std::cout << std::endl << "Find : " << std::endl;

    ft::map<int, char> my_m;
    std::map<int, char> m;
    for (int i = 33; i < 65; i++) {
      my_m.insert(ft::pair<int, char>(i, (char)i));
      m.insert(std::pair<int, char>(i, (char)i));
    }
    std::cout << (my_m.find(33)->first == m.find(33)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.find(53)->first == m.find(53)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.find(25) == my_m.end() && m.find(25) == m.end()
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);

    std::cout << std::endl << "Count : " << std::endl;

    std::cout << (my_m.count(33) == m.count(33) ? BOLDGREEN "OK " END
                                                : BOLDRED "KO " END);

    std::cout << (my_m.count(25) == m.count(25) ? BOLDGREEN "OK " END
                                                : BOLDRED "KO " END);

    std::cout << std::endl << "Lower & Upper Bounds : " << std::endl;

    std::cout << (my_m.lower_bound(33)->first == m.lower_bound(33)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);

    std::cout << (my_m.upper_bound(33)->first == m.upper_bound(33)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.lower_bound(33)->first == m.lower_bound(33)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.lower_bound(45)->first == m.lower_bound(45)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.upper_bound(45)->first == m.upper_bound(45)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.lower_bound(63)->first == m.lower_bound(63)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.upper_bound(63)->first == m.upper_bound(63)->first
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.lower_bound(68) == my_m.end() &&
                          m.lower_bound(68) == m.end()
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.upper_bound(68) == my_m.end() &&
                          m.upper_bound(68) == m.end()
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);

    std::cout << std::endl << "Equal range : " << std::endl;

    std::cout << (my_m.equal_range(33).first->first ==
                              m.equal_range(33).first->first &&
                          my_m.equal_range(33).first->second ==
                              m.equal_range(33).first->second &&
                          my_m.equal_range(33).second->first ==
                              m.equal_range(33).second->first &&
                          my_m.equal_range(33).second->second ==
                              m.equal_range(33).second->second
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
    std::cout << (my_m.equal_range(45).first->first ==
                              m.equal_range(45).first->first &&
                          my_m.equal_range(45).first->second ==
                              m.equal_range(45).first->second &&
                          my_m.equal_range(45).second->first ==
                              m.equal_range(45).second->first &&
                          my_m.equal_range(45).second->second ==
                              m.equal_range(45).second->second
                      ? BOLDGREEN "OK " END
                      : BOLDRED "KO " END);
  }

  /* ********************************************************************  */
  /*                                 NON MEMBER FUNCTIONS */
  /* ********************************************************************  */
  {
    std::cout << std::endl
              << BOLDBLUE "********* Non member functions *********" END
              << std::endl;
    std::cout << std::endl << "Comparison : " << std::endl;
    ft::map<int, char> my_m;
    std::map<int, char> m;
    for (int i = 33; i < 65; i++) {
      my_m.insert(ft::pair<int, char>(i, (char)i));
      m.insert(std::pair<int, char>(i, (char)i));
    }
    ft::map<int, char> my_m1;
    std::map<int, char> m1;
    for (int i = 33; i < 65; i++) {
      my_m1.insert(ft::pair<int, char>(i, (char)i));
      m1.insert(std::pair<int, char>(i, (char)i));
    }

    std::cout << ((my_m == my_m1) == (m == m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m < my_m1) == (m < m1) ? BOLDGREEN "OK " END
                                             : BOLDRED "KO " END);
    std::cout << ((my_m <= my_m1) == (m <= m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m > my_m1) == (m > m1) ? BOLDGREEN "OK " END
                                             : BOLDRED "KO " END);
    std::cout << ((my_m >= my_m1) == (m >= m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m != my_m1) == (m != m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    my_m1.insert(ft::pair<int, char>(98, '@'));
    m1.insert(std::pair<int, char>(98, '@'));
    std::cout << ((my_m == my_m1) == (m == m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m < my_m1) == (m < m1) ? BOLDGREEN "OK " END
                                             : BOLDRED "KO " END);
    std::cout << ((my_m <= my_m1) == (m <= m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m > my_m1) == (m > m1) ? BOLDGREEN "OK " END
                                             : BOLDRED "KO " END);
    std::cout << ((my_m >= my_m1) == (m >= m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);
    std::cout << ((my_m != my_m1) == (m != m1) ? BOLDGREEN "OK " END
                                               : BOLDRED "KO " END);

    std::cout << std::endl << "Swap : " << std::endl;
    swap(my_m, my_m1);
    swap(m, m1);
    printDiffMap(my_m, m);

    printDiffMap(my_m1, m1);
  }
}