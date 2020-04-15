// plus.hxx

#ifndef PLUS_HXX
#define PLUS_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T = void>
  struct plus {

    constexpr inline
    bool operator()(T const& lhs, T const& rhs) const
    {
      return lhs + rhs;
    }

  };


  // Total specialization
  template <>
  struct plus<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t, U&& u) const
      -> decltype(  std::forward<T>(t) + std::forward<U>(u) )
    {
      return std::forward<T>(t) + std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif