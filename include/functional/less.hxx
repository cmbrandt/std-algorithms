// less.hxx

#ifndef LESS_HXX
#define LESS_HXX


// std::less has a very detailed and nuanced implementation.. something to
// spend some time with later on.


namespace cmb {


  template <typename T = void>
  struct less
  {
    constexpr bool
    operator()(T const& lhs, T const& rhs) { return lhs < rhs; }
  };


} // namespace cmb


#endif