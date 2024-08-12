#feature on safety

#include <safe-cxx/string_view.hxx>

template<class T, class U>
void assert_eq(T^ t, U^ u) safe
{
  if (*t != *u) throw;
}

void string_view_constructor() safe
{
  const [char; dyn]^/static str = "hello, world!";

  safecxx::string_view sv = str;

  assert_eq(^sv.size(), ^0u);
}

int main() {
  string_view_constructor();
}
