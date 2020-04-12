// less.hxx

#ifndef LESS_HXX
#define LESS_HXX


namespace cmb {


  template <class T = void> // 
  struct less {

    constexpr bool
    operator()(T const& lhs, T const& rhs) const
    {
      return lhs < rhs;
    }

  };


  template <>
  struct less<void> {

    template<class T, // 
             class U> // 
    constexpr auto operator()(T&& t, U&& u) const
    {
      return std::forward<T>(t) < std::forward<U>(u);
    }
 
    //using is_transparent = void;
  };


} // namespace cmb


#endif