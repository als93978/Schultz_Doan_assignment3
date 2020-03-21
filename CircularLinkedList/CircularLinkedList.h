#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "ItemType.h"

struct NodeType {
    ItemType data;
    NodeType *next;
};

class CircularLinkedList {
    // private members
    int length;
    NodeType *head;

 public:
    CircularLinkedList(); // default constructor for CircularLinkedList
    ~CircularLinkedList(); // destructor for CircularLinkedList
    void insertItem(ItemType &item); // insert function that inserts the item into the circular linked list in sorted order
    void deleteItem(ItemType &item); // delete function that removes the item from the circular linked list
    int lengthIs() const; // returns the length of the circular linked list
    void print(); // prints the circular linked list
};

#endif
