// lower_bound.hxx

#ifndef LOWER_BOUND_HXX
#define LOWER_BOUND_HXX

//#include "../functional.hxx"
#include <functional>
#include "../iterator.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline I
  lower_bound(I first, I last, T const& value, C compare)
  {
    while (first != last) {
      auto dist = cmb::distance(first, last);
      I middle  = cmb::next(first, dist / 2);

      if ( compare(*middle, value) )
        first = cmb::next(middle);
      else
        last  = middle;
    }

    return first;
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr inline I
  lower_bound(I first, I last, T const& value)
  {
    return cmb::lower_bound(first, last, value, std::less<>{ });
  }


} // namespace cmb

/*

g++ -Wall -std=c++17 algorithm_lower_bound.cxx -o lb
g++ -Wall -std=c++17 algorithm_upper_bound.cxx -o ub
g++ -Wall -std=c++17 algorithm_binary_search.cxx -o bs
g++ -Wall -std=c++17 algorithm_equal_range.cxx -o er

*/


#endif