#include <iostream>

#include "DoublyLinkedList.h"
#include "ItemType.h"

using namespace std;

int main() {
    DoublyLinkedList list;

    ItemType item1(5);
    ItemType item2(10);
    ItemType item3(15);
    ItemType item4(20);
    ItemType item5(25);
    ItemType item6(17);
    ItemType item7(2);
    
    list.insertItem(item1);
    list.insertItem(item2);
    list.insertItem(item3);
    list.insertItem(item4);
    list.insertItem(item5);
    list.insertItem(item6);
    list.insertItem(item7);

    list.print();
    list.printReverse();
}

