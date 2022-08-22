#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include <sstream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureData.h"
#include "TemperatureDatabase.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr),tail(nullptr) {}

LinkedList::~LinkedList() {
	if (head != nullptr)	{
		clear();}}
//TODO
LinkedList::LinkedList(const LinkedList& source) {
	//create a node, start at head, until you reach null ptr of source object, insert node into linked list
	//create node pointer, point towards source's head
	//pointer has access to node's data
	Node* src = source.getHead();
	//Node* temp = src;
	//how does this function access the node created inside the insert function?
	//how do I link the list im created together
	while (src != nullptr)	{
		insert(src->data.id, src->data.year, src->data.month, src->data.temperature);
		//how to link?
		src = src->next;
	}
}
//TODO
LinkedList& LinkedList::operator=(const LinkedList& source) {
	//create a node, start at head, until you reach null ptr of source object, insert node into linked list
	//create node pointer, point towards source's head
	//pointer has access to node's data
	Node* src = source.getHead();
	//Node* temp = src;
	//how does this function access the node created inside the insert function?
	//how do I link the list im created together
	while (src != nullptr)	{
		insert(src->data.id, src->data.year, src->data.month, src->data.temperature);
		//how to link?
		src = src->next;
	}
	return *this;
}
void LinkedList::insert(string location, int year, int month, double temperature) {
	//possible cases
	//empty list, single list, non empty: front, middle, end
	Node* node = new Node(location, year, month, temperature); //already has TemperatureData portion
	//empty, just add
	if (head == nullptr && tail == nullptr)	{
		head = node;
		tail = node;
		return;}
	//non empty
	//front
	if (node->data < head->data)	{
		node->next = head;
		head = node;
		return;}
	//end
	if (tail->data < node->data)	{
		tail->next = node;
		tail = node;
		return;}
	//middle
	Node* currNode = head; 
	//create previous node pointer
	Node* prev = nullptr;
	while(currNode != nullptr)	{
		if (node->data < currNode->data)	{ //insert after currNode, 
			//node->next = currNode->next;
			//currNode->next = node;
			node->next = prev->next;
			prev->next = node;
			return;}
		prev = currNode;
		currNode = currNode->next;
		}}
void LinkedList::clear() {
	while (head != nullptr) { //loops until end
        Node* deleting = head;
        head = head->next;
        delete deleting;}
    head = nullptr;
    tail = nullptr;}
Node* LinkedList::getHead() const {
	return head;
}
string LinkedList::print() const {
	string outputString = "";
	stringstream toPrint;
	Node* iterator = head;
	//Office Hours Notes
	//use ostringstream
	//create sentence
	//put stuff into ostringstream object, convert to string, add to string, return that string
	//template for output is given by prompt
	while (iterator != nullptr)	{
		//create sentence
		//put into ostringstream object
		toPrint << iterator->data.id << " " << iterator->data.year << " " << iterator->data.month << " " << iterator->data.temperature << endl;
		//convert ostream to string
		//add to string
		outputString += toPrint.str();
		toPrint.str("");
		toPrint.clear();
		iterator = iterator->next;}

	return outputString;}
ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

//linkedinlist cpp
//temperature data
//temperature database