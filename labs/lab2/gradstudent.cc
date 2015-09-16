#include <iostream>
#include "gradstudent.h"

using namespace std;

void GradStudent::init(string init_name, int init_id,
                       float init_GPA, string init_research_area)
{
  Student::init(init_name, init_id, init_GPA);
  research_area = init_research_area;
}

string GradStudent::getResearchArea() const
{
  return research_area;
}

void GradStudent::printStudent() const
{
  Student::printStudent();
  cout << "Research Area: " << research_area << endl << endl;
}
