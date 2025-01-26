/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void printList(Node* head);
void deleteList(Node* head);

int main(int argc, char* argv[])
{
    cout << "this is a test" << endl;
    
    Node* head = new Node(0, nullptr);
    Node* list = head;
    Node* odds = nullptr;
    Node* evens = nullptr;


    //THIS is not the function, it's just for the test so I CAN use a for loop. right?
    for (int i = 1; i <= 10; i++) 
    {
       Node* newNode = new Node(i, nullptr);
       list->next = newNode;
       list = newNode;
    }

    cout << "everything" << endl;
    printList(head);
    split(head, odds, evens);
    cout << "this are odds" << endl;
    printList(odds);
    cout << "this are evens" << endl;
    printList(evens);

    deleteList(odds);
    deleteList(evens);
}


void printList(Node* head) 
{
    if (head != nullptr) 
    {
        cout << head->value << endl;
        printList(head->next);
    }
}

void deleteList(Node* head) 
{
    if (head != nullptr) 
    {
        Node* next = head->next;

        delete head;

        deleteList(next);
    }
}