#ifndef UTILITY_HXX
#define UTILITY_HXX

#include <type_traits>


namespace cmb {

//
// Declarations

template <class T>
constexpr void
swap(T& a, T& b) noexcept( std::is_nothrow_move_constructible_v<T> &&
                           std::is_nothrow_move_assignable_v<T> );
template <class T, size_t N>
constexpr void
swap(T (&a)[N], T (&b)[N]) noexcept(std::is_nothrow_swappable_v<T>);

template <class T, class U = T>
constexpr T
exchange(T& obj, U&& new_val);

template <class T>
constexpr T&&
forward(std::remove_reference_t<T>& t) noexcept;
template <class T>
constexpr T&&
forward(std::remove_reference_t<T>&& t) noexcept;

template <class T>
constexpr std::remove_reference_t<T>&&
move(T&& t) noexcept;

template <class T>
constexpr std::conditional_t<
  !std::is_nothrow_move_constructible_v<T> && std::is_copy_constructible_v<T>, T const&, T&&>
move_if_noexcept(T& x) noexcept;



//
// Swap

template <class T> // T satisfies MoveConstructible and MoveAssignable
constexpr void
swap(T& a, T& b) noexcept( std::is_nothrow_move_constructible_v<T> &&
                           std::is_nothrow_move_assignable_v<T> )
{
  T c( cmb::move(a) );
  a  = cmb::move(b);
  b  = cmb::move(c);
}

template <class T,  // T satisfies Swappable
          size_t N>
constexpr void
swap(T (&a)[N], T (&b)[N]) noexcept(std::is_nothrow_swappable_v<T>)
{
  for (std::size_t n = 0; n < N; ++n)
    cmb::swap(a[n], b[n]);
}



//
// Exchange

template <class T,     // T satisfies MoveConstructible
          class U = T> // U satisfies MoveConstructible
constexpr T
exchange(T& obj, U&& new_val)
{
  T old_val = cmb::move(obj);
  obj       = cmb::forward<U>(new_val);
  return old_val;
}



//
// Forward

template <typename T> // T is an arbitrary type
constexpr T&&
forward(std::remove_reference_t<T>& t) noexcept
{
  return static_cast<T&&>(t);
}

template <typename T> // T is an arbitrary type
constexpr T&&
forward(std::remove_reference_t<T>&& t) noexcept
{
  static_assert(!std::is_lvalue_reference_v<T>,
                "template argument substituting T is an lvalue reference type");
  return static_cast<T&&>(t);
}



//
// Move

template<typename T> // T is an abritrary type
constexpr std::remove_reference_t<T>&&
move(T&& t) noexcept
{
  return static_cast<std::remove_reference_t<T>&&>(t);
}



//
// Move If Noexcept

template <class T> // T is an arbitrary type
constexpr std::conditional_t<
  !std::is_nothrow_move_constructible_v<T> && std::is_copy_constructible_v<T>, T const&, T&&>
move_if_noexcept(T& x) noexcept
{
  return cmb::move(x);
}

} // namespace cmb


#endif