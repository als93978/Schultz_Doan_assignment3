#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "DoublyLinkedList.h"

using namespace std;

template <typename T>
void readInputFile(DoublyLinkedList<T>& list, char* filename);

template <typename T>
void runUserInterface(DoublyLinkedList<T>& list, string type);

int main(int argc, char* argv[]) {
    // //TESTING CODE BELOW
    // DoublyLinkedList<string> list;

    // // int item1 = 1;
    // // int item2 = 3;
    // // int item3 = 5;
    // // int item4 = 7;
    // // int item5 = 9;
    // // int item6 = 11;
    // // int item7 = 13;
    // // int item8 = 15;

    // // float item1 = 1.2;
    // // float item2 = 3.5;
    // // float item3 = 5.45;
    // // float item4 = 7.32;
    // // float item5 = 9.67;
    // // float item6 = 11.45;
    // // float item7 = 13.21;
    // // float item8 = 15.22;

    // string item1 = "absent";
    // string item2 = "bought";
    // string item3 = "circular";
    // string item4 = "deductive";
    // string item5 = "electric";
    // string item6 = "faux";
    // string item7 = "george";
    // string item8 = "hyper";
    // string item9 = "aaron";

    // list.insertItem(item1);
    // list.insertItem(item2);
    // list.insertItem(item3);
    // list.insertItem(item4);
    // list.insertItem(item5);
    // list.insertItem(item6);
    // list.insertItem(item7);
    // list.insertItem(item8);
    // list.insertItem(item9);

    // list.print();

    // list.printReverse();

    // cout << "Length: " << list.lengthIs() << endl;

    // list.deleteItem(-1);

    // list.print();

    // list.printReverse();

    // cout << "Length: " << list.lengthIs() << endl;

    bool incorrectInput = true;
    char commandInput = '\0';
    while(incorrectInput) {
	cout << "Enter list type (i - int, f - float, s - std:string): ";
	cin >> commandInput;

	cout << endl;

	switch(commandInput) {
	case 'i': {
	    DoublyLinkedList<int> list;

	    readInputFile(list, argv[1]);

	    runUserInterface(list, "Int");
	    
	    incorrectInput = false;

	    break;
	}

	case 'f': {
	    DoublyLinkedList<float> list;
		    
	    readInputFile(list, argv[1]);

	    runUserInterface(list, "Float");

	    incorrectInput = false;

	    break;
	}

	case 's': {
	    DoublyLinkedList<string> list;

	    readInputFile(list, argv[1]);

	    runUserInterface(list, "String");

	    incorrectInput = false;

	    break;
	}

	default: {
	    cout << "Invalid command, try again!" << endl;
	    
	    cout << endl;

	    break;
	}
	}
    }
    
    return 0;
}

template <typename T>
void readInputFile(DoublyLinkedList<T>& list, char* filename) {
    fstream fs;
    
    fs.open(filename, fstream::in);
	
    T valueInput;
    if(fs.is_open()) {
    	fs >> valueInput;
	
    	while(!fs.eof()) {
    	    list.insertItem(valueInput);

    	    fs >> valueInput;
    	}

    	fs.close();
    }

    else {
    	cout << "Failed to open the input file" << endl;

    	exit(1);
    }
}

template <typename T>
void runUserInterface(DoublyLinkedList<T>& list, string type) {
    cout << "insert (i), delete (d), length (l), print (p)," 
    	 << " printReverse(r), quit (q)" << endl;

    cout << endl;
    
    bool running = true;
    char commandInput = '\0';
    while(running) {
    	cout << "Enter a command: ";
    	cin >> commandInput;

    	cout << endl;
	
    	switch(commandInput) {
    	case 'i': {
    	    T item;

    	    cout << type << " to insert: ";
    	    cin >> item;

    	    list.insertItem(item);

    	    cout << endl;

    	    list.print();

    	    cout << endl;
	    
    	    break;
    	}
	    
    	case 'd': {
    	    T item;

    	    cout << type << " to delete: ";
    	    cin >> item;

    	    list.deleteItem(item);

    	    cout << endl;

    	    list.print();

    	    cout << endl;
	    
    	    break;
    	}

    	case 'l': {
    	    cout << "The length is: " << list.lengthIs() << endl;

    	    cout << endl;
	    
    	    break;
    	}

    	case 'p': {
    	    list.print();

    	    cout << endl;
	    
    	    break;
    	}

    	case 'r': {
    	    list.printReverse();

    	    cout << endl;
	    
    	    break;
    	}

    	case 'q': {
    	    running = false;

    	    cout << "Quitting program..." << endl;

    	    cout << endl;
	    
    	    break;
    	}

	default:
	    cout << "Invalid command, try again!" << endl;

	    cout << endl;

	    break;
    	}
    }

}

