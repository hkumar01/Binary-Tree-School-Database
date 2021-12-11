// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// database header file

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <sstream>
#include "bst.h"
#include "student.h"
#include "faculty.h"
#include "linkedlist.h"

using namespace std;

class Database
{
  public:
    Database();
    ~Database();
    void fileReader();
    void executeSelection();
    void printMasterFaculty();
    void printMasterStudent();
    void findFaculty(string searchID);
    void findStudent(string searchID);
    void addStudent();
    void addFaculty();
    void printAdvisor(string searchID);
    void createStudentFromFile(string line);
    void createFacultyFromFile(string line);
    void saveFile();
    void printAdviseeInfo(string searchID);
    void deleteStudent(string searchID);
    void deleteFaculty(string searchID);
    void removeAdvisee(string stuSearchID, string facSearchID);
    void changeStudentAdvisor(string stuSearchID, string facSearchID);
    BST<Student> *masterStudent = new BST<Student>();
    BST<Faculty> *masterFaculty = new BST<Faculty>();
  private:
    ofstream studentOutputFile;
    ofstream facultyOuputFile;
};

#endif
