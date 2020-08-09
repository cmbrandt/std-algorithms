// greater_equal.hxx

#ifndef GREATER_EQUAL_HXX
#define GREATER_EQUAL_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T>
  struct greater_equal {

    constexpr inline
    bool operator()(T const& x, T const& y) const
    {
      return x >= y;
    }

  };


  // Total specialization
  template <>
  struct greater_equal<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t, U&& u) const
      -> decltype(  std::forward<T>(t) >= std::forward<U>(u) )
    {
      return std::forward<T>(t) >= std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif