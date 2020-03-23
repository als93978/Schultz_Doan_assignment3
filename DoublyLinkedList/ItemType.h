#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {GREATER, LESS, EQUAL}; // enumeration used when comparing the ItemType elements

class ItemType {
    int value; // private data member for value input
    
 public:
    ItemType(); // default constructor
    ItemType(int value); // constructor for the value input
    Comparison compareTo(ItemType item); // Compares the value of the item with the current object's value and returns GREATER, LESS, or EQUAL
    int getValue() const; // returns the value
    void initialize(int number); // Sets the data member by the variable number
    void print(); // prints the value
};

#endif
