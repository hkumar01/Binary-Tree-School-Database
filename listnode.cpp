// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// implementation of ListNode for linkedlist

#include "listnode.h"

//constructor
ListNode::ListNode()
{
}

//destructor
ListNode::~ListNode()
{
  //research
  next = NULL;
}

//overloaded constructor 
ListNode::ListNode(int d)
{
  data = d;
  next = NULL;
  prev = NULL;
}
