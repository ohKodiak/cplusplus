#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	// Default constructor
	//TODO
	LinkedList();
	// Destructor
	//TODO
	~LinkedList();
	// Copy constructor
	//TODO
	LinkedList(const LinkedList& other);
	// Copy assignment
	//TODO
	LinkedList& operator=(const LinkedList& other);
	// Insert a record to the linked list
	//TODO
	void insert(std::string location, int year, int month, double temperature);
	// Clear the content of this linked list
	void clear();

	// The functions below are written already. Do not modify them.
	std::string print() const;
	Node* getHead() const;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
