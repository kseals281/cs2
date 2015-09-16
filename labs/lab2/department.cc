#include "department.h"
#include <iostream>

void Department::sortUnderGradStudentArrayGPA(int num_students)
{
  sortStudentArrayGPA(students, num_students);
}

void Department::printUnderGradStudents(int index)
{
  printStudents(students, index);
}

void Department::sortGradStudentArrayGPA(int num_students)
{
  int minIndex = 0, startIndex = 0;
  Student temp;
  while (startIndex < num_students)
  {
    for (int i = startIndex; i < num_students; i++)
    {
      if (gradStudents[i].getGPA() < gradStudents[minIndex].getGPA())
        minIndex = i;
    }
    swap(gradStudents[startIndex], gradStudents[minIndex]);
    startIndex++;
    minIndex = startIndex;
  }
}

void Department::printGradStudents(int index)
{
  for (int i = 0; i < index; i++)
  {
    gradStudents[i].printStudent();
  }
}
