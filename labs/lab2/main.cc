#include "gradstudent.h"
#include "student.h"
#include "department.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  Department department;

  //Read from student.txt and keep track of how many members
  //Also initializes log file
  ifstream undergrads, graduates;
  ofstream logfile;
  logfile.open("log.txt");
  undergrads.open("student.txt");
  int num_undergrads = 0, id, num_grads = 0;
  float GPA;
  string first_name, last_name, name, research_area, message;

  //Reading loop for undergrad. Log if error
  while (!undergrads.eof()) {
    undergrads >> first_name >> last_name >> id >> GPA;
    if (undergrads.fail())
    {
      undergrads.clear();
      getline(undergrads, message);
      message = first_name + " " + last_name + " " + message;
      logfile << message << endl;
    }
    else
    {
      name = first_name + " " + last_name;
      department.students[num_undergrads].init(name, id, GPA);
      num_undergrads++;
    }
  }
  undergrads.close();

  //Read from graduate.txt and keep track of how many members. Log if error
  graduates.open("graduate.txt");
  while (!graduates.eof())
  {
    graduates >> first_name >> last_name >> id >> GPA >> research_area;
    if (graduates.fail())
    {
      graduates.clear();
      getline(graduates, message);
      message = first_name + " " + last_name + " " + message;
      logfile << message << endl;
    }
    else
    {
      name = first_name + " " + last_name;
      department.gradStudents[num_grads].init(name, id, GPA, research_area);
      num_grads++;
    }
  }
  graduates.close();

  // Call member function to print the undergrads in the struct
  department.sortUnderGradStudentArrayGPA(num_undergrads);
  department.printUnderGradStudents(num_undergrads);

  // // Call member function to print the graduates in the struct
  department.sortGradStudentArrayGPA(num_grads);
  department.printGradStudents(num_grads);

  return 0;
}
