#include <iostream>
#include <fstream>

#include "DoublyLinkedList.h"
#include "ItemType.h"

using namespace std;

/*
  Author: Austin Schultz

  Handles file reading and the command-line user interface.
 */
int main(int argc, char* argv[]) {
    // //TESTING CODE BELOW
    // DoublyLinkedList list;
    
    // ItemType item2(10);
    // ItemType item3(15);
    // ItemType item4(20);
    // ItemType item5(25);
    // ItemType item6(17);
    // ItemType item7(12);
    // ItemType item8(30);
    
    // list.insertItem(item2);
    // list.insertItem(item3);
    // list.insertItem(item4);
    // list.insertItem(item5);
    // list.insertItem(item6);
    // list.insertItem(item7);
    // list.insertItem(item8);
    
    // // list.insertItem(2); // 0
    // // list.insertItem(4); // 1
    // // list.insertItem(6); // 2
    // // list.insertItem(8); // 3
    // // list.insertItem(10); // 4
    // // list.insertItem(12); // 5
    
    // list.print();
    // list.printReverse();

    // cout << "length: " << list.lengthIs() << endl;
    
    // // list.deleteItem(4);

    // // list.print();
    // // list.printReverse();

    // // cout << "length: " << list.lengthIs() << endl;

    DoublyLinkedList list;
    ItemType item;
    int valueInput;
    fstream fs;

    // open the file with the given filename
    fs.open(argv[1], fstream::in);

    // read the file, inserting each space seperated value into the list
    string line;
    if(fs.is_open()) {
    	fs >> valueInput;
	
    	while(!fs.eof()) {
    	    item.initialize(valueInput);
    	    list.insertItem(item);

    	    fs >> valueInput;
    	}

    	fs.close();
    }

    else {
    	cout << "Failed to open the input file" << endl;

    	return 1;
    }

    // display the command options
    cout << "insert (i), delete (d), length (l), print (p)," 
    	 << " printReverse(r), quit (q)" << endl;

    cout << endl;

    // the main command input loop
    bool running = true;
    char commandInput = '\0';
    while(running) {
    	cout << "Enter a command: ";
    	cin >> commandInput;

    	cout << endl;

	// process the input and call the appropriate DoublyLinkedList functions
    	switch(commandInput) {
    	case 'i': {
    	    int num;

    	    cout << "Number to insert: ";
    	    cin >> num;

    	    ItemType item(num);
    	    list.insertItem(item);

    	    cout << endl;

    	    list.print();

    	    cout << endl;
	    
    	    break;
    	}
	    
    	case 'd': {
    	    int num;

    	    cout << "Number to delete: ";
    	    cin >> num;

    	    ItemType item(num);
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

	    // wrong command given
	default:
	    cout << "Invalid command, try again!" << endl;
	    
	    cout << endl;
	    
	    break;
    	}
    	}
    }
    
    return 0;
}

