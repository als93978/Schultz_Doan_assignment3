#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    NodeType* current = nullptr;

    while(head != nullptr && tail != nullptr) {
	current = head;
	head = head->next;
	delete current;
    }

    // head will already be = nullptr by the end of the loop
    tail = nullptr;
}

int DoublyLinkedList::lengthIs() const {
    return length;
}

void DoublyLinkedList::insertItem(ItemType& item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;

    NodeType* current = head;
    
    if(head == nullptr && tail == nullptr) { // newNode is being inserted into empty list
	head = newNode;
	tail = newNode;
	
	length++;

	return;
    }
    
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
    
    if(current == nullptr && !isDuplicate) { // newNode is being inserted as last element
	tail->next = newNode;
	newNode->back = tail;
	
	tail = newNode;
	
	length++;
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

void DoublyLinkedList::insertItem(int itemValue) {
    ItemType item(itemValue);

    insertItem(item);
}

void DoublyLinkedList::deleteItem(ItemType& item) {
    NodeType* current = head;

    if(head == nullptr && tail == nullptr) { // trying to delete from empty list
	cout << "You cannot delete from an empty list." << endl;

	return;
    }

    if((item.compareTo(current->data) == EQUAL) && (current->next != nullptr)) { // deleting the first item
	current->next->back = nullptr;
	head = current->next;

	length--;

	delete current;

	return;
    }

    // deleting the only item
    if((item.compareTo(current->data) == EQUAL) && (current->next == nullptr)) {
	head = nullptr;
	tail = nullptr;

	length--;

	delete current;

	return;
    }

    if(item.compareTo(tail->data) == EQUAL) { // deleting the last item
	NodeType* temp = tail->back;

	temp->next = nullptr;

	length--;
	
	delete tail;

	tail = temp;

	return;
    }

    bool isFound = false;
    while(current != nullptr) {
	if(item.compareTo(current->data) == GREATER) { // keep going
	    current = current->next;
	}

	else if(item.compareTo(current->data) == EQUAL) { // item found
	    isFound = true;
	    
	    break;
	}

	else // if given item is less than current item has not been found by now, item isn't in list
	    break;
    }

    if(isFound) { // general case delete
	current->back->next = current->next;
	current->next->back = current->back;

	length--;
	
	delete current;
    }

    else
	cout << "Item not in list!" << endl;
}

void DoublyLinkedList::deleteItem(int itemIndex) {
    ItemType item = searchItem(itemIndex);
    
    deleteItem(item);
}

ItemType DoublyLinkedList::searchItem(int itemIndex) {
    ItemType item;
    
    // index is out of bounds or list is empty 
    if((itemIndex < 0) || (itemIndex > length-1) || (head == nullptr && tail == nullptr)) {
	cout << "Item not found" << endl;

	return item;
    }

    NodeType* current = head;

    int i = 0;
    while(current != nullptr) {	
	if(i == itemIndex) // found item
	    return current->data;

	current = current->next;
	i++;
    }

    return item;
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

