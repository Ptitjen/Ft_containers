
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

#include "Chrono.hpp"

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

void print_int_stdvector(std::vector<int> v) {
  std::cout << BLUE "Size " END << v.size() << std::endl;
  std::cout << BLUE "Capacity :  " END << v.capacity() << std::endl;
  std::cout << BLUE "Content : " END;
  if (v.empty()) return;

  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_longint_stdvector(std::vector<long int> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_unsignedint_stdvector(std::vector<unsigned int> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_str_stdvector(std::vector<std::string> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}

int main(void) {
  Chrono chrono = Chrono("Small vector functions", "Large vector");
  chrono.begin();
  // std::cout << std::endl
  //           << BOLDMAGENTA "----- My vector -----" END << std::endl;
  { /* Constructor empty vector => ok */
    std::cout << BOLDGREEN "******* Vector *******" END << std::endl;

    std::cout << BOLDCYAN "Default constructor - empty vector" END << std::endl;
    std::vector<int> v = std::vector<int>();
    print_int_stdvector(v);
    std::cout << CYAN "Max size : " END << v.max_size() << std::endl;
    std::cout << BOLDCYAN "Push back : " END << std::endl;
    v.push_back(1);
    std::cout << "Access [0] : " << v[0] << std::endl;
    v.push_back(2);
    print_int_stdvector(v);
    std::cout << v[1] << std::endl;
    v.push_back(3);
    print_int_stdvector(v);
    v.push_back(4);
    print_int_stdvector(v);
    v.push_back(5);
    print_int_stdvector(v);
    v.push_back(6);
    print_int_stdvector(v);
    v.push_back(7);
    print_int_stdvector(v);
    v.push_back(8);
    print_int_stdvector(v);
    v.push_back(9);
    print_int_stdvector(v);
    std::cout << CYAN "Back : " END << v.back() << std::endl;
    std::cout << BOLDCYAN "Pop back" END << std::endl;
    v.pop_back();
    print_int_stdvector(v);

    std::cout << CYAN "Back : " END << v.back() << std::endl;
    std::cout << CYAN "Front : " END << v.front() << std::endl;

    std::cout << BOLDCYAN "At" END << std::endl;
    std::cout << "At 1 : " << v.at(1) << std::endl;
    try {
      std::cout << "At 80 : " << v.at(80) << std::endl;
    } catch (std::exception& e) {
      std::cout << "Exception caught" << std::endl;
    }

    std::cout << BOLDCYAN "Begin : " END << *v.begin() << std::endl;

    std::cout << BOLDCYAN "Resize 15 with 1: " END << std::endl;
    v.resize(15, 1);
    print_int_stdvector(v);

    std::cout << BOLDCYAN "Resize 20 with nothing: " END << std::endl;
    v.resize(20);
    print_int_stdvector(v);

    std::cout << BOLDCYAN "reserve 30 : " END << std::endl;
    v.reserve(30);
    print_int_stdvector(v);
    std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

    std::cout << BOLDCYAN "Resize to smaller : " END << std::endl;
    v.resize(8);
    print_int_stdvector(v);

    std::cout << "Iterator + : v.begin() + 2 : " << *(v.begin() + 2)
              << std::endl;
    std::cout << "Iterator - : v.end() - 2 : " << *(v.end() - 2) << std::endl;

    std::cout << BOLDCYAN "Insert :" END << std::endl;

    std::cout << "Insert one value 42 at begin: " << std::endl;
    std::cout << "Return value : " RED << *(v.insert(v.begin(), 42)) << END
              << std::endl;
    print_int_stdvector(v);

    std::cout << "Insert one value 42 at position 2: " << std::endl;
    std::cout << "Return value : " RED << *(v.insert(v.begin() + 2, 42)) << END
              << std::endl;
    print_int_stdvector(v);

    std::cout << "Insert multiple value 42 42 42 42 at position 7 : "
              << std::endl;
    v.insert(v.begin() + 7, 4, 42);
    print_int_stdvector(v);

    std::vector<int> to_insert(3, 42);
    to_insert[1] = 43;
    to_insert[2] = 44;
    std::cout << "Insert vector 42 43 44: " << std::endl;
    v.insert(v.begin() + 4, to_insert.begin(), to_insert.end());
    print_int_stdvector(v);

    std::cout << BOLDCYAN "Erase" END << std::endl;
    std::cout << CYAN "Erase position 2 : " END << std::endl;
    std::cout << "Return value : " RED << *(v.erase(v.begin() + 2)) << END
              << std::endl;
    print_int_stdvector(v);

    std::cout << CYAN "Erase begin : " END << std::endl;
    std::cout << "Return value : " RED << *(v.erase(v.begin())) << END
              << std::endl;
    print_int_stdvector(v);

    std::cout << CYAN "Erase from 2 to 5 (excluding 5): " END << std::endl;
    std::cout << "Return value : " RED
              << *(v.erase(v.begin() + 2, v.begin() + 5)) << END << std::endl;
    print_int_stdvector(v);

    std::cout << CYAN "Erase from 5 to 9 (excluding 9): " END << std::endl;
    std::cout << "Return value : " RED
              << *(v.erase(v.begin() + 5, v.begin() + 9)) << END << std::endl;
    print_int_stdvector(v);

    std::cout << "Adress of v : " << &v << std::endl;
    std::cout << "Adress of other : " << &to_insert << std::endl;
    std::cout << BOLDCYAN "Swap with 42 43 44" END << std::endl;
    v.swap(to_insert);
    std::cout << "Adress of v : " << &v << std::endl;
    std::cout << "New vector : ";
    print_int_stdvector(v);
    std::cout << "Other vector : " << std::endl;
    std::cout << "Adress of other : " << &to_insert << std::endl;
    print_int_stdvector(to_insert);

    std::cout << BOLDCYAN "Clear" END << std::endl;
    v.clear();
    print_int_stdvector(v);
    std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

    std::vector<int> to_assign;

    to_assign.push_back(5);
    to_assign.push_back(4);
    to_assign.push_back(3);
    to_assign.push_back(2);
    to_assign.push_back(1);

    std::cout << BOLDCYAN "Assign on empty vector: " END << std::endl;
    std::cout << "on empty vector with other vector 5 4 3 2 1 (5 values): "
              << std::endl;
    v.assign(to_assign.begin(), to_assign.begin() + 5);
    print_int_stdvector(v);

    std::cout << "on not empty vector with other vector 5 4 3 2 1 (2 values): "
              << std::endl;
    v.assign(to_assign.begin(), to_assign.begin() + 2);
    print_int_stdvector(v);

    std::cout << "on not empty vector with value 42 (5 values): " << std::endl;
    v.assign(5, 42);
    print_int_stdvector(v);

    std::cout << BOLDCYAN "Reverse iterator" END << std::endl;
    std::vector<int> myvector;  // 5 default-constructed ints
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);
    std::cout << "My vector : " << std::endl;
    print_int_stdvector(myvector);

    std::cout << "Printing vector with iterator : " << std::endl;
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end();
         ++it) {
      std::cout << *it << std::endl;
    }  // ok

    std::cout << "Reverse printing vector with iterator : " << std::endl;
    for (std::vector<int>::iterator it = myvector.end(); it != myvector.begin();
         --it) {
      std::cout << *(it - 1) << std::endl;
    }  // ok

    std::cout << "Printing vector with reverse iterator : " << std::endl;
    std::cout << "End adress : " << &*(myvector.end()) << std::endl;
    std::cout << "Rbegin adress : " << &*(myvector.rbegin()) << std::endl;
    for (std::vector<int>::reverse_iterator it = myvector.rend();
         it != myvector.rbegin(); --it) {
      std::cout << *(it - 1) << std::endl;
    }
    std::cout << "Reverse printing vector with reverse iterator : "
              << std::endl;
    for (std::vector<int>::reverse_iterator it = myvector.rbegin();
         it != myvector.rend(); ++it) {
      std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    /* Operateur d'affectation */
    std::vector<int> cpy;
    cpy = v;
    std::cout << BOLDCYAN "Affectation operator : " END << std::endl;
    print_int_stdvector(cpy);
    cpy[0] = 100;
    print_int_stdvector(cpy);
    std::cout << "Verifying original : " << std::endl;
    print_int_stdvector(v);
    std::cout << std::endl;

    /* Constructeur de recopie */
    std::cout << BOLDCYAN "Copy constructor : " END << std::endl;
    std::vector<int> cpy2(v);
    print_int_stdvector(cpy2);
    cpy2[0] = 200;
    print_int_stdvector(cpy2);
    std::cout << "Verifying original : " << std::endl;
    print_int_stdvector(v);
  }

  /***** Constructor vector(nb elem) *****/
  {
    std::cout << BOLDCYAN "Vector of 4 int without value : " END << std::endl;
    std::vector<int> v = std::vector<int>(4);
    print_int_stdvector(v);
    v[0] = 1;
    print_int_stdvector(v);
  }

  /***** Constructor vector(nb elem, value) *****/
  {
    std::cout << BOLDCYAN "Vector of 10 unsigned int with value 42 : " END
              << std::endl;
    unsigned int i = 42;
    std::vector<unsigned int> v = std::vector<unsigned int>(10, i);
    std::cout << v.size() << std::endl;
    std::cout << v.max_size() << std::endl;
    std::cout << v.capacity() << std::endl;
    print_unsignedint_stdvector(v);
  }
  {
    std::cout << BOLDCYAN "Vector of 10 int with value 42 : " END << std::endl;
    int i = 42;
    std::vector<int> v = std::vector<int>(10, i);
    print_int_stdvector(v);
  }
  {
    std::cout << BOLDCYAN "Vector of 10 string with value bla : " END
              << std::endl;
    std::vector<std::string> v = std::vector<std::string>(10, "bla");
    print_str_stdvector(v);
  }
  // TODO
  /*****Iterator constructor *****/
  {
    std::cout << BOLDCYAN "Constructor using iterators :" END << std::endl;

    std::vector<int> v = std::vector<int>(3, 1);
    std::vector<int> my_v(v.begin(), v.end());
    print_int_stdvector(v);
    print_int_stdvector(my_v);
    my_v[0] = 42;
    print_int_stdvector(v);
    print_int_stdvector(my_v);
  }
  chrono.stop();

  {
    std::cout << BOLDCYAN "Performance - vector of 1000000 int" END
              << std::endl;
    std::cout << "Large vector : " << std::endl;
    std::vector<int> large_v = std::vector<int>(1000000, 42);
    large_v.push_back(1);
    large_v.pop_back();
    std::cout << "Accessor : " << large_v[888888] << std::endl;
    std::cout << "At : " << large_v.at(500000) << std::endl;
    std::cout << "Size : " << large_v.size() << std::endl;
    std::cout << "Begin : " << *large_v.begin() << std::endl;
    large_v.insert(large_v.begin() + 500000, 43);
    std::cout << "insert at 500000 : " << large_v[500000] << std::endl;
    large_v.erase(large_v.begin() + 500000);
    std::cout << "insert at 500000 : " << large_v[500000] << std::endl;

    std::vector<int> large_v_swap = std::vector<int>(999999, 41);
    large_v.swap(large_v_swap);
    std::cout << "After swap with 999999 vector of 41 :" << std::endl
              << "Accessor :" << large_v[450000] << std::endl
              << "Size : " << large_v.size() << std::endl;
    std::cout << "Other swapped vector :" << std::endl
              << "Accessor :" << large_v_swap[450000] << std::endl
              << "Size : " << large_v_swap.size() << std::endl;

    chrono.stop();
  }
}
