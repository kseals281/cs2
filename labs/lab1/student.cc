#include "student.h"
#include <iostream>

using namespace std;

void Student::printStudent()
{
  cout << "Name: " << name << endl;
  cout << "ID: "  << id << endl;
  cout << "GPA: " << GPA << endl << endl;
}
//This function takes an array of students and the total number
//of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n) {
  int minIndex = 0, startIndex = 0;
  Student temp;
  while (startIndex < n)
  {
    for (int i = startIndex; i < n; i++)
    {
      if (arr[i].GPA < arr[minIndex].GPA)
        minIndex = i;
    }
    swap(arr[startIndex], arr[minIndex]);
    startIndex++;
    minIndex = startIndex;
  }
}

//This function takes an array of students and the total number
//of students and prints them to console
void printStudents(Student students[], int index){
  for (int i = 0; i < index; i++)
  {
    students[i].printStudent();
  }
}
