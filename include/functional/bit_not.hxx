// bit_not.hxx

#ifndef BIT_NOT_HXX
#define BIT_NOT_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T = void>
  struct bit_not {

    constexpr inline
    T operator()(T const& x) const
    {
      return ~x;
    }

  };


  // Total specialization
  template <>
  struct bit_not<void> {

    template<class T>
    constexpr inline
    auto operator()(T&& t) const
      -> decltype(  ~std::forward<T>(t) )
    {
      return ~std::forward<T>(t);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif