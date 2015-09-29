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
  songs[length] = new_song;
  length++;
}

// int Unsorted::getlength() const
// {
//   return length;
// }

// bool isfull() const
// {
//   return (length == SIZE);
// }

// Single Unsorted::getnextSingle()
// {
//   current++;
//   song = songs[current];
// }
