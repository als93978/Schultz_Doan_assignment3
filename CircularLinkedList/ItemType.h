#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {GREATER, LESS, EQUAL}; // enumeration used when comparing the ItemType elements

class ItemType {
    int value; // private data member for value input
    
 public:
    // author: David Doan
    ItemType(); // default constructor
    // author: David Doan
    ItemType(int value); // constructor for the value input
    // author: David Doan
    Comparison compareTo(ItemType item); // Compares the value of the item with the current object's value and returns GREATER, LESS, or EQUAL
    // author: David Doan
    int getValue() const; // returns the value
    // author: David Doan
    void initialize(int num); // Sets the data member by the variable number
};

#endif
