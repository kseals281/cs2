#ifndef SONG
#define SONG

#include <string>

using namespace std;

enum RelationType {NOT_EQUAL, EQUAL};

struct Single
{
  string artist;
  string title;
  float rating;
  RelationType ComparedTo(Single other_song);
};

#endif