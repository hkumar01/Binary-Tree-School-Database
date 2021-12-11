// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// faculty header file 

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

class Faculty
{
  public:
    Faculty();
    ~Faculty();
    Faculty(int id);
    Faculty(int id, string name, string level, string department);
    void setDepartment(string department);
    friend bool operator< (const Faculty &left, const Faculty &right);
    friend bool operator> (const Faculty &left, const Faculty &right);
    friend bool operator== (const Faculty &left, const Faculty &right);
    friend bool operator!= (const Faculty &left, const Faculty &right);
    friend ostream& operator<< (ostream &output, const Faculty printPerson);
    DoublyLinkedList *adviseeList;
    void addAdvisee(int id);
    void deleteAdvisee(int id);
    void printInfo();
  private:
    int id;
    string name;
    string level;
    string department;
};

#endif
