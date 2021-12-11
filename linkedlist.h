// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// linked list header file 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "listnode.h"

using namespace std;

class DoublyLinkedList
{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(int d);
    void insertBack(int d);
    int removeFront();
    int removeBack();
    int removeNode(int value);
    int find(int value);
    bool isEmpty();
    unsigned int getSize();
    int search(int value);
    int removeAtPos(int position);
    string printList();
    friend ostream& operator<< (ostream &output, const DoublyLinkedList d);
};

#endif
