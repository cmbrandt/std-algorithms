// logical_not.hxx

#ifndef LOGICAL_NOT_HXX
#define LOGICAL_NOT_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T = void>
  struct logical_not {

    constexpr inline
    T operator()(T const& x) const
    {
      return !x;
    }

  };


  // Total specialization
  template <>
  struct logical_not<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t, U&& u) const
      -> decltype(  !std::forward<T>(t) )
    {
      return !std::forward<T>(t);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif