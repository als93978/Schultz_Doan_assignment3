#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

DoublyLinkedList::~DoublyLinkedList() {

}

int DoublyLinkedList::lengthIs() const {
    return length;
}

void DoublyLinkedList::insertItem(ItemType& item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;

    NodeType* current = head;
    
    bool isDuplicate = false;
    while(current != nullptr) {
	if(item.compareTo(current->data) == GREATER) // keep going
	    current = current->next;

	else if(item.compareTo(current->data) == EQUAL) { // duplicate item
	    cout << "Item already exists" << endl;
	    isDuplicate = true;
	    delete newNode; // delete the unused new node to avoid a memory leak
	    break;
	}
	
	else // found the location to insert item
	    break;
    }

    // newNode is being inserted into empty list or as last element
    if(current == nullptr && !isDuplicate) {
	if(tail != nullptr) { // newNode is being inserted as last element
	    tail->next = newNode;
	    newNode->back = tail;
	    
	    tail = newNode;

	    length++;
	}

	else { // newNode is being inserted into empty list
	    head = newNode;
	    tail = newNode;

	    length++;
	}
    }

    // newNode is being inserted into very beginning
    else if(current->back == nullptr && !isDuplicate) {
	newNode->next = current;
	current->back = newNode;

	head = newNode;

	length++;
    }
    
    else if(!isDuplicate) { // general case insert
	newNode->back = current->back;
	current->back->next = newNode;
	newNode->next = current;
	current->back = newNode;

	length++;
    }
}

void DoublyLinkedList::deleteItem(ItemType& item) {

}

void DoublyLinkedList::print() {
    NodeType* current = head;

    while(current != nullptr) {
	cout << current->data.getValue() << " ";

	current = current->next;
    }

    cout << endl;
}

void DoublyLinkedList::printReverse() {
    NodeType* current = tail;

    while(current != nullptr) {
	cout << current->data.getValue() << " ";

	current = current->back;
    }

    cout << endl;
}

