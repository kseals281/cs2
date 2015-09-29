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
  bool isfull() const;
  Single getnextSingle();
  // Single getSingle(Single song_to_look_for) const;
  void deleteSong(Single song);
  void resetlist();
  void setRating(string title, int new_rating);

private:
  Single* songs;
  int current;
  int length;
  int SIZE;
};

#endif