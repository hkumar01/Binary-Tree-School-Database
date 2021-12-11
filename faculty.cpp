// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

//implementation of faculty class

#include "faculty.h"

//constructor
Faculty::Faculty()
{

}

// destructor
Faculty::~Faculty()
{

}

// overloaded constructor
Faculty::Faculty(int id)
{
  this->id = id;
}

// overloaded constructor
Faculty::Faculty(int id, string name, string level, string department)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->department = department;
  adviseeList = new DoublyLinkedList();
}

// addAdvisee takes integer parameter and adds it to the adviseeList linked list
void Faculty::addAdvisee(int id)
{
  adviseeList->insertFront(id);
}

// deleteAdvisee takes integer parameter and removes value from adviseeList linked list
void Faculty::deleteAdvisee(int id)
{
  adviseeList->removeNode(id);
}

// setDepartment takes string parameter and sets it as department member variable
void Faculty::setDepartment(string department)
{
  this->department = department;
}

// overloaded less than operator
bool operator< (const Faculty &left, const Faculty &right)
{
  return left.id < right.id;
}

// overloaded greater than operator
bool operator> (const Faculty &left, const Faculty &right)
{
  return left.id > right.id;
}

// overloaded equality operator
bool operator== (const Faculty &left, const Faculty &right)
{
  return left.id == right.id;
}

// overloaded not equal operator
bool operator!= (const Faculty &left, const Faculty &right)
{
  return left.id != right.id;
}

// printInfo returns faculty information and adviseeList IDs
void Faculty::printInfo()
{
  cout << "FACULTY MEMBER:" << endl;
  cout << "ID: " << id << ", " << "Name: " << name << ", " << "Level: " << level << ", "<< "Department: " << department << endl;

  for (int i = 0; i < adviseeList->getSize(); ++i)
  {
    int id = adviseeList->removeFront();
    cout << "ID # " << id << endl;

    adviseeList->insertBack(id);
  }
}

// overloaded insertion operator 
ostream& operator<< (ostream &output, const Faculty faculty)
{
  output << faculty.id << ", " << faculty.name << ", " << faculty.level << ", "<< faculty.department;
}
