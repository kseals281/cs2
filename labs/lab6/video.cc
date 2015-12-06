#include <fstream>
#include <iostream>
#include "media.h"
#include "video.h"

using namespace std;

video::video()
{
}

void video::display()
{
  cout << "\nVideo: " << getTitle() << " " << getLength();
}