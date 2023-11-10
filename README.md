James Tulloch - Student No: 21032766

README
Task 1
Implement a class which prints the following output.

Output:

Hello world - String S is constructed and printed. Hello world - New scope, T is asssigned as an object which is a copy of S. Hello world - Prints the content of S again. e - Gets the char at the index of [1] in S, which is 'e'. Hello world - Prints the contents of S again. Hello world - Prints the contents of T again. HEllo world - S is modified so that the char at the index of [1] is now 'E'.

[!To run this file:] clang++ filetest_string.cpp my_string.cpp ./a.out

Description:

The class my_string is correctly implemented and prints the ouput specified. It does so through using constructors, copy constructors and a destructor. It also has the functions get and set char, for the 4th line of output 'e' and the 7th line, where "Hello" is changed to be "HEllo"

Task 2
Extend the programme to support automatic reference counting.

Output:

Hello world [1] - One instance of S exists, reference count is 1. Hello world [2] - Two references of S now exist, with T being a copy of S. The reference count is now 2. Hello world [2] - S is printed, there are still two objects which refer to the contents of S. e - No reference is printed because a specific index of s, [1], is being called instead of the object. Hello world [2] - *S is printed again, the objects refering to its content are still 2. * Hello world [2]- T is printed again, the the objects refering to the content of S are still 2. \ HEllo world [1] - T is now out of scope, and S[1] is modified to be 'E' instead of 'e'. There is now only one reference to the contents of S.

[!To run this file:] clang++ filetest_string.cpp my_string.cpp ./a.out

Description:

The reference counting is implemented in the my_string class, with a pointer called "reference_count". This pointer keeps track of how many instances of the object are in existence, when they are constructed or destroyed.

Task 3
Extend the programme to demonstrate a reference count of 0.

Output:

Hello world [1] Hello world [2] Hello world [2] e \ Hello world [2] \ Hello world [2] HEllo world [1] Reference count is now 0, freeing memory. - Once the final object of S is destroyed, the memory is freed using 'nullptr', setting its value to 0.

[!To run this file:]

clang++ -o task3 filetest_string.cpp my_string.cpp

./task3

Description:

The implementation deletes the pointer to the reference count using "nullptr" when the destructor is called. This returns the memory used to null or 0.

Task 4
Extend the example so reference counting is in a template rather than the "my_string" class.

Output:

Hello world [1] Hello world [2] Hello world [2] e \ Hello world [2] Hello world [2] HEllo world [2] - The output is the same as task 2, despite the template being called and instead of using "ref_count" from within the class.

[!To run this file:] clang++ -o task4 filetest_string.cpp my_string.cpp

./task4

Description:

The class RefCount is implemented in the header file refcount.hpp. This file contains the functionality of task 3's "refcount" implementation inside of the "my_string" class and creates it as a template.
