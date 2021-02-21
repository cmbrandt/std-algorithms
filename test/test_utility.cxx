#include <iostream>
#include <utility.hxx>
#include <test_utility.hxx>


void test_utility()
{
  int fail = 0;

  fail = test_swap(fail);
  fail = test_exchange(fail);
  fail = test_forward(fail);
  fail = test_move(fail);
  fail = test_move_if_noexcept(fail);

  if (fail == 0)
    std::cout << "\ntest_utility()    passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_utility()    had " << fail << " errors." << std::endl;
}


//
// ... tests

int test_swap(int fail)
{


  return fail;
}



int test_exchange(int fail)
{


  return fail;
}



int test_forward(int fail)
{


  return fail;
}



int test_move(int fail)
{


  return fail;
}



int test_move_if_noexcept(int fail)
{


  return fail;
}