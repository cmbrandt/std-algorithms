// midpoint.hxx

#ifndef MIDPOINT_HXX
#define MIDPOINT_HXX

#include <limits>      // for std::numeric_limits::min, std::numeric_limits::max
#include <type_traits> // for std::is_integral_v, std::make_unsigned_t, ...


namespace cmb {


  // Overload for integer and floating-point types
  template <class T> // T models Arithmetic
  constexpr T
  midpoint(T a, T b) noexcept
  {
    if constexpr (std::is_integral_v<T>) {

      using U = typename std::make_unsigned_t<T>;

      int sign = 1;
      U m = a;
      U M = b;

      if (a > b) {

        sign = -1;
        m = b;
        M = a;
      }

      return a + sign * T( U(M - m) / 2 );
    }
    else { // is_floating
    
      constexpr T lo = std::numeric_limits<T>::min() * 2;
      constexpr T hi = std::numeric_limits<T>::max() / 2;

      const T abs_a = std::abs(a);
      const T abs_b = std::abs(b);

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
  template <typename T> // T models Pointer
  constexpr std::enable_if_t<std::is_object_v<T>, T*>
  midpoint(T* a, T* b)
  {
    // T is a complete type
    static_assert( sizeof(T*) != 0 );

    return a + cmb::midpoint(std::ptrdiff_t{0}, b - a);
  }


} // namespace cmb


#endif