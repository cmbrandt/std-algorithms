// lcm.hxx

#ifndef LCM_HXX
#define LCM_HXX

#include <type_traits>


namespace cmb {


  // Implementation function
  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  lcm_impl(M m, N n)
  {
    return (m != 0 && n != 0)
         ? ( std::abs(m) / cmb::gcd(m, n) ) * std::abs(n)
         : 0;
  }


  // asdf
  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  lcm(M m, N n)
  {
    static_assert(std::is_integral_v<M>,
                  "lcm arguments are integers");
    static_assert(std::is_integral_v<N>,
                  "lcm arguments are integers");
    static_assert(!std::is_same_v<std::remove_cv_t<M>, bool>,
                  "lcm arguments are not bools");
    static_assert(!std::is_same_v<std::remove_cv_t<N>, bool>,
                  "lcm arguments are not bools");

    return lcm_impl(n, m % n);
  }


} // namespace cmb


#endif