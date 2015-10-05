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
  bool isfull() const;
  void deleteSong(Single song);
  void resetlist();
  void setRating(string title, int new_rating);
  void readSongs();
  void printList();

private:
  Single* songs;
  int current;
  int length;
  int SIZE;
};

#endif