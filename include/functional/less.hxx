// less.hxx

#ifndef LESS_HXX
#define LESS_HXX


// std::less has a very detailed and nuanced implementation.. something to
// spend some time with later on.


namespace cmb {

/*
  template <class T = void>
  struct less {
    constexpr bool
    operator()(T const& lhs, T const& rhs) const { return lhs < rhs; }
  };


  template <>
  struct less<void> {
    template<class T, class U>
    constexpr auto operator()(T&& t, U&& u) const
    -> decltype(std::forward<T>(t) < std::forward<U>(u));
 
    using is_transparent = void;
  };
// */







template <>
struct less<>
{
    inline bool
    template <typename T1, typename T2
    operator()(const T1& lhs, const T2& rhs) const {return lhs < rhs;}
};



template <class T1, class T2 = T1>
struct less
{
    inline bool
    operator()(const T1& lhs, const T1& rhs) const {return lhs < rhs;}

    inline bool
    operator()(const T1& lhs, const T2& rhs) const {return lhs < rhs;}

    inline bool
    operator()(const T2& lhs, const T1& rhs) const {return lhs < rhs;}

    inline bool
    operator()(const T2& lhs, const T2& rhs) const {return lhs < rhs;}
};


template <class T1>
struct less<T1, T1>
{
    inline bool
    operator()(const T1& lhs, const T1& rhs) const {return lhs < rhs;}
};


template <class T1>
struct less<const T1, T1>
{
    inline bool
    operator()(const T1& lhs, const T1& rhs) const {return lhs < rhs;}
};


template <class T1>
struct less<T1, const T1>
{
    inline bool
    operator()(const T1& lhs, const T1& rhs) const {return lhs < rhs;}
};






} // namespace cmb




#endif





/*

template <class _Arg1, class _Arg2, class _Result>
struct _LIBCPP_TEMPLATE_VIS binary_function
{
    typedef _Arg1   first_argument_type;
    typedef _Arg2   second_argument_type;
    typedef _Result result_type;
}






#if _LIBCPP_STD_VER > 11
template <class _Tp = void>
#else
template <class _Tp>
#endif
struct _LIBCPP_TEMPLATE_VIS less : binary_function<_Tp, _Tp, bool>
{
    _LIBCPP_CONSTEXPR_AFTER_CXX11 _LIBCPP_INLINE_VISIBILITY
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x < __y;}
};

#if _LIBCPP_STD_VER > 11
template <>
struct _LIBCPP_TEMPLATE_VIS less<void>
{
    template <class _T1, class _T2>
    _LIBCPP_CONSTEXPR_AFTER_CXX11 _LIBCPP_INLINE_VISIBILITY
    auto operator()(_T1&& __t, _T2&& __u) const
    _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) < _VSTD::forward<_T2>(__u)))
    -> decltype        (_VSTD::forward<_T1>(__t) < _VSTD::forward<_T2>(__u))
        { return        _VSTD::forward<_T1>(__t) < _VSTD::forward<_T2>(__u); }
    typedef void is_transparent;
};
#endif


*/