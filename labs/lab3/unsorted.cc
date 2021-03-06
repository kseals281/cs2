#include "unsorted.h"
#include "song.h"
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

// Dynamically creates the playlist
void Unsorted::init()
{
  cout << "How many songs would you like in the playlist: ";
  cin >> SIZE;
  songs = new Single[SIZE];
  current = 0;
  length = 0;
}

// Adds a song if the list is not full
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

bool Unsorted::isfull() const
{
  return (length == SIZE);
}

// Deletes the song from the list but not the file. Moves the other songs
// forward to overwrite it's place in the list
void Unsorted::deleteSong(Single song)
{
  int location = 0;
  while(song.ComparedTo(songs[location]) != EQUAL)
  {
    location++;
  }
  if (length > 1 && location != length)
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

// Changes the rating of a song in the list by name of song
void Unsorted::setRating(string name, int new_rating)
{
  for (int i = 0; i < name.length(); ++i)
  {
    name[i] = (char)tolower(name[i]);
  }
  for (int i = 0; i < length; i++)
  {
    if(songs[i].title == name)
      songs[i].rating = new_rating;
  }
}

// Reads the songs into the list from the file
void Unsorted::readSongs()
{
  ifstream songs_file;
  songs_file.open("favSongs.txt");

  while(!songs_file.eof())
  {
    if(length == SIZE)
      break;
    Single song;
    songs_file >> song.title >> song.artist >> song.rating;
    addSong(song);
  }
}

void Unsorted::printList()
{
  cout << endl;
  for (int i = 0; i < length; i++)
  {
    cout << songs[i].title << " by " << songs[i].artist << " rating: "
         << songs[i].rating << endl;
  }
}