// generic7.cxx

// g++-9 -std=c++17 -Wall generic7.cxx -o g7

//#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "lower_bound.hxx"


// User-defined type
class Employee {
public:
  // Ctors
  Employee() = default;
  Employee(int id, std::string const& f, std::string const& l)
    : id_(id), first_name_(f), last_name_(l) { }
  // ...

  // Accessors
  int         id()         const { return id_; }
  std::string first_name() const { return first_name_; }
  std::string last_name()  const { return last_name_;  }
  // ...

private:
  // Members
  int         id_;
  std::string first_name_;
  std::string last_name_;
  // ...
};


// Heterogeneous comparison function
bool compare_id(Employee const& e, int id) { return e.id() < id; }


int main()
{
  // Define Employee objects
  Employee e1{ 1, "John",  "Doe" };
  Employee e2{ 2, "James", "Doe" };
  Employee e3{ 4, "Jeff",  "Doe"};

  // Initialize vector of employees
  std::vector<Employee> e{ e1, e2, e3 };

  // Search for Employee id #3
  auto r = nag::lower_bound( e.begin(), e.end(), 3, compare_id );

  std::cout << "\n4 parameter overload:" << std::endl;
  std::cout << "r = " << nag::distance( e.begin(), r ) << std::endl;


}