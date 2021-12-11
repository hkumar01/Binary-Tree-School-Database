// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

#include "student.h"


//constructor
Student::Student()
{
  id = 0;
  name = "";
  level = "";
  major = "";
  GPA = 0.0;
  advisor = 0;
}

//destructor
Student::~Student(){}

// overloaded constructor, only ID input
Student::Student(int id)
{
  this->id = id;
}

//overloaded constructor, takes all student parameters
Student::Student(int id, string name, string level, string major, double GPA, int advisor)
{
  this->id = id;
  this->name = name;
  this->level = level;
  this->major = major;
  this->GPA = GPA;
  this->advisor = advisor;
}

// setMajor takes a string variable to modify student's major field
void Student::setMajor(string major)
{
  this->major = major;
}

// setGPA takes a double and modifies student's GPA field
void Student::setGPA(double GPA)
{
  this->GPA = GPA;
}

// setAdvisor takes an interger and modifies student's advisor field
void Student::setAdvisor(int adID)
{
  advisor = adID;
}

// getAdvisor returns an integer of student's advisor ID
int Student::getAdvisor()
{
  return advisor;
}

// less than overloaded operator
bool operator< (const Student &left, const Student &right)
{
  return left.id < right.id;
}

// greater than overloaded operator
bool operator> (const Student &left, const Student &right)
{
  return left.id > right.id;
}

// equality overloaded operator
bool operator== (const Student &left, const Student &right)
{
  return left.id == right.id;
}

// Not equal to overloaded operator
bool operator!= (const Student &left, const Student &right)
{
  return left.id != right.id;
}

// prints all student fields
void Student::printInfo()
{
  cout << "STUDENT MEMBER: " << endl;
  cout << "ID: " << id << ", " << "Name: " << name << ", " << "Level: " << level << ", "
  << "Major: " << major << ", " << "GPA: " << GPA << ", " << "Advisor ID: " << advisor << endl;
}

// overloaded insertion operator returns stream 
ostream& operator<< (ostream &output, const Student student)
{
  output << student.id << ", " << student.name << ", " << student.level << ", " << student.major << ", " << student.GPA << ", " << student.advisor;
}
