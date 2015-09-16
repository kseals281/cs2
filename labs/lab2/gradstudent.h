#ifndef G_STUDENT
#define G_STUDENT
#include <string>
#include "student.h"

using namespace std;

class GradStudent : public Student {
  public:
    void init(
          string new_name, int new_id, float new_GPA, string new_research_area);
    string getResearchArea() const;
    void printStudent() const;

  private:
    string research_area;
};
#endif
