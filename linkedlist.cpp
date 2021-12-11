// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

#include "linkedlist.h"

// implementation of Doubly LinkedList

//constructor
DoublyLinkedList::DoublyLinkedList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

// printList will print the lists contents and returns a string
string DoublyLinkedList::printList()
{
  string result = "";
  ListNode *node = front;

  while (node != NULL)
  {
    int ans = node->data;
    result += to_string(ans) + " ";
    node = node->next;
  }

  return result;
}

// isEmpty returns true if linked list size is 0 and false if size greater than 0
bool DoublyLinkedList::isEmpty()
{
  return (size == 0);
}

// getSize returns an unsigned integer for the size of the list
unsigned int DoublyLinkedList::getSize()
{
  return size;
}

// insertFront takes an integer parameter and inserts the element to the front of the list
void DoublyLinkedList::insertFront(int d)
{
  ListNode* node = new ListNode(d);
  if(isEmpty())
  {
    back = node;
  }
  else
  {
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

// insertBack takes an integer parameter and inserts the element to the back of the list
void DoublyLinkedList::insertBack(int d)
{
  ListNode* node = new ListNode(d);
  if(isEmpty())
  {
    front = node;
  }
  else
  {
    //not empty
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

// removeFront removes front integer and returns it
int DoublyLinkedList::removeFront()
{
  if (isEmpty())
  {
    throw runtime_error("List is empty.");
  }
  ListNode *temp = front;

  if (front->next == NULL)
  {
    //only one node in list and its front node
    back->next = NULL;
  }
  else
  {
    //more than one node in List
    front->next->prev = NULL;
  }
  front = front->next;
  temp->next = NULL;
  int result = temp->data;
  --size;
  delete temp;

  return result;
}

// removeBack removes back integer and returns it
int DoublyLinkedList::removeBack()
{
  if (isEmpty())
  {
    throw runtime_error("List is empty.");
  }

  ListNode *temp = back;
  if (back->prev == NULL)
  {
    //only one node in List
    front = NULL;
  }
  else
  {
    //more than one node
    back->prev->next = NULL;
  }

  back = back->prev;
  temp->prev = NULL;
  int data = temp->data;

  delete temp;
  --size;

  return data;
}

// search takes an integer parameter and searches the list for the parameter value, returns integer value if found
int DoublyLinkedList::search(int value)
{
  int index = -1;
  ListNode *current_node = front;

  while (current_node != NULL)
  {
    ++index;
    if (current_node->data == value)
    {
      break;
    }
    else
    {
      current_node = current_node->next;
    }

    if (current_node == NULL)
    {
      index = -1;
    }
  }
  return index;
}

// removeAtPos takes integer parameter (position in list) and removes and returns element in the position
int DoublyLinkedList::removeAtPos(int position)
{
  int index = 0;

  ListNode *current = front;
  ListNode *previous = front;

  while (index != position)
  {
    previous = current;
    current = current->next;
    index++;
  }

  previous->next = current->next;
  current->next = NULL;
  int temp = current->data;
  delete current;
  size--;

  return temp;
}

// removeNode takes interger parameter and removes and returns if element is found in list 
int DoublyLinkedList::removeNode(int value)
{
  if (isEmpty())
  {
    throw runtime_error("Emtpy.");
  }
    //leverage find method to decide whether you look for it or not
    ListNode *curr = front;

    while(curr->data != value)
    {
      curr = curr->next;
      if (curr == NULL)
        return -1;
    }
    //here, found value, now remove
    if (curr == front)
    {
      front = curr->next;
      front->prev = NULL;
    }
    else if (curr == back)
    {
      back = curr->prev;
      back->next = NULL;
    }
    else if ((curr != front) && (curr != back))
    {
      //listnode between front and back
      curr->next->prev = curr->prev;
      curr->prev->next = curr->next;
    }

    curr->next = NULL;
    curr->prev = NULL;
    int data = curr->data;
    --size;
    delete curr;

    return data;
  }
