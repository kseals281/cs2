#include "media.h"
#include <iostream>
#include <fstream>

using namespace std;

media::media()
{
  next = NULL;
}

media::~media()
{
  delete next;
}

void media::display()
{}

void media::setTitle(string name)
{
  title = name;
}

void media::setLength(string run_time)
{
  length = run_time;
}

void media::setNext(media& node)
{
  next = &node;
}

string media::getTitle()
{
  return title;
}

string media::getLength()
{
  return length;
}

media* media::getNext()
{
  return next;
}