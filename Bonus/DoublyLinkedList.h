#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
struct NodeType {
    T data;
    NodeType<T>* next;
    NodeType<T>* back;
};

template <typename T>
class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    int lengthIs() const;
    void insertItem(T& item);
    void deleteItem(T& item);
    void deleteItem(int itemIndex);
    T searchItem(int itemIndex);
    void print();
    void printReverse();

 private:
    NodeType<T>* head;
    NodeType<T>* tail;
    int length;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T>* current = nullptr;

    while(head != nullptr && tail != nullptr) {
	current = head;
	head = head->next;
	delete current;
    }

    // head will already be = nullptr by the end of the loop
    tail = nullptr;
}

template <typename T>
int DoublyLinkedList<T>::lengthIs() const {
    return length;
}

template <typename T>
void DoublyLinkedList<T>::insertItem(T& item) {
    NodeType<T>* newNode = new NodeType<T>;
    newNode->data = item;
    newNode->next = nullptr;
    newNode->back = nullptr;

    NodeType<T>* current = head;
    
    if(head == nullptr && tail == nullptr) { // newNode is being inserted into empty list
	head = newNode;
	tail = newNode;
	
	length++;

	return;
    }
    
    bool isDuplicate = false;
    while(current != nullptr) {
	if(item > current->data) // keep going
	    current = current->next;

	else if(item == current->data) { // duplicate item
	    cout << endl;
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

template <typename T>
void DoublyLinkedList<T>::deleteItem(T& item) {
    NodeType<T>* current = head;

    if(head == nullptr && tail == nullptr) { // trying to delete from empty list
	cout << endl;
	cout << "You cannot delete from an empty list." << endl;

	return;
    }

    if((item == current->data) && (current->next != nullptr)) { // deleting the first item
	current->next->back = nullptr;
	head = current->next;

	length--;

	delete current;

	return;
    }

    // deleting the only item
    if((item == current->data) && (current->next == nullptr)) {
	head = nullptr;
	tail = nullptr;

	length--;

	delete current;

	return;
    }

    if(item == tail->data) { // deleting the last item
	NodeType<T>* temp = tail->back;

	temp->next = nullptr;

	length--;
	
	delete tail;

	tail = temp;

	return;
    }

    bool isFound = false;
    while(current != nullptr) {
	if(item > current->data) { // keep going
	    current = current->next;
	}

	else if(item == current->data) { // item found
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

    else {
	cout << endl;
	cout << "Item not in list!" << endl;
	cout << endl;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteItem(int itemIndex) {
    T item = searchItem(itemIndex);
    
    deleteItem(item);
}

template <typename T>
T DoublyLinkedList<T>::searchItem(int itemIndex) {
    T item;
    
    // index is out of bounds or list is empty 
    if((itemIndex < 0) || (itemIndex > length-1) || (head == nullptr && tail == nullptr))
	return item;

    NodeType<T>* current = head;

    int i = 0;
    while(current != nullptr) {	
	if(i == itemIndex) // found item
	    return current->data;

	current = current->next;
	i++;
    }

    return item;
}

template <typename T>
void DoublyLinkedList<T>::print() {
    NodeType<T>* current = head;

    while(current != nullptr) {
	cout << current->data << " ";

	current = current->next;
    }

    cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T>* current = tail;

    while(current != nullptr) {
	cout << current->data << " ";

	current = current->back;
    }

    cout << endl;
}

#endif

