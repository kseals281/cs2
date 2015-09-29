#ifndef STUDENTS
#define STUDENTS
#include <string>

using namespace std;

class Student
{
  public:
    void init(string new_name, int new_id, float new_GPA);
    string getName() const;
    int getid() const;
    float getGPA() const;
    void printStudent() const;

  private:
    string name;
    int id;
    float GPA;
};

//This function takes an array of students and the total number
//of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n);

//This function takes an array of students and the total number
//of students and prints them to console
void printStudents(Student students[], int index);


#endif
