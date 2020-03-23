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
    // author: David Doan
    CircularLinkedList(); // default constructor for CircularLinkedList
    // author: David Doan
    ~CircularLinkedList(); // destructor for CircularLinkedList
    // author: David Doan
    void insertItem(ItemType &item); // insert function that inserts the item into the circular linked list in sorted order
    // author: David Doan
    void deleteItem(ItemType &item); // delete function that removes the item from the circular linked list
    // author: David Doan
    int lengthIs() const; // returns the length of the circular linked list
    // author: David Doan
    void print(); // prints the circular linked list
};

#endif
