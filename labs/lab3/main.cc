#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include "song.h"
#include "unsorted.h"

using namespace std;

Single input(void);
void addtofile(Single);

int main()
{
  Unsorted playlist;
  playlist.init();

  string choice;

  while (choice != "exit")
  {
    Single song;
    cout << "\nChoose an option [add-delete-exit]: ";
    cin >> choice;

    // Converts the entire string to lower case letters
    for (int i = 0; i < choice.length(); i++)
    {
      choice[i] = (char)tolower(choice[i]);
    }

    if (choice != "exit")
      song = input();

    if (choice == "add")
    {
      addtofile(song);
      playlist.addSong(song);
    }

    if (choice == "delete")
    {
      playlist.deleteSong(song);
    }

  }
  return 0;
}

Single input()
{
  Single new_song;
  string title, artist;
  cout << "\nEnter the name of the song: ";
  cin.ignore(); // Clears the input buffer so the getline gets what the user types
  getline(cin, title);
  new_song.title = title;
  cout << "Enter the name of the artist: ";
  getline(cin, artist);
  new_song.artist = artist;
  cout << "Enter your rating for the song out of 100: ";
  cin >> new_song.rating;
  return new_song;
}

void addtofile(Single new_song)
{
  ofstream song_file;
  song_file.open("favSongs.txt", ios_base::app);
  ostringstream converter;
  converter << new_song.rating;
  string rating = converter.str();
  song_file << endl << (new_song.title + " | " + new_song.artist + " | " +
                        rating);
  song_file.close();
}