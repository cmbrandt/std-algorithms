// less.hxx

#ifndef LESS_HXX
#define LESS_HXX

#include <utility>


namespace cmb {


  // Specification and implementation of less (since C++14)
  template <class T = void>
  struct less {

    constexpr bool
    operator()(T const& lhs, T const& rhs) const
    {
      return lhs < rhs;
    }

  };


  // Total specialization of less (since C++14)
  template <>
  struct less<void> {

    template<class T, class U>
    constexpr auto operator()(T&& t, U&& u) const
      -> decltype( std::forward<T>(t) < std::forward<U>(u) )
    {
      return std::forward<T>(t) < std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif