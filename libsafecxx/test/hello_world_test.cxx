#feature on safety

#include <safe-cxx/string_view.hxx>
#include <safe-cxx/string_constant.hxx>

template<class T, class U>
void assert_eq(T const^ t, U const^ u) safe
{
  if (*t != *u) throw;
}

void string_view_constructor() safe
{
  std2::string_constant<char> sc("rawr");

  const [char; dyn]^ str = "hello, world!";

  safecxx::string_view sv = str;

  assert_eq(sv.size(), 0u);
}

int main() {
  string_view_constructor();
}
