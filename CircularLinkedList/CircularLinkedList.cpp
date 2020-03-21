#include <iostream>
#include <fstream>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList() {
    head = nullptr;
    length = 0;
}

CircularLinkedList::~CircularLinkedList() {
    NodeType *temp;
    if (length == 0) {
	return;
    }
    
    for (int i = 0; i < length; i++) {
	temp = head;
	if (temp->next == nullptr) {
	    head = nullptr;
	}

	else {
	    head = head->next;
	}
	delete temp;
    }
}

void CircularLinkedList::insertItem(ItemType &item) {
    NodeType *newNode = new NodeType;
    newNode->data = item;
    newNode->next = nullptr;
    NodeType *current;
    NodeType *predLoc = head;
    bool duplicateFound = false;
    bool moreToSearch = true;
    
    if (head == nullptr) { // inserts when circular linked list is empty
    	head = newNode;
    	newNode->next = newNode;
	length++;
    	return;
    }
    
    else {
	current = head->next;
	while (moreToSearch) { // finds the item in list and compares to current->data
	    if (item.compareTo(current->data) == LESS) {
		moreToSearch = false;
	    }

	    else if (item.compareTo(current->data) == EQUAL) { // finds and handles duplicates
		cout << "\nItem already exists" << endl;
		duplicateFound = true;
		delete newNode;
		break;
	    }

	    else { // if greater, updates predLoc, current, and moreToSearch
		predLoc = current;
		current = current->next;
		moreToSearch = (current != head->next);
	    }
	}

	if (!duplicateFound) { // general case for insert
	    newNode->next = predLoc->next;
	    predLoc->next = newNode;

	    // special case: if this is the last node in the circular linked list, head is reassigned to newNode
	    if (head->data.compareTo(item) == LESS) {
		head = newNode;
	    }
	    
	    length++;
	    return;
	}
    }
}

void CircularLinkedList::deleteItem(ItemType &item) {
    NodeType *predLoc = head;
    NodeType *current = head;
    bool moreToSearch = true;

    if (length == 0) { // list is empty
	cout << "\nYou cannot delete from an empty list." << endl;
	return;
    }

    bool isFound = false;

    current = head->next;

    while (moreToSearch) {
	if (item.compareTo(current->data) == LESS) {
	    moreToSearch = false;
	}

	if (item.compareTo(current->data) == EQUAL) { // checks if the item is found
	    isFound = true;
	    break;
	}

	else { // if greater, updates predLoc, curreent, and moreToSearch
	    predLoc = current;
	    current = current->next;
	    moreToSearch = (current != head->next);
	}
    }

    if (isFound) {

	if (predLoc == current && isFound) { // if node is found and special case: deleting the only node in the circular list, then head becomes null 
	    head = nullptr;
	}
	
	else {
	    predLoc->next = current->next;
	    if (current == head) { // special case: if the last node in the circular linked list is being deleted, then head is reassigned to predLoc
		head = predLoc;
	    }
	}
    }

    if (!isFound) { // if the item is not found in the list
	cout << "\nItem not in list!" << endl;
	return;
    }
    
    delete current;
    length--;
}

int CircularLinkedList::lengthIs() const {
    return length;
}

void CircularLinkedList::print() {
    NodeType *temp;
    
    if (length == 0) { // if list is empty
    	cout << "List is empty." << endl;
	return;
    }

    else {
	temp = head->next;
    }
    
    do {
    	cout << temp->data.getValue() << " ";
	temp = temp->next;
    }
    
    while (temp != head->next);

    cout << endl;
}
