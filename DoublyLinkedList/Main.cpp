#include <iostream>
#include <fstream>

#include "DoublyLinkedList.h"
#include "ItemType.h"

using namespace std;

int main(int argc, char* argv[]) {
    // TESTING CODE BELOW
    // DoublyLinkedList list;
    
    // // ItemType item2(10);
    // // ItemType item3(15);
    // // ItemType item4(20);
    // // ItemType item5(25);
    // // ItemType item6(17);
    // // ItemType item7(2);
    
    // // list.insertItem(item2);
    // // list.insertItem(item3);
    // // list.insertItem(item4);
    // // list.insertItem(item5);
    // // list.insertItem(item6);
    // // list.insertItem(item7);
    
    // list.insertItem(2); // 0
    // list.insertItem(4); // 1
    // list.insertItem(6); // 2
    // list.insertItem(8); // 3
    // list.insertItem(10); // 4
    // list.insertItem(12); // 5
    
    // list.print();
    // list.printReverse();

    // cout << "length: " << list.lengthIs() << endl;
    
    // list.deleteItem(4);

    // list.print();
    // list.printReverse();

    // cout << "length: " << list.lengthIs() << endl;

    DoublyLinkedList list;
    ItemType item;
    int input;
    fstream fs;

    fs.open(argv[1], fstream::in);

    string line;
    if(fs.is_open()) {
	fs >> input;
	
	while(!fs.eof()) {
	    item.initialize(input);
	    list.insertItem(item);

	    fs >> input;
	}

	fs.close();
    }

    else {
	cout << "Failed to open the input file" << endl;

	return 1;
    }

    
    
    return 0;
}

