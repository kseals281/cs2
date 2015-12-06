#include <iostream>
#include "gradstudent.h"

using namespace std;

// Calls inherited classes' init and initializes the research area
void GradStudent::init(string init_name, int init_id,
                       float init_GPA, string init_research_area)
{
  Student::init(init_name, init_id, init_GPA);
  research_area = init_research_area;
}

// Get function for research area
string GradStudent::getResearchArea() const
{
  return research_area;
}

// Calls inherited classes' print function and expands upon it
void GradStudent::printStudent() const
{
  Student::printStudent();
  cout << "Research Area: " << research_area << endl << endl;
}
