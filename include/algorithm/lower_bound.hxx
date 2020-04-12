// lower_bound.hxx

#ifndef LOWER_BOUND_HXX
#define LOWER_BOUND_HXX

#include "functional.hxx"
#include "iterator.hxx"


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
    return cmb::lower_bound(first, last, value, cmb::less<>{ });
  }


} // namespace cmb

/*

g++ -Wall -std=c++17 algorithm_lower_bound.cxx   -I /Users/cmbrandt/projects/stl-algorithm/include -o lb
g++ -Wall -std=c++17 algorithm_upper_bound.cxx   -I /Users/cmbrandt/projects/stl-algorithm/include -o ub
g++ -Wall -std=c++17 algorithm_binary_search.cxx -I /Users/cmbrandt/projects/stl-algorithm/include -o bs
g++ -Wall -std=c++17 algorithm_equal_range.cxx   -I /Users/cmbrandt/projects/stl-algorithm/include -o er

g++ -Wall -std=c++17 functional_less.cxx -I /Users/cmbrandt/projects/stl-algorithm/include -o less

g++ -Wall -std=c++17 iterator_advance.cxx  -I /Users/cmbrandt/projects/stl-algorithm/include -o ad
g++ -Wall -std=c++17 iterator_distance.cxx -I /Users/cmbrandt/projects/stl-algorithm/include -o di
g++ -Wall -std=c++17 iterator_next.cxx     -I /Users/cmbrandt/projects/stl-algorithm/include -o nx
g++ -Wall -std=c++17 iterator_prev.cxx     -I /Users/cmbrandt/projects/stl-algorithm/include -o pr

*/


#endif