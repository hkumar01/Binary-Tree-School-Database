// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

#include <iostream>
#include <exception>
#include "faculty.h"
#include "student.h"
#include "database.h"
#include "bst.h"

using namespace std;

int main(int argc, char** argv)
{
  Database *tester = new Database();
  tester->fileReader(); //read file

  tester->executeSelection(); // display menu selection 

  return 0;
}
