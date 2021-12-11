// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

//Student object class

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
  public:
    Student();
    ~Student();
    Student(int id);
    Student(int id, string name, string level, string major, double GPA, int advisor);
    void setMajor(string major);
    void setGPA(double GPA);
    void setAdvisor(int adID);
    int getAdvisor();
    void printInfo();
    friend bool operator< (const Student &left, const Student &right);
    friend bool operator> (const Student &left, const Student &right);
    friend bool operator== (const Student &left, const Student &right);
    friend bool operator!= (const Student &left, const Student &right);
    friend ostream& operator<< (ostream &output, const Student printPerson);
    int advisor;
  private:
    int id;
    string name;
    string level;
    string major;
    double GPA;
};

#endif
