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
    void deleteIndexItem(int itemIndex);
    T searchItem(int itemIndex);
    void print();
    void printReverse();

 private:
    NodeType<T>* head;
    NodeType<T>* tail;
    int length;
};

/*
  Author: Austin Schultz

  Constructor

  Gets the list ready by setting head and tail to nullptr
  and length to 0.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/*
  Author: Austin Schultz

  Destructor

  Deletes all the nodes in the list to avoid memory leaks.
 */
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

/*
  Author: Austin Schultz

  Returns the length data member, giving the length of the list
  (Number of nodes).
 */
template <typename T>
int DoublyLinkedList<T>::lengthIs() const {
    return length;
}

/*
  Author: Austin Schultz

  Given a reference to an item, this function finds the appropriate
  location (preserving the sorted order) in the list based on the
  value of item and the values already in the list, and inserts
  the item wrapped in a NodeType to that location.
 */
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

/*
  Author: Austin Schultz

  Given a reference to the item, this function finds the item in the list
  whose value matches that of the given item's value, and deletes the item.
 */
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

    else { // item was not found
	cout << endl;
	cout << "Item not in list!" << endl;
    }
}

/*
  Author: Austin Schultz

  A convenience function that allows you to specify the index of the item
  you want to delete in the list, rather than having to pass in a reference
  to the item.

  The function uses the searchItem function (described below) to find the
  item that corresponds to the given itemIndex, and then passes that resulting
  item to the normal deleteItem function.
 */
template <typename T>
void DoublyLinkedList<T>::deleteIndexItem(int itemIndex) {
    T item = searchItem(itemIndex);
    
    deleteItem(item);
}

/*
  Author: Austin Schultz

  Given a given index that corresponds to an item in the list,
  this function returns the item that corresponds to the index.
 */
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

/*
  Author: Austin Schultz

  Iterates through the list and sequentially prints out each item's value.
 */
template <typename T>
void DoublyLinkedList<T>::print() {
    NodeType<T>* current = head;

    while(current != nullptr) {
	cout << current->data << " ";

	current = current->next;
    }

    cout << endl;
}

/*
  Author: Austin Schultz

  The same as the above print function except it prints the item values out backwards,
  starting at the last item and going to the first item.
 */
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

