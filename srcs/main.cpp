#ifndef MAIN_CPP
#define MAIN_CPP
#include <exception>
#include <iostream>
#include <iterator>

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

void print_int_ftvector(ft::vector<int> v) {
  std::cout << BLUE "Size " END << v.size() << std::endl;
  std::cout << BLUE "Capacity :  " END << v.capacity() << std::endl;
  std::cout << BLUE "Content : " END;
  if (v.empty()) return;

  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_longint_ftvector(ft::vector<long int> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_unsignedint_ftvector(ft::vector<unsigned int> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}
void print_str_ftvector(ft::vector<std::string> v) {
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i++) std::cout << " | " << v[i];
  std::cout << " |" << std::endl;
}

int main(void) {
  // std::cout << std::endl
  //           << BOLDMAGENTA "----- My vector -----" END << std::endl;
  { /* Constructor empty vector => ok */
    std::cout << BOLDCYAN "Default constructor - empty vector" END << std::endl;
    ft::vector<int> v = ft::vector<int>();
    print_int_ftvector(v);
    std::cout << CYAN "Max size : " END << v.max_size() << std::endl;
    std::cout << BOLDCYAN "Push back : " END << std::endl;
    v.push_back(1);
    std::cout << "Access [0] : " << v[0] << std::endl;
    v.push_back(2);
    print_int_ftvector(v);
    std::cout << v[1] << std::endl;
    v.push_back(3);
    print_int_ftvector(v);
    v.push_back(4);
    print_int_ftvector(v);
    v.push_back(5);
    print_int_ftvector(v);
    v.push_back(6);
    print_int_ftvector(v);
    v.push_back(7);
    print_int_ftvector(v);
    v.push_back(8);
    print_int_ftvector(v);
    v.push_back(9);
    print_int_ftvector(v);
    std::cout << CYAN "Back : " END << v.back() << std::endl;
    std::cout << BOLDCYAN "Pop back" END << std::endl;
    v.pop_back();
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
    /* Reverse iterator : not working */
    // std::cout << BOLDCYAN "Rbegin : " END << *v.rbegin() << std::endl;
    // std::cout << BOLDCYAN "Rend : " END << *v.rend() << std::endl;

    std::cout << BOLDCYAN "Resize 15 with 1: " END << std::endl;
    v.resize(15, 1);
    print_int_ftvector(v);

    std::cout << BOLDCYAN "Resize 20 with nothing: " END << std::endl;
    v.resize(20);
    print_int_ftvector(v);

    std::cout << BOLDCYAN "reserve 30 : " END << std::endl;
    v.reserve(30);
    print_int_ftvector(v);
    std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

    std::cout << BOLDCYAN "Resize to smaller : " END << std::endl;
    v.resize(8);
    print_int_ftvector(v);

    std::cout << BOLDCYAN "Insert :" END << std::endl;

    std::cout << "Insert one value 42 at begin: " << std::endl;
    v.insert(v.begin(), 42);
    print_int_ftvector(v);

    std::cout << "Insert one value 42 at position 2: " << std::endl;
    v.insert(v.begin() + 2, 42);
    print_int_ftvector(v);

    std::cout << "Insert multiple value 42 42 42 42: " << std::endl;
    v.insert(v.begin() + 7, 4, 42);
    print_int_ftvector(v);

    ft::vector<int> to_insert(3, 42);
    to_insert[1] = 43;
    to_insert[2] = 44;
    std::cout << "Insert vector 42 43 44: " << std::endl;
    v.insert(v.begin() + 4, to_insert.begin(), to_insert.end());
    print_int_ftvector(v);

    std::cout << BOLDCYAN "Erase" END << std::endl;
    std::cout << CYAN "Erase position 2 : " END << std::endl;
    v.erase(&v[2]);
    print_int_ftvector(v);

    std::cout << CYAN "Erase begin : " END << std::endl;
    v.erase(v.begin());
    print_int_ftvector(v);

    std::cout << CYAN "Erase from 2 to 5 (excluding 5): " END << std::endl;
    v.erase(v.begin() + 2, v.begin() + 5);
    print_int_ftvector(v);

    std::cout << CYAN "Erase from 5 to 9 (excluding 9): " END << std::endl;
    v.erase(v.begin() + 5, v.begin() + 9);
    print_int_ftvector(v);

    std::cout << "Adress of v : " << &v << std::endl;
    std::cout << "Adress of other : " << &to_insert << std::endl;
    std::cout << BOLDCYAN "Swap with 42 43 44" END << std::endl;
    v.swap(to_insert);
    std::cout << "Adress of v : " << &v << std::endl;
    std::cout << "New vector : ";
    print_int_ftvector(v);
    std::cout << "Other vector : " << std::endl;
    std::cout << "Adress of other : " << &to_insert << std::endl;
    print_int_ftvector(to_insert);

    std::cout << BOLDCYAN "Clear" END << std::endl;
    v.clear();
    print_int_ftvector(v);
    std::cout << "Empty ? " << (v.empty() ? "True" : "False") << std::endl;

    // /* Operateur d'affectation */
    // ft::vector<int> cpy;
    // cpy = v;
    // std::cout << BOLDCYAN "Affectation operator : " END << std::endl;
    // print_int_ftvector(cpy);
    // cpy[0] = 100;
    // print_int_ftvector(cpy);
    // std::cout << "Verifying original : "<< std::endl;
    // print_int_ftvector(v);

    // /* Constructeur de recopie */
    // std::cout << BOLDCYAN "Copy constructor : " END << std::endl;
    // ft::vector<int> cpy2 (v);
    // print_int_ftvector(cpy2);
    // cpy2[0] = 200;
    // print_int_ftvector(cpy2);
    // std::cout << "Verifying original : "<< std::endl;
    // /* verifying original */
    // print_int_ftvector(v);
  }  // OK

  {
    // ft::vector<int> v = ft::vector<int>(4);
    // std::cout << v[0] << std::endl;
    // std::cout << v[3] << std::endl;
    // std::cout << v[4] << std::endl;
    // v[0] = 1;
    // std::cout << v[0] << std::endl;
    // std::cout << v.size() << std::endl;
    // std::cout << v.max_size() << std::endl;
    // std::cout << v.capacity() << std::endl;

    //} /* Constructor vector(nb elem, value) */
    // {
    //   unsigned int i = 42;
    //   ft::vector<unsigned int> v = ft::vector<unsigned int>(10, i);
    //   std::cout << v.size() << std::endl;
    //   std::cout << v.max_size() << std::endl;
    //   std::cout << v.capacity() << std::endl;
    //   print_unsignedint_ftvector(v);
    // }  // works
    // {  // TO DO :check
    //   int i = 42;
    //   ft::vector<int> v = ft::vector<int>(10, i);
    //   std::cout << v.size() << std::endl;
    //   std::cout << v.max_size() << std::endl;
    //   std::cout << v.capacity() << std::endl;
    //   print_int_ftvector(v);
    // }
    // {  // TO DO :check
    //   long int i = 42;
    //   ft::vector<long int> v = ft::vector<long int>(10, i);
    //   std::cout << v.size() << std::endl;
    //   std::cout << v.max_size() << std::endl;
    //   std::cout << v.capacity() << std::endl;
    //   print_longint_ftvector(v);
    // }
    // {
    //   ft::vector<std::string> v = ft::vector<std::string>(10, "bla");
    //   std::cout << v.size() << std::endl;
    //   std::cout << v.max_size() << std::endl;
    //   std::cout << v.capacity() << std::endl;
    //   print_str_ftvector(v);
  }  // works
  // /*Iterator constructor */
  // {
  //   ft::vector<int> v = ft::vector<int>(3, 1);
  //   ft::vector<int> my_v(v.begin(), v.end());
  // }
}

#endif

// std::uninitialized fill pour reallocation