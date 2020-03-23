#include <iostream>
#include <fstream>
#include "ItemType.h"

using namespace std;

/*
  Author: Austin Schultz

  Default Constructor

  Gets an ItemType object ready by initializing value to 0.
 */
ItemType::ItemType() {
    value = 0;
}

/*
  Author: Austin Schultz

  Constructor

  Gets an ItemType object ready by initializing value to the
  given int value.
 */
ItemType::ItemType(int value) {
    this -> value = value;
}

/*
  Author: Austin Schultz

  Returns the appropriate Comparison enum value based
  on whether the given item's value is greater than,
  less than, or equal to this ItemType object's value.
 */
Comparison ItemType::compareTo(ItemType item) {
    if (this -> value > item.getValue()) {
	return GREATER;
    }

    else if (this -> value < item.getValue()) {
	return LESS;
    }

    else {
	return EQUAL;
    }
}

/*
  Author: Austin Schultz

  Returns the value data member.
 */
int ItemType::getValue() const {
    return value;
}

/*
  Author: Austin Schultz

  Sets the value data member to num.

  Allows you to set the value data member
  after initializing an ItemType object.
 */
void ItemType::initialize(int number) {
    this -> value = number;
}

/*
  Author: Austin Schultz

  Prints the value data member.
 */
void ItemType::print() {
    cout << value;
}

