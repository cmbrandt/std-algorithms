// equal_to.hxx

#ifndef EQUAL_TO_HXX
#define EQUAL_TO_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T>
  struct equal_to {

    constexpr inline
    bool operator()(T const& x, T const& y) const
    {
      return x == y;
    }

  };


  // Total specialization
  template <>
  struct equal_to<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t, U&& u) const
      -> decltype(  std::forward<T>(t) == std::forward<U>(u) )
    {
      return std::forward<T>(t) == std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif