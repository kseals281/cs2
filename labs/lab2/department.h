#ifndef DEPARTMENT
#define DEPARTMENT
#include <string>
#include "student.h"
#include "gradstudent.h"

using namespace std;

struct Department
{
  Student students[15];
  GradStudent gradStudents[15];
  void sortUnderGradStudentArrayGPA(int);
  void printUnderGradStudents(int);
  void sortGradStudentArrayGPA(int);
  void printGradStudents(int);
};

#endif