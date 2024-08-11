#feature on safety
#include "std2.h"

using namespace std2;

int main() safe {

  // Populate the vector with views with a nice mixture of lifetimes.
  vector<string_view> views { };

  // string_view with /static lifetime.
  views^.push_back("From a string literal");

  // string_view with outer scope lifetime.
  string s1 = "From string object 1";
  views^.push_back(s1);

  {
    // string_view with inner scope lifetime.
    string s2 = "From string object 2";
    views^.push_back(s2);

    // Print the strings. All strings are in scope, so this should build.
    println("Printing from the inner scope:");
    for(string_view sv : views)
      println(sv);
  }

  // Mutation XOR Aliasing violation.
  // A shared borrow on s1 from line 16 is in scope.
  // s1^.append(" more text");

  // Print the strings. s2 already fell out of scope, so this should
  // be a borrowck violation. `views` now contains objects that hold
  // dangling pointers.
  println("Printing from the outer scope:");
  for(string_view sv : views) {
    println(sv);
  } 
}
