// accumulate.hxx

#ifndef ACCUMULATE_HXX
#define ACCUMULATE_HXX


namespace cmb {


  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T models ...
  inline T accumulate(I first, I last, T init)
  {
    for (; first != last; ++first)
      init += *first;

    return init;
  }


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T models ...
            class B> // B models BinaryOperation
  inline T accumulate(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op(init, *first);

    return init;
  }


} // namespace cmb


#endif