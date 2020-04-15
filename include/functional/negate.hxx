// negate.hxx

#ifndef NEGATE_HXX
#define NEGATE_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T = void>
  struct negate {

    constexpr inline
    bool operator()(T const& arg) const
    {
      return -arg;
    }

  };


  // Total specialization
  template <>
  struct negate<void> {

    template<class T, class U>
    constexpr inline
    auto operator()(T&& t) const
      -> decltype(  -std::forward<T>(t) )
    {
      return -std::forward<T>(t);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif