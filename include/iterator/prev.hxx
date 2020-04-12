// prev.hxx

#ifndef PREV_HXX
#define PREV_HXX

#include <iterator>
#include "advance.hxx"


namespace cmb {


  template <class I> // I models BidirectionalIterator
  constexpr inline I
  prev(I it, typename std::iterator_traits<I>::difference_type n = 1 )
  {
    cmb::advance(it, -n);
    return it;
  }


} // namespace cmb


#endif