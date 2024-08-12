#pragma once

#feature on safety

#include <string>
#include <cstddef>

namespace safecxx
{

template<class CharT, class Traits = std::char_traits<CharT>>
class basic_string_view/(a);

// C++-style typedefs.
using string_view    = basic_string_view<char>;
using wstring_view   = basic_string_view<wchar_t>;
using u8string_view  = basic_string_view<char8_t>;
using u16string_view = basic_string_view<char16_t>;
using u32string_view = basic_string_view<char32_t>;

// Rust-style typedefs.
using str    = basic_string_view<char>;
using wstr   = basic_string_view<wchar_t>;
using u8str  = basic_string_view<char8_t>;
using u16str = basic_string_view<char16_t>;
using u32str = basic_string_view<char32_t>;

template<class CharT, class Traits>
class basic_string_view/(a)
{
public:
  using traits_type            = Traits;
  using value_type             = CharT;
  using pointer                = value_type*;
  using const_pointer          = value_type const*;
  using reference              = value_type&;
  using const_reference        = value_type const&;
  // using const_iterator         = implementation-defined; // see [string.view.iterators]
  // using iterator               = const_iterator;201
  // using const_reverse_iterator = reverse_iterator<const_iterator>;
  // using reverse_iterator       = const_reverse_iterator;
  using size_type              = std::size_t;
  using difference_type        = std::ptrdiff_t;
  static constexpr size_type npos = size_type(-1);

  basic_string_view() = delete;

  basic_string_view(const [value_type; dyn]^ str) noexcept safe
  : p_(str)
  {
  }

  size_type size(self) noexcept safe {
      return (*self.p_)~length;
  }

private:
  const [value_type; dyn]^/a p_;
};

}
