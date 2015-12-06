#ifndef MEDIA
#define MEDIA
#include <string>
#include <fstream>

using namespace std;

class media
{
public:
  media();
  ~media();
  virtual void display();
  void setTitle(string);
  void setLength(string);
  void setNext(media&);
  string getTitle();
  string getLength();
  media* getNext();

private:
  string title;
  string length;
  media* next;

};



#endif