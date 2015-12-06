#include <fstream>
#include <iostream>
#include "songs.h"
#include "media.h"

using namespace std;

song::song()
{
}

void song::display()
{
  cout << "\nSong: " << getTitle() << " " << getLength();
}