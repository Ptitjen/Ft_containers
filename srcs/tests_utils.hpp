#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include <stack>
#include <utility>
#include <vector>

#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"

#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#define END "\033[0m"

template <class T>
void printDiffVector(ft::vector<T>& my_v, std::vector<T>& v) {
  bool success = true;
  if (my_v.size() != v.size()) {
    std::cout << BOLDRED "Diff KO - size " END;
    success = false;
  }

  // if (my_v.capacity() != v.capacity()) {
  //   std::cout << BOLDRED "Diff KO - capacity " END;
  //   success = false;
  //   std::cout << std::endl << my_v.capacity() << " " << v.capacity() << " ";
  // }
  if (success)
    for (unsigned long long int i = 0; i < my_v.size(); i++) {
      if (!(my_v[i] == v[i])) {
        std::cout << BOLDRED "Diff KO - content " END;
        std::cout << " - Error at [" << i << "]";
        success = false;
        break;
      }
    }
  if (success) std::cout << BOLDGREEN "OK " END;
};

template <class T>
void printDiffStack(ft::stack<T>& my_v, std::stack<T>& v) {
  bool success = true;
  if (my_v.size() != v.size()) {
    std::cout << BOLDRED "Diff KO - size " END;
    success = false;
  }

  if (success)
    while (!my_v.empty()) {
      if (!(my_v.top() == v.top())) {
        std::cout << BOLDRED "Diff KO - content " END;
        success = false;
        break;
      }
      my_v.pop();
      v.pop();
    }
  if (success) std::cout << BOLDGREEN "OK " END;
};

template <class T1, class T2>
void printDiffPair(ft::pair<T1, T2>& my_v, std::pair<T1, T2>& v) {
  bool success = true;
  if (my_v.first != v.first) {
    std::cout << BOLDRED "Diff KO - first " END;
    success = false;
  }
  if (my_v.second != v.second) {
    std::cout << BOLDRED "Diff KO - first " END;
    success = false;
  }
  if (success) std::cout << BOLDGREEN "OK " END;
};

template <class T>
void printSimpleFtVector(ft::vector<T>& my_v) {
  if (my_v.empty()) return;
  for (unsigned long long int i = 0; i < my_v.size(); i++)
    std::cout << my_v[i] << (i != my_v.size() - 1 ? " - " : "");
  std::cout << std::endl;
}

template <class T>
void printSimpleStdVector(std::vector<T>& v) {
  if (v.empty()) return;
  for (unsigned long long int i = 0; i < v.size(); i++)
    std::cout << v[i] << (i != v.size() - 1 ? " - " : "");
  std::cout << std::endl;
}

class bli {
 public:
  bli() : int_(1), char_('a') {}
  bli(const int& i, const char& c)  // NOLINT
      : int_(i), char_(c) {}
  ~bli(){};
  int int_;
  char char_;
};

bool operator==(const bli& x, const bli& y);
void print_Ftbli(ft::vector<bli> v);

class ThrowingConstructor {
 public:
  ThrowingConstructor() { throw std::exception(); }
};
#endif
