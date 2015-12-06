#ifndef QUE
#define QUE

#include "media.h"

class que
{
public:
  que();
  ~que();
  void addNewSong(string, string);

private:
  media* head;
  media* tail;

};

#endif