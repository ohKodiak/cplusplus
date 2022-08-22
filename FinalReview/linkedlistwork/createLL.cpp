#include <iostream>
#include "linked.h"
#include <vector>
#include <string>

using namespace std;

//you have a class linkedlist and node
//linkedlist holds head
//node holds the value and the pointer that the node connects to

void LinkedList::create(vector<int> vex)   {
    int size = 0;
    size = vex.size();
    Node* node = new Node(vex.at(0));
    head = node;
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(vex.at(i));
        node->next = newNode;  //removed .next
        node = newNode;
    }
}
//----------------------------------------------------------------------
//print
void LinkedList::print()    {
    Node* currNode = head;
    while (currNode != nullptr) {
        cout << currNode->value << endl;
        currNode = currNode->next;}
    }
//----------------------------------------------------------------------
//average function
float LinkedList::average() {
    float sum = 0.0;
    float count = 0;
    float average = 0.0; 
    Node* traverse = this->head;
    while (traverse != nullptr) {
        sum += traverse->value;
        count += 1;
        traverse = traverse->next;}
    average = sum / count;
    return average;
    
}
//----------------------------------------------------------------------
//remove max function
void LinkedList::removeMaximum(){
    //iterate through and figure out which one is the maximum first
    int holdMax = 0;
    Node* traverse = this->head;
    while (traverse != nullptr) {
        if (traverse->value > holdMax)  {
            holdMax = traverse->value;}
        traverse = traverse->next;
        }
    traverse = this->head;
    Node* holdprev = nullptr;
    while (traverse != nullptr) {
        
        //will need a case for if it is the head, tail, or in the middle
        if (traverse->value >= holdMax) {
            //if head
            if (this->head == traverse)   {
                this->head = traverse->next;
                traverse->next = nullptr; //disconnect
                traverse = this->head;
                //cout << "here2" << endl;
                continue;} 
            else if (traverse->next == nullptr)  {
                holdprev->next = nullptr;
                //cout << "here3" << endl;
                break;}
            else    {
                holdprev->next = traverse->next; //link previous to next over current
                traverse->next = nullptr;} //disconnect current from list
                traverse = holdprev->next; //move pointer from current to next
                //cout << "here4" << endl;
                
        }
        holdprev = traverse;
        traverse = traverse->next;
    }
}
//----------------------------------------------------------------------
//reverse a linked list
void LinkedList::reverse()  {
    if (head == nullptr)    {
        cout << head->value;
        return;}
    Node* currNode = head;
    Node* previous = nullptr;
    Node* next = nullptr;
    //for head to tail
    while (currNode != nullptr) {
        next = currNode->next; //next in line
        currNode->next = previous; //changes direction of link
        previous = currNode; //gives previous value
        head = currNode; //moves head along
        currNode = next; //moves pointer along
    }
}
//----------------------------------------------------------------------
//find middle element
Node* LinkedList::middle()   {
    if (head == nullptr)    {
        return nullptr;
    }
    int counter = 0;
    int middle = 0;
    int i = 1;
    Node* currNode = this->head;
    while (currNode != nullptr) {
        counter += 1;
        currNode = currNode->next;}
    middle = (counter / 2) + 1;
    currNode = head;
    while (currNode != nullptr) {
        if (i == middle)   {
            return currNode;}
        i += 1;
        currNode = currNode->next;}
    return currNode; // should never get here
}

//----------------------------------------------------------------------