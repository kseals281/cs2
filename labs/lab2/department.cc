#include "department.h"
#include <iostream>

// Calls inherited classes' sort by GPA
void Department::sortUnderGradStudentArrayGPA(int num_students)
{
  sortStudentArrayGPA(students, num_students);
}

// Calls inherited classes' print
void Department::printUnderGradStudents(int index)
{
  printStudents(students, index);
}

// Mimics the regular student sort
void Department::sortGradStudentArrayGPA(int num_students)
{
  int minIndex = 0, startIndex = 0;
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

// Mimics the regular student print
void Department::printGradStudents(int index)
{
  for (int i = 0; i < index; i++)
  {
    gradStudents[i].printStudent();
  }
}
