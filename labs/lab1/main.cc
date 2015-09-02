#include "student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  //Declare an instance of the struct Student
  Student a_student;

  //Declare an array of type Student that can hold at least 10
  Student students[10];

  //Read from student.txt and keep track of how many members
  ifstream students_in_file;
  students_in_file.open("student.txt");
  int num_students = -1;

  while (!students_in_file.eof()) {
    num_students++;
    string first_name, last_name;
    students_in_file >> first_name >> last_name;
    students[num_students].name = first_name + " " + last_name;
    students_in_file >> students[num_students].id >> students[num_students].GPA;
  }

  //Call member function to print the struct
  sortStudentArrayGPA(students, num_students);
  printStudents(students, num_students);

  students_in_file.close();

  return 0;
}
