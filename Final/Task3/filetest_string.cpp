#include "my_string.hpp"

int main() {
  my_string s("Hello World");
  s.print();
  {
    my_string t = s;
    s.print();
    t.print();
    std::cout <<s.getChar(1) << std::endl;
    s.print();
    t.print();
  }
  s.setChar(1,'E');
  s.print();

  // Demonstrate reference count of 0
  {
      my_string u("Temporary String");
      u.print();
      u.decreaseRefCount();
  } // u goes out of scope here, should print "Reference count is now 0, freeing memory."
}
