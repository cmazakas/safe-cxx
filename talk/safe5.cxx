#feature on safety

template<typename F, typename... Args>
void spawn(F f, Args... args) safe requires(safe(f(rel args...)));

struct Foo {
  // The int overload is safe.
  void operator()(const self^, int) safe;

  // The double overload is unsafe.
  void operator()(const self^, double);
};

int main() safe {
  Foo obj { };
  spawn(obj, 1);
}