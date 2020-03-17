#include <iostream>
#include <fstream>
#include <string>

#include "DoublyLinkedList.h"

using namespace std;

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
    
    DoublyLinkedList list;
    ItemType item;
    int valueInput;
    fstream fs;

    fs.open(argv[1], fstream::in);

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
    	}
    }
    
    return 0;
}

