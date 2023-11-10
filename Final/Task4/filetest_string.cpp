#include "my_string.hpp"

int main() {
    my_string s("Hello world");
    s.print(); // Should print "Hello world"

    {
        my_string t = s; // Uses copy constructor
        s.print(); // Should print "Hello world"
        t.print(); // Should print "Hello world"
        std::cout << s.getChar(1) << std::endl; // Should print 'e'
        s.print(); // Should still print "Hello world"
        t.print(); // Should still print "Hello world"
    } // 't' goes out of scope here and is destroyed

    s.setChar(1,'E'); // Should change the string to "HEllo world"
    s.print(); // Should print "HEllo world"
    return 0;
}
