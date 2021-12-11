// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// ListNode header file

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

class ListNode
{
  public:
    ListNode();
    ListNode(int d);
    ~ListNode();
    int data;
    ListNode *next;
    ListNode *prev;
};

#endif
