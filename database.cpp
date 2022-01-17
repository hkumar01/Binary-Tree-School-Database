// Hari Kumar
// 002352411
// hkumar@chapman.edu
// CPSC350-02
// Assignment 6

// implementation of database, executing all database operations for masterFaculty and masterStudent

#include "database.h"

// constructor
Database::Database() {}

//destructor
Database::~Database() {}

// fileReader opens student and faculty files and reads their contents line by line
void Database::fileReader()
{
  ifstream facultyInputFile;
  ifstream studentInputFile;

  facultyInputFile.open("facultyTable.txt");
  studentInputFile.open("studentTable.txt");

  if (!facultyInputFile.is_open())
  {
    cout << "No faculty file detected." << endl;
  }
  else
  {
    string line;
    while (!facultyInputFile.eof())
    {
      getline(facultyInputFile, line);
      createFacultyFromFile(line);
    }
  }

  if (!studentInputFile.is_open())
  {
    cout << "No student file detected." << endl;
  }
  else
  {
    string line;
    while(!studentInputFile.eof())
    {
      getline(studentInputFile, line);
      createStudentFromFile(line);
    }
  }
  facultyInputFile.close();
  studentInputFile.close();
}

// createFacultyFromFile takes string parameter (representing a faculty member and their information)
// insert faculty into masterFaculty
void Database::createFacultyFromFile(string line)
{
  istringstream ss(line);
  string faculty_arr[4];

  string readData;
  int i = 0;

  while (ss.good())
  {
    string substr;
    getline(ss, substr, ',');
    faculty_arr[i] = substr;
    ++i;
  }

  int id = stoi(faculty_arr[0]);
  string name = faculty_arr[1];
  string level = faculty_arr[2];
  string department = faculty_arr[3];

  Faculty addFaculty(id, name, level, department);
  masterFaculty->insert(addFaculty);
}

// createStudentFromFile takes string parameter (representing a student member from their information)
// if student's advisorID does not exist, then student is not created and added to masterStudent
void Database::createStudentFromFile(string line)
{
  istringstream ss(line);
  string student_arr[6];

  string readData;
  int i = 0;

  while(ss.good())
  {
    string substr;
    getline(ss, substr, ',');
    student_arr[i] = substr;
    ++i;
  }

  string str_id = student_arr[0];
  int id = stoi(str_id);

  string name = student_arr[1];
  string level = student_arr[2];
  string major = student_arr[3];

  string str_GPA = student_arr[4];
  double GPA = stod(str_GPA);

  string str_advisorID = student_arr[5];
  int advisorID = stoi(str_advisorID);

  Faculty searchFaculty(advisorID);

  if (masterFaculty->contains(searchFaculty))
  {
    Faculty searchID = masterFaculty->search(advisorID);
    searchID.addAdvisee(id);
    Student addStudent(id, name, level, major, GPA, advisorID);
    masterStudent->insert(addStudent);
  }
}

// executeSelection is a loop displaying the menu screen and list of operaions that can be done
void Database::executeSelection()
{
  string selection = "1";
  while (selection != "13")
  {
    cout << endl;
    cout << "START MENU" << endl;
    cout << "Enter a number to perform database action." << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Exit" << endl;

    cin >> selection;

    if (selection == "1")
    {
      printMasterStudent();
    }
    else if (selection == "2")
    {
      printMasterFaculty();
    }
    else if (selection == "3")
    {
      cout << "Enter Student ID to return respective information." << endl;

      string searchID;
      cin >> searchID;

      findStudent(searchID);
    }
    else if (selection == "4")
    {
      cout << "Enter faculty ID to return respective information." << endl;

      string searchID;
      cin >> searchID;

      findFaculty(searchID);
    }
    else if (selection == "5")
    {
      cout << "Enter student ID." << endl;

      string searchID;
      cin >> searchID;

      printAdvisor(searchID);
    }
    else if (selection == "6")
    {
      cout << "Enter faculty ID to view advisee info." << endl;

      string searchID;
      cin >> searchID;

      printAdviseeInfo(searchID);
    }
    else if (selection == "7")
    {
      addStudent();
    }
    else if (selection == "8")
    {
      cout << "Enter student ID to delete student." << endl;

      string searchID;
      cin >> searchID;

      deleteStudent(searchID);
    }
    else if (selection == "9")
    {
      addFaculty();
    }
    else if (selection == "10")
    {
      string searchID;

      cout << "Enter faculty ID to delete." << endl;
      cin >> searchID;

      deleteFaculty(searchID);
    }
    else if (selection == "11")
    {
      string stuSearchID;
      string facSearchID;

      cout << "Enter student ID to change." << endl;
      cin >> stuSearchID;

      cout << "Enter student's new faculty advisor ID." << endl;
      cin >> facSearchID;

      changeStudentAdvisor(stuSearchID, facSearchID);
    }
    else if (selection == "12")
    {
      string stuSearchID;
      string facSearchID;

      cout << "Enter student ID to remove from faculty advisor." << endl;
      cin >> stuSearchID;

      cout << "Enter faculty ID." << endl;
      cin >> facSearchID;

      removeAdvisee(stuSearchID, facSearchID);
    }
    else if (selection == "13")
    {
      saveFile();
      break;
    }
    else
    {
      cout << "Invalid selection." << endl;
      continue;
    }
  }
}

// saveFile saves masterFaculty and masterStudent to their appropriate files
void Database::saveFile()
{
  ofstream facultyOutputFile;
  ofstream studentOutputFile;

  facultyOuputFile.open("facultyTable.txt");
  studentOutputFile.open("studentTable.txt");

  masterFaculty->treeToFile(facultyOuputFile);
  masterStudent->treeToFile(studentOutputFile);
}

// printMasterFaculty prints the faculty BST
void Database::printMasterFaculty()
{
  masterFaculty->printNodes();
}

// printMasterStudent prints the student BST
void Database::printMasterStudent()
{
  masterStudent->printNodes();
}

// findFaculty takes a string and finds the faculty member based on ID in masterFaculty
void Database::findFaculty(string searchID)
{
  int intID = stoi(searchID);

  Faculty searchFaculty(intID);

  if (masterFaculty->contains(searchFaculty))
  {
    Faculty f =  masterFaculty->search(searchFaculty); //if masterFaculty contains faculy ID being searched for, print faculty information
    f.printInfo();
  }
  else
  {
    cout << "Faculty is not found based on ID." << endl;
  }
}

// findStudent takes a string and finds the student member based on ID in masterStudent
void Database::findStudent(string searchID)
{
  int intID = stoi(searchID);

  Student searchStudent(intID);

  if (masterStudent->contains(searchStudent))
  {
    Student printStudent = masterStudent->search(searchStudent); // if student exists in masterStudent, search for it and print its info
    printStudent.printInfo();
  }
  else
  {
    cout << "Student is not found based on ID" << endl;
  }
}

// addStudent prompts user to enter new student information
// checks to see if advisor ID exists, if not then student is not added to masterStudent
void Database::addStudent()
{
  string str_id;
  string name;
  string level;
  string major;
  string str_GPA;
  string str_advisorID;

  cout << "Enter student ID." << endl;
  cin >> str_id;
  cin.ignore();

  int id = stoi(str_id);

  cout << "Enter student name." << endl;
  getline(cin, name);

  cout << "Enter student level." << endl;
  getline(cin, level);

  cout << "Enter student major." << endl;
  getline(cin, major);

  cout << "Enter student GPA." << endl;
  cin >> str_GPA;

  double GPA = stod(str_GPA);

  cout << "Enter student advisor's ID." << endl;
  cin >> str_advisorID;

  int advisorID = stoi(str_advisorID);

  if (masterFaculty->contains(advisorID))
  {
    Student addStu(id, name, level, major, GPA, advisorID);
    masterStudent->insert(addStu);
    masterFaculty->search(advisorID).addAdvisee(id);
  }
  else
  {
    cout << "Faculty ID not found." << endl;
  }
}

// addFaculty prompts user for new faculty information and adds to masterFaculty
void Database::addFaculty()
{
  string str_id;
  string name;
  string level;
  string department;

  cout << "Enter faculty ID." << endl;
  cin >> str_id;
  cin.ignore();

  int id = stoi(str_id);

  cout << "Enter faculty name." << endl;
  getline(cin, name);

  cout << "Enter faculty level." << endl;
  getline(cin, level);

  cout << "Enter faculty department." << endl;
  getline(cin, department);

  Faculty addFacu(id, name, level, department);
  masterFaculty->insert(addFacu);
}

// printAdvisor takes a string as parameter and searches for student's advisor information based on student ID
void Database::printAdvisor(string searchID)
{
  int studentID = stoi(searchID);

  Student searchStu(studentID);

  if (masterStudent->contains(searchStu))
  {
    cout << masterFaculty->search(masterStudent->search(searchStu).advisor) << endl; // using student ID, search masterStudent for the Student's advisor ID
    // use the advisor ID to search masterFaculty and print contents
  }
  else
  {
    cout << "Student not found based on ID." << endl;
  }
}

//printAdviseeInfo takes string as parameter and searches for faculty advisee information based on faculy ID
// if masterFaculty contains the faculty ID and size of adviseeList is greater than 0, print advisee information
void Database::printAdviseeInfo(string searchID)
{
  int intID = stoi(searchID);
  Faculty searchFaculty(intID);

  if (masterFaculty->contains(searchFaculty))
  {
    Faculty findFaculty = masterFaculty->search(searchFaculty);

    if (findFaculty.adviseeList->getSize() == 0)
    {
      cout << "Faculty has no advisees." << endl;
    }
    else
    {
      for (int i = 0; i < findFaculty.adviseeList->getSize(); ++i)
      {
        int id = findFaculty.adviseeList->removeBack();

        Student searchStudent(id);
        cout << masterStudent->search(searchStudent) << endl;

        findFaculty.adviseeList->insertFront(id);
      }
    }
  }
  else
  {
    cout << "Faculty is not found based on ID." << endl;
  }
}

// deleteStudent takes string parameter, searches for student based on student ID
// and deletes student from masterStudent if student exists
void Database::deleteStudent(string searchID)
{
  int intID = stoi(searchID);

  Student searchStudent(intID);

  if (masterStudent->contains(searchStudent))
  {
    int advisorSearchID = masterStudent->search(searchStudent).advisor; // grab the advisor ID number
    masterStudent->deleteNode(searchStudent); // delete the  student from the tree
    Faculty toDelete = masterFaculty->search(advisorSearchID);
    toDelete.deleteAdvisee(intID); // remove the student from the advisor advisee List
  }
  else
  {
    cout << "Student not found based on ID." << endl;
  }
}

// deleteFaculty takes string parameter, searches for faculty based on ID, and delete if found
// and removes faculty's advisees from its list, assigns those advisee with 0 as advisor ID
void Database::deleteFaculty(string searchID)
{
  int facID = stoi(searchID);

  Faculty searchFaculty(facID);

  if (masterFaculty->contains(searchFaculty))
  {
    DoublyLinkedList *delAdvisorList = masterFaculty->search(searchFaculty).adviseeList; // pointer to advisors adviseeList

    while (delAdvisorList->getSize() > 0)
    {
      int adviseeID = delAdvisorList->removeFront();
      Student searchStudent = Student(adviseeID);

      masterStudent->search(searchStudent).setAdvisor(0); // assign student with zero
    }
    masterFaculty->deleteNode(searchFaculty);
  }
  else
  {
    cout << "Faculty not found based on ID." << endl;
  }
}

// changeStudentAdvisor takes two string parameters, changes student advisor ID to new specified ID
// only if both student and faculty IDs exist
void Database::changeStudentAdvisor(string stuSearchID, string facSearchID)
{
  int stuID = stoi(stuSearchID);
  int facID = stoi(facSearchID);

  Student searchStudent(stuID);
  Faculty searchFaculty(facID);

  if (masterFaculty->contains(searchFaculty) && masterStudent->contains(searchStudent))
  {
    //search for student's former advisor id to remove students id from their list
    Faculty deleteStudentID = masterFaculty->search(masterStudent->search(searchStudent).advisor);
    deleteStudentID.deleteAdvisee(stuID);

    // search for new advisor, add student ID to new faculty adviseeList
    Faculty newStudentAdvisor = masterFaculty->search(searchFaculty);
    newStudentAdvisor.addAdvisee(stuID);

    // change student's advisor ID to new advisor ID
    Student stu = masterStudent->search(searchStudent);
    stu.setAdvisor(facID);
  }
  else
  {
    cout << "Student or Faculty ID were not found" << endl;
  }
}

// removeAdvisee takes two string parameters, removes advisee from advisor list
// only if both student and faculty IDs exist
void Database::removeAdvisee(string stuSearchID, string facSearchID)
{
  int stuID = stoi(stuSearchID);
  int facID = stoi(facSearchID);

  Student searchStudent(stuID);
  Faculty searchFaculty(facID);

  if (masterStudent->contains(searchStudent) && masterFaculty->contains(searchFaculty))
  {
    Student removeAdvisor = masterStudent->search(searchStudent);
    removeAdvisor.setAdvisor(0); // search for student and set student advisor to 0
    Faculty f = masterFaculty->search(masterStudent->search(searchStudent).advisor); // get faculty ID for student and remove from faculty adviseeList
    f.deleteAdvisee(stuID);
  }
  else
  {
    cout << "Student or Faculty ID were not found" << endl;
  }
}
