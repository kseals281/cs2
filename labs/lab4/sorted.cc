#include <string>
#include "sorted.h"
#include "node.h"

using namespace std;

void Sorted::Sorted()
{
  cout << "How many songs would you like in the playlist: ";
  cin >> SIZE;
  list = new Node[SIZE];
  current = 0;
  length = 0;
}

void Sorted::~sorted()
{
  Node* tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

bool Sorted::isfull() const
{
  return (length == SIZE);
}

int Sorted::getlength() const
{
  return length;
}