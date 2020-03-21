#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

/*
  Author: Austin Schultz

  Constructor

  Gets the list ready by setting head and tail to nullptr
  and length to 0.
 */
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

/*
  Author: Austin Schultz

  Destructor

  Deletes all the nodes in the list to avoid memory leaks.
 */
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

/*
  Author: Austin Schultz

  Returns the length data member, giving the length of the list
  (Number of nodes).
 */
int DoublyLinkedList::lengthIs() const {
    return length;
}

/*
  Author: Austin Schultz

  Given an ItemType reference, this function finds the appropriate
  location (preserving the sorted order) in the list based on the
  value of item and the values already in the list, and inserts
  the item wrapped in a NodeType to that location.
 */
void DoublyLinkedList::insertItem(ItemType& item) {
    NodeType* newNode = new NodeType;
    newNode->data = item;
    newNode->next = nullptr;
    newNode->back = nullptr;

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

  This convenience function allows you to put in an int value directly
  into insertItem rather than having to make an ItemType object
  yourself.
  
  The function simply creates an ItemType object with the given
  itemValue int and then passes the ItemType object to the normal
  insertItem function.
 */
void DoublyLinkedList::insertItem(int itemValue) {
    ItemType item(itemValue);

    insertItem(item);
}

/*
  Author: Austin Schultz

  Given an ItemType reference, this function finds the item in the list
  whose value matches that of the given item's value, and deletes the item.
 */
void DoublyLinkedList::deleteItem(ItemType& item) {
    NodeType* current = head;

    if(head == nullptr && tail == nullptr) { // trying to delete from empty list
	cout << endl;
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

    else { // item was not found
	cout << endl;
	cout << "Item not in list!" << endl;
    }
}

/*
  Author: Austin Schultz

  A convenience function that allows you to specify the index of the item
  you want to delete in the list, rather than having to make an ItemType
  object.

  The function uses the searchItem function (described below) to find the
  item that corresponds to the given itemIndex, and then passes that resulting
  ItemType object to the normal deleteItem function.
 */
void DoublyLinkedList::deleteItem(int itemIndex) {
    ItemType item = searchItem(itemIndex);
    
    deleteItem(item);
}

/*
  Author: Austin Schultz

  Given a given index that corresponds to an item in the list,
  this function returns the ItemType object item that corresponds
  to the index.
 */
ItemType DoublyLinkedList::searchItem(int itemIndex) {
    ItemType item(-1);
    
    // index is out of bounds or list is empty 
    if((itemIndex < 0) || (itemIndex > length-1) || (head == nullptr && tail == nullptr))
	return item;

    NodeType* current = head;

    int i = 0;
    while(current != nullptr) {	
	if(i == itemIndex) // found item, internal index is same as given index
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
void DoublyLinkedList::print() {
    NodeType* current = head;

    while(current != nullptr) {
	cout << current->data.getValue() << " ";

	current = current->next;
    }

    cout << endl;
}

/*
  Author: Austin Schultz

  The same as the above print function except it prints the item values out backwards,
  starting at the last item and going to the first item.
 */
void DoublyLinkedList::printReverse() {
    NodeType* current = tail;

    while(current != nullptr) {
	cout << current->data.getValue() << " ";

	current = current->back;
    }

    cout << endl;
}

