#include <iostream>
#include <utility.hxx>


// struct with noexcept move ctor and noexcept copy ctor
struct Good {
  Good() = default;

  Good(Good&&)      noexcept // will not throw
  { std::cout << "Non-throwing move ctor\n"; }

  Good(Good const&) noexcept // will not throw
  { std::cout << "Non-throwing copy ctor" << std::endl; }
};


// struct with move ctor and copy ctor that may throw
struct Bad {
  Bad() = default;
    
  Bad(Bad&&)      // may throw
  { std::cout << "    Throwing move ctor" << std::endl; }
    
  Bad(Bad const&) // may throw
  { std::cout << "    Throwing copy ctor\n"; }
};


int main()
{
    Good g1;
    Bad  b1;

    Good g2( cmb::move_if_noexcept(g1) ); // Non-throwing move ctor
    Bad  b2( cmb::move_if_noexcept(b1) ); //     Throwing copy ctor
}