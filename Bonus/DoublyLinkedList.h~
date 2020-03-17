#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "ItemType.h"

struct NodeType {
    ItemType data;
    NodeType* next;
    NodeType* back;
};

class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int lengthIs() const;
    void insertItem(ItemType& item);
    void insertItem(int itemValue);
    void deleteItem(ItemType& item);
    void deleteItem(int itemIndex);
    ItemType searchItem(int itemIndex);
    void print();
    void printReverse();

 private:
    NodeType* head;
    NodeType* tail;
    int length;
};

#endif

