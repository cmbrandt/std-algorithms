// next.hxx

#ifndef NEXT_HXX
#define NEXT_HXX

#include <iterator>
#include "advance.hxx"


namespace cmb {


  template <class I> // I models InputIterator
  constexpr I
  next(I x, typename std::iterator_traits<I>::difference_type n = 1)
  {
    cmb::advance(x, n); // this should actually call the STD::ADVANCE_IMPL function
    return x;
  }


} // namespace cmb


#endif