CSCI 2720

Assignnment 3: Circular and Doubly Linked Lists

README
==============================================

Group members
-------------
Austin Schultz - als93978@uga.edu
       * Contributions: All of DoublyLinkedList (ItemType.h, ItemType.cpp,
       DoublyLinkedList.h, DoublyLinkedList.cpp, Main.cpp, input1.txt, Makefile),
       Bonus, and Readme.txt.
       
David Doan - dd67391@uga.edu
       * Contributions: All of CircularLinkedList (ItemType.h, ItemType.cpp,
       CircularLinkedList.h, CircularLinkedList.cpp, input1.txt, Main.cpp, Makefile)

For DoublyLinkedList (Not the Bonus)
====================================

Compiling
---------
Ensure you are in the correct assignment directory (Schultz-Doan-assignment3).

Then simply run:
make compile

gcc version 6.2.0 was used to compile for testing.

To compile manually, run the following:
g++ -g -Wall -O0 -pedantic-errors -o main ItemType.cpp DoublyLinkedList.cpp Main.cpp

To run
------
Simply run:
make run    **(note this only runs ./main input1.txt)

To run manually, run the following:
./main input1.txt
or ./main input.txt (if using input.txt, but eLC download came with input1.txt)
or ./main [other input file]

After running
-------------
If you want, you can run the following:
make clean

Or, run: rm main.

This deletes the 'main' executable file.

For Bonus
===========================

Compiling
---------
Ensure you are in the correct assignment directory (Schultz-Doan-assignment3).

Then simply run:
make compile

gcc version 6.2.0 was used to compile for testing.

To compile manually, run the following:
g++ -g -Wall -O0 -pedantic-errors -o main Main.cpp

To run
------
Simply run:
make run    **(note this only runs ./main string-input.txt)

To run manually, run the following:
./main string-input.txt
./main int-input.txt
./main float-input.txt
or ./main [other input file]

After running
-------------
If you want, you can run the following:
make clean

Or, run: rm main.

This deletes the 'main' executable file.
