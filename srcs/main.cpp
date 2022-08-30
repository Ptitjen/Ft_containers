#include "vector.hpp"
#include <iostream>
#include <vector>

#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define END "\033[0m"

void print_int_ftvector (ft::vector<int> v){
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i ++ )
    std::cout << " | " << v[i] ;
  std::cout << " |" << std::endl;
}
void print_str_ftvector (ft::vector<std::string> v){
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i ++ )
    std::cout << " | " << v[i] ;
  std::cout << " |" << std::endl;
}
void print_int_vector (std::vector<int> v){
  std::cout << "Content : ";
  for (unsigned long int i = 0; i < v.size(); i ++ )
    std::cout << " | " << v[i] ;
  std::cout << " |" << std::endl;
}

int main(void) {
  std::cout << BOLDMAGENTA "----- Built in vector -----" END << std::endl;
  // {
  //   std::vector<int> v = std::vector<int>();
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   std::cout << "Max size : " << v.max_size() << std::endl;
  //   v.push_back(1);
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   std::cout << v[0] << std::endl;
  //   v.push_back(2);
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   std::cout << v[1] << std::endl;  
  //   v.push_back(3);
  //   v.push_back(4);
  //   v.push_back(5);
  //   v.push_back(6);
  //   v.push_back(7);
  //   v.push_back(8);
  //   v.push_back(9);
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   print_int_vector(v);

  //   /* Operateur d'affectation */
  //   std::vector<int> cpy;
  //   cpy = v;
  //   std::cout << "Affectation operator : " << std::endl;
  //   print_int_vector(cpy);
  //   cpy[0] = 100;
  //   print_int_vector(cpy);
  //   std::cout << "Verifying original : "<< std::endl;
  //   print_int_vector(v);

  //   /* Constructeur de recopie */
  //   std::cout << "Copy constructor : "<< std::endl;
  //   std::vector<int> cpy2 (v);
  //   print_int_vector(cpy2);
  //   cpy2[0] = 200;
  //   print_int_vector(cpy2);
  //   std::cout << "Verifying original : "<< std::endl;
  //   /* verifying original */
  //   print_int_vector(v);
  // }
  {
    // std::vector<int> v(4);
    // std::cout << v[0] << std::endl;
    // std::cout << v[3] << std::endl;
    // std::cout << v[4] << std::endl;
    // v[0] = 1;
    // std::cout << v[0] << std::endl;
    // std::cout << v.size() << std::endl;
    // std::cout << v.max_size() << std::endl;
    // std::cout << v.capacity() << std::endl;
  }
  {
    int i = 42;
    std::vector<int> v = std::vector<int>(10, i);
    std::cout << v.size() << std::endl;
    std::cout << v.max_size() << std::endl;
    std::cout << v.capacity() << std::endl;
    print_int_vector(v);
  }

  std::cout<<std::endl<< BOLDMAGENTA "----- My vector -----" END << std::endl;
  // { /* Constructor empty vector => ok */
  //   std::cout << BOLDCYAN "Default constructor - empty vector" END << std::endl;
  //   ft::vector<int> v = ft::vector<int>();
  //   std::cout << CYAN "Size : " END << v.size() << std::endl;
  //   std::cout << CYAN "Capacity : " END << v.capacity() << std::endl;
  //   std::cout << CYAN "Max size : " END<< v.max_size() << std::endl;
  //   std::cout << BOLDCYAN "Push back : " END << std::endl;
  //   v.push_back(1);
  //   std::cout << "Size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   std::cout << v[0] << std::endl;
  //   v.push_back(2);
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   std::cout << v[1] << std::endl;  
  //   v.push_back(3);
  //   v.push_back(4);
  //   v.push_back(5);
  //   v.push_back(6);
  //   v.push_back(7);
  //   v.push_back(8);
  //   v.push_back(9);
  //   std::cout << "size : " << v.size() << std::endl;
  //   std::cout << "Capacity : " << v.capacity() << std::endl;
  //   print_int_ftvector(v);

  //   /* Operateur d'affectation */
  //   ft::vector<int> cpy;
  //   cpy = v;
  //   std::cout << BOLDCYAN "Affectation operator : " END << std::endl;
  //   print_int_ftvector(cpy);
  //   cpy[0] = 100;
  //   print_int_ftvector(cpy);
  //   std::cout << "Verifying original : "<< std::endl;
  //   print_int_ftvector(v);

  //   /* Constructeur de recopie */
  //   std::cout << BOLDCYAN "Copy constructor : " END << std::endl;
  //   ft::vector<int> cpy2 (v);
  //   print_int_ftvector(cpy2);
  //   cpy2[0] = 200;
  //   print_int_ftvector(cpy2);
  //   std::cout << "Verifying original : "<< std::endl;
  //   /* verifying original */
  //   print_int_ftvector(v);   
  // } //OK

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

  }
  /* Constructor vector(nb elem, value) */
  // {
  //   unsigned int i = 42;
  //   ft::vector<int> v = ft::vector<int>(10,i);
  //   std::cout << v.size() << std::endl;
  //   std::cout << v.max_size() << std::endl;
  //   std::cout << v.capacity() << std::endl;
  //   //print_int_ftvector(v);
  // } //works
  { //TO DO :check 
    int i = 42;
    ft::vector<int> v = ft::vector<int>(10,i);
    std::cout << v.size() << std::endl;
    std::cout << v.max_size() << std::endl;
    std::cout << v.capacity() << std::endl;
    print_int_ftvector(v);
  }
  // {
  //   ft::vector<std::string> v = ft::vector<std::string>(10, "bla");
  //   std::cout << v.size() << std::endl;
  //   std::cout << v.max_size() << std::endl;
  //   std::cout << v.capacity() << std::endl;
  //   print_str_ftvector(v);
  // } // works
  /*Iterator constructor */
  {
    ft::vector<std::string> v = ft::vector<std::string>(3, "bla");
  }
}