#include<iostream>

using std::cout, std::endl;

struct CourseNode {
  std::string course;
  CourseNode* next;
  CourseNode() : course(), next(nullptr) {}
  CourseNode(std::string course) : course(course), next(nullptr) {}
};

// TODO: Write this function
CourseNode* mergeCourses(CourseNode* degree1Head, CourseNode* degree2Head)  {
    CourseNode* currNode1 = degree1Head;
    CourseNode* currNode2 = degree2Head;
    CourseNode* tail;
    //find tail of first plan
    while (currNode2 != nullptr)    {
        if (currNode2->next == nullptr)    {tail = currNode2;}
        currNode2 = currNode2->next;
    }
    //now you know what the tail is
    currNode2 = degree2Head; //reassign
    //all of degree2's nodes will be in the new degree plan
    //now you just need to find which of the degree 1 nodes are not in the degree2 plan and add those degree 2 plan
    bool add = true; //check
    while (currNode1 != nullptr)    { 
        add = true; //reinitialze
        currNode2 = degree2Head; //reinitialize
        while (currNode2 != nullptr)    { 
            if (currNode1->course == currNode2->course) { 
                add = false;
            }
        currNode2 = currNode2->next;
        }
        if (add)    {
            CourseNode* copy = new CourseNode(currNode1->course);
            copy->next = nullptr;
            tail->next = copy;
            tail = copy;
        }
        currNode1 = currNode1->next;
    }
    return degree2Head; //returns head of new linked list that contains the new degree plan
};

void printList(CourseNode* head) {
    CourseNode* cur = head;
    while (cur!=nullptr) {
        cout << cur->course << endl;
        cur = cur->next;
    }
}

int main() {
    CourseNode* degree1Head = new CourseNode("CSCE 120");
    degree1Head->next = new CourseNode("CSCE 181");
    degree1Head->next->next = new CourseNode("CSCE 222");
    degree1Head->next->next->next = new CourseNode("CSCE 331");

    CourseNode* degree2Head = new CourseNode("CSCE 120");
    degree2Head->next = new CourseNode("CSCE 222");
    degree2Head->next->next = new CourseNode("CSCE 350");
    degree2Head->next->next->next = new CourseNode("ECEN 248");

    CourseNode* combined = mergeCourses(degree1Head, degree2Head);

    printList(combined);

// This will produce memory leaks if run but you can ignore

}