#include <map>
#include <stdexcept>

#include "bstree.hpp"
#include "chrono.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include "pair.hpp"
#include "tests_utils.hpp"
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
  {
    /* PERF TEST : INSERT */
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

    /* PERF TEST : ERASE */
    /* PERF TEST : FIND */
  }
  {
    /* CONSTRUCTORS */
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
    // ft::map<int, char> my_m_it_cpy(my_m_it.begin(), my_m_it.end()); );
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
}