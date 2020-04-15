// logical_or.hxx

#ifndef LOGICAL_OR_HXX
#define LOGICAL_OR_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T = void>
  struct logical_or {

    constexpr inline
    T operator()(T const& x, T const& y) const
    {
      return x || y;
    }

  };


  // Total specialization
  template <>
  struct logical_or<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t, U&& u) const
      -> decltype(  std::forward<T>(t) || std::forward<U>(u) )
    {
      return std::forward<T>(t) || std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif