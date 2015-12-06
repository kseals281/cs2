#include "song.h"

using namespace std;

// Compares the title of the song and returns an enum based on equality
RelationType Single::ComparedTo(Single other_song)
{
  for (int i = 0; i < other_song.title.length(); i++)
  {
    other_song.title[i] = (char)tolower(other_song.title[i]);
  }
  for (int i = 0; i < title.length(); i++)
  {
    title[i] = (char)tolower(title[i]);
  }
  if (title != other_song.title)
    return NOT_EQUAL;
  else
    return EQUAL;
}