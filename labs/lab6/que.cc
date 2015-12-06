#include "que.h"
#include "media.h"
#include "video.h"
#include "songs.h"
#include <iostream>
#include <fstream>

using namespace std;

que::que()
{
  head = NULL;
  tail = NULL;
  string name, run_time;
  ifstream vid_file, song_file;
  vid_file.open("videos.txt");
  song_file.open("songs.txt");
  for (int i = 0; i < 1; i++)
  {
    song_file >> name >> run_time;
    addNewSong(name, run_time);
  }
  vid_file.close();
  song_file.close();
}

que::~que()
{
  delete head;
  delete tail;
}

void que::addNewSong(string name, string run_time)
{
  song new_song;
  new_song.setTitle(name);
  new_song.setLength(run_time);
  if (head == NULL)
  {
    head = &new_song;
    tail = &new_song;
  }
  else
  {
    // tail->setNext(new_song);
    // tail = &new_song;
  }
  new_song.display();
}