#ifndef UNSORTED
#define UNSORTED

#include <string>
#include "song.h"

using namespace std;

class Unsorted
{
public:
  void init();
  void addSong(Single new_song);
  int getlength() const;
  Single getnextSingle();
  Single getSingle();
  void resetlist();

private:
  Single* songs;
  int current;
  int length;
  int SIZE;
};

#endif