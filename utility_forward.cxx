#include <iostream>
#include <utility.hxx>


// Function with lvalue and rvalue reference overloads
void f(int const& x) { std::cout << " lvalue" << std::endl; }
void f(int&& x)      { std::cout << " rvalue" << std::endl; }


// Function template
template <class T>
void g(T&& x)
{
  f( x );                  // always an lvalue
  f( cmb::forward<T>(x) ); // rvalue if argument is an rvalue
}


int main()
{
  int a{5};

  std::cout << "\nCalling g with lvalue:" << std::endl;
  g(a); // lvalue lvalue

  std::cout << "\nCalling g with rvalue:" << std::endl;
  g(5); // lvalue rvalue
}