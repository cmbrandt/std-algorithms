// logical_not.hxx

#ifndef LOGICAL_NOT_HXX
#define LOGICAL_NOT_HXX

#include <utility>


namespace cmb {


  // Specification and implementation
  template <class T>
  struct logical_not {

    constexpr bool
    operator()(T const& x) const
    {
      return !x;
    }

  };


  // Total specialization
  template <>
  struct logical_not<void> {

    template<class T>
    constexpr auto
    operator()(T&& t) const
      -> decltype(  !std::forward<T>(t) )
    {
      return !std::forward<T>(t);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif