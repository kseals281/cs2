#ifndef DEPARTMENT // So that the struct isn't redefined
#define DEPARTMENT
#include <string>
#include "student.h"
#include "gradstudent.h"

using namespace std;

struct Department // Both the undergrad and graduate functions and arrays
{
  Student students[15];
  GradStudent gradStudents[15];
  void sortUnderGradStudentArrayGPA(int);
  void printUnderGradStudents(int);
  void sortGradStudentArrayGPA(int);
  void printGradStudents(int);
};

#endif