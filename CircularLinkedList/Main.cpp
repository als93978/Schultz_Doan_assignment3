#include <iostream>
#include <fstream>
#include "CircularLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char * argv[]) {
    CircularLinkedList list;
    ItemType item;
    int input;
    fstream fs;
    fs.open(argv[1], fstream::in); // reads input file

    if (fs.is_open()) {
	fs >> input;

	while (!fs.eof()) {
	    item.initialize(input);
	    list.insertItem(item);
	    fs >> input;
	}

	cout << "insert (i), delete (d), length (l), print (p), quit (q)" << endl;
    }

    else {
	cout << "Failed to open the input file" << endl;
	return 0;
    }

    bool loop = true;
    char character; // character input when entering a command

    while (loop) {
	cout << "\nEnter a command: ";
    	cin >> character;
    	cout << "\n";

	switch (character) {
	    
	case 'i': { // insert command that inserts a node in the circular linked list
	    int number;
	    cout << "Number to insert: ";
	    cin >> number;
	    ItemType item(number);
	    list.insertItem(item);
	    list.print();
	    break;
	}

	case 'd': { // delete command that deletes a node in te circular linked list
	    int value;
	    cout << "Number to delete: ";
	    cin >> value;
	    ItemType item(value);
	    list.deleteItem(item);
	    list.print();
	    break;
	}

	case 'l': { // length commands that returns the length of the circular linked list
	    cout << "The length is: " << list.lengthIs() << endl;
	    break;
	}
		
	case 'p': { // print command that prints the circular linked list
	    list.print();
	    break;
	}
	    
	case 'q': { // quit command that stops the hile loop and exits the program
	    cout << "Quitting program..." << endl;
	    loop = false;
	    return 0;
	    break;
	}
	    
	default: { // this will print when the command is invalid
	    cout << "Invalid command, try again!" << endl;
    	    break;
	}
	}
    }
}
    
