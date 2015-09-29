#include "unsorted.h"
#include "song.h"
#include <iostream>

using namespace std;

void Unsorted::init()
{
  cout << "How many songs would you like in the playlist: ";
  cin >> SIZE;
  songs = new Single[SIZE];
  current = 0;
  length = 0;
}

void Unsorted::addSong(Single new_song)
{
  if (isfull())
  {
    cout << "\nCannot add song to playlist as the list is full." << endl;
    return;
  }
  songs[length] = new_song;
  length++;
}

int Unsorted::getlength() const
{
  return length;
}

bool Unsorted::isfull() const
{
  return (length == SIZE);
}

Single Unsorted::getnextSingle()
{
  if(current == length - 1)
  {
    Single empty;
    return empty;
  }
  current++;
  return songs[current];
}

// Single Unsorted::getSingle(song_to_look_for) const
// {
//   bool more_to_search;
//   int location = 0;

//   more_to_search = (location < length)

//   while (more_to_search)
//   {
//     switch (Single.ComparedTo( songs[location]))
//     {
//       case NOT_EQUAL:
//         location++;
//         more_to_search = (location < length);
//       case EQUAL:
//         song_to_look_for = songs[location];
//         break;
//     }
//   }
//   return song_to_look_for;
// }

void Unsorted::deleteSong(Single song)
{
  int location = 0;
  while(song.ComparedTo(songs[location]) != EQUAL)
  {
    location++;
  }
  if (length < 1)
    songs[location] = songs[length - 1];
  length--;
  if (current >= length)
  {
    current--;
  }
}

void Unsorted::resetlist()
{
  length = 0;
  current = 0;
}