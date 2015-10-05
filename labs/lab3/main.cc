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
string lower(string);
string removeSpace(string);
string getname();

int main()
{
  Unsorted playlist;
  playlist.init();
  playlist.readSongs();

  string choice;

  while (choice != "exit")
  {
    Single song;
    cout << "\nChoose an option [add-delete-rating-print-exit]: ";
    cin >> choice;

    // Converts the entire string to lower case letters
    choice = lower(choice);

    if (choice == "add")
    {
      song = input();
      addtofile(song);
      playlist.addSong(song);
    }

    if (choice == "delete")
    {
      Single song;
      song.title = getname();
      playlist.deleteSong(song);
    }

    if (choice == "rating")
    {
      string name = getname();
      int rating;
      cout << "\nNew rating: ";
      cin >> rating;
      playlist.setRating(name, rating);
    }

    if (choice == "print")
    {
      playlist.printList();
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
  new_song.title = removeSpace(lower(title));

  cout << "Enter the name of the artist: ";
  getline(cin, artist);
  new_song.artist = removeSpace(lower(artist));

  cout << "Enter your rating [0-100]: ";
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
  song_file << endl << (new_song.title + " " + new_song.artist + " " +
                        rating);
  song_file.close();
}

string lower(string word)
{
  for (int i = 0; i < word.length(); i++)
  {
    word[i] = (char)tolower(word[i]);
  }
  return word;
}

string removeSpace(string word)
{
  for (int i = 0; i < word.length(); i++)
  {
    if(word[i] == ' ')
      word[i] = '_';
  }
  return word;
}

string getname()
{
  cout << "\nName of song: ";
  Single song;
  cin.ignore();
  string title;
  getline(cin, title);
  return removeSpace(title);
}