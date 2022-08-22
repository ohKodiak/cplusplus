#ifndef LINKED_H
#define LINKED_H

#include <string>
#include <iostream>
#include "linked.h"
#include <vector>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
  Node* head;

 public:
  LinkedList() : head{nullptr} {}
  void create(vector<int> vex);
  void print();
  float average();
  void removeMaximum();
  void reverse();
  Node* middle();
  // other member functions
};


#endif