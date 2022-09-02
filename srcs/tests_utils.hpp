#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

#include <vector>

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
void printDiffVector(ft::vector<T> my_v, std::vector<T> v) {
  bool success = true;
  if (my_v.size() != v.size()) {
    std::cout << BOLDRED "Diff KO - size " END;
    success = false;
  }
  if (my_v.capacity() != v.capacity()) {
    std::cout << BOLDRED "Diff KO - capacity " END;
    success = false;
  }
  if (success)
    for (unsigned long long int i = 0; i < my_v.size(); i++) {
      if (my_v[i] != v[i]) {
        std::cout << BOLDRED "Diff KO - content " END;
        std::cout << " - Error at [" << i << "]";
        success = false;
        break;
      }
    }
  if (success) std::cout << BOLDGREEN "OK " END;
};

template <class T>
void printSimpleFtVector(ft::vector<T> my_v) {
  if (my_v.empty()) return;
  for (unsigned long long int i = 0; i < my_v.size(); i++)
    std::cout << my_v[i] << (i != my_v.size() - 1 ? " - " : "");
  std::cout << std::endl;
}

template <class T>
void printSimpleStdVector(std::vector<T> v) {
  if (v.empty()) return;
  for (unsigned long long int i = 0; i < v.size(); i++)
    std::cout << v[i] << (i != v.size() - 1 ? " - " : "");
  std::cout << std::endl;
}

class bli {
 public:
  bli() : int_(1), char_('a'), string_("bla") {}
  bli(const int& i, const char& c, const std::string& s)  // NOLINT
      : int_(i), char_(c), string_(s) {}
  ~bli();
  int int_;
  char char_;
  std::string string_;
};

bool operator==(const bli& x, const bli& y);
void print_Ftbli(ft::vector<bli> v);

// void print_Ftbli(ft::vector<bli> v) {
//   for (unsigned long i = 0; i < v.size(); i++) {
//     std::cout << v[i].int_ << " " << v[i].char_ << " " << v[i].string_
//               << (i != v.size() - 1 ? " - " : "");
//   }
//   std::cout << std::endl;
// }

// bool operator==(const bli& x, const bli& y) {
//   return ((x.int_ == y.int_) && (x.char_ == y.char_) &&
//           (x.string_ == y.string_));
// }
#endif

// TODO : write specializations for bli classes // enable if is integral