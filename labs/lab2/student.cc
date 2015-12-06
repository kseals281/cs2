#include "student.h"
#include <iostream>

using namespace std;

// initializes the values in the class
void Student::init(string init_name, int init_id, float init_GPA)
{
  name = init_name;
  id = init_id;
  GPA = init_GPA;
}

// Get functions for the values
string Student::getName() const
{
  return name;
}

int Student::getid() const
{
  return id;
}

float Student::getGPA() const
{
  return GPA;
}

// Print function for the values
void Student::printStudent() const
{
  cout << "Name: " << name << endl;
  cout << "ID: "  << id << endl;
  cout << "GPA: " << GPA << endl;
}
//This function takes an array of students and the total number
//of students and sorts them in ascending order according to GPA
// template<class S>
void sortStudentArrayGPA(Student arr[], int n)
{
  int minIndex = 0, startIndex = 0;
  while (startIndex < n)
  {
    for (int i = startIndex; i < n; i++)
    {
      if (arr[i].getGPA() < arr[minIndex].getGPA())
        minIndex = i;
    }
    swap(arr[startIndex], arr[minIndex]);
    startIndex++;
    minIndex = startIndex;
  }
}

//This function takes an array of students and the total number
//of students and prints them to console
void printStudents(Student students[], int index)
{
  for (int i = 0; i < index; i++)
  {
    students[i].printStudent();
    cout << endl;
  }
}
