#ifndef STUDENTS
#define STUDENTS

#include <string>

using namespace std;

class Student
{
  public:
    void init(string new_name, int new_id, float new_GPA);
    string getName() const;
    //void setName(new_name);
    int getid() const;
    //void setid(new_id);
    float getGPA() const;
    //void setGPA(new_GPA);
    void printStudent();

  private:
    string name;
    int id;
    float GPA;
};


//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n);

//This function takes an array of students and the total number //of students and prints them to console
void printStudents(Student students[], int index);

#endif
