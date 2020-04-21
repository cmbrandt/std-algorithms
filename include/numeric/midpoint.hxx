// midpoint.hxx

#ifndef MIDPOINT_HXX
#define MIDPOINT_HXX

#include <limits>      // for std::numeric_limits::min, std::numeric_limits::max
#include <type_traits> // for std::is_integral_v, std::make_unsigned_t


namespace cmb {


  // Overload for integer and floating-point types
  template <class T>
  constexpr inline T
  midpoint(T a, T b)
  {
    if constexpr (std::is_integral_v<T>) {

      using U = std::make_unsigned_t<T>;

      int k = 1;
      U m = a;
      U M = b;

      if (a > b) {

        k = -1;
        m =  b;
        M =  a;
      }

      return a + k*T( U(M - m) / 2 );
    }
    else { // std::is_floating

      constexpr T lo = std::numeric_limits<T>::min() * 2;
      constexpr T hi = std::numeric_limits<T>::max() / 2;

      const T abs_a = a < 0 ? -a : a;
      const T abs_b = b < 0 ? -b : b;

      // Most likely
      if (abs_a <= hi && abs_b <= hi)
        return (a + b) / 2;

      // Not safe to halve a
      if (abs_a < lo)
        return a + b/2;

      // Not safe to halve b
      if (abs_b < lo)
        return a/2 + b;

      // Otherwise correctly rounded
      return a/2 + b/2;
    }
  }


  // Overload for pointers
  template <typename T>
  constexpr inline T*
  midpoint(T* a, T* b) noexcept
  {
    // Check that T is a complete type
    static_assert( sizeof(T) != 0 );

    return a + (b - a) / 2;
  }


} // namespace cmb


#endif