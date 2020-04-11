// less.hxx

#ifndef LESS_HXX
#define LESS_HXX


namespace cmb {


  template <class T = void>
  struct less
  {
    bool operator()(T const& lhs, T const& rhs) { return lhs < rhs; }
  };


} // namespace cmb


#endif