// test_functional.cxx

#include <iostream>
#include "functional.hxx"


// Function object used within test_functional()
template <typename T, typename C = cmb::less<>>
bool compare_test(T a, T b, C compare = C())
{
  return compare(a, b);
}


void test_functional()
{
    std::cout << "\n\n\n  ***** test_functional() *****" << std::endl;

    int fail = 0;


    //
    // Test for cmb::less

    bool b1 = compare_test(0,   5  );
    bool b2 = compare_test(5.0, 0.0);

    if (b1 !=true or b2 != false) {
      ++fail;
      std::cout << "\nERROR! cmb::less()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << true
                << "\nb2    = " << b2
                << "\nsoln1 = " << false
                 << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_iterator() passed with zero errors." << std::endl;
    else
      std::cout <<"\ntest_iterator() had " << fail << " errors." << std::endl;

}