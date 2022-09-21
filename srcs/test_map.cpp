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

  std::cout << std::endl;

  chrono.begin();
  for (int i = 0; i < 100000; i++) {
    int n = rand() % 100000;
    my_m.insert(ft::pair<int, char>(n, '$'));
  }
  chrono.stop();
  for (int i = 0; i < 100000; i++) {
    int n = rand() % 100000;
    m.insert(std::pair<int, char>(n, '$'));
  }
  chrono.stop();
}