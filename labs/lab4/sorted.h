#ifndef SORTED
#define SORTED

#include "node.h"

using namespace std;

class Sorted
{
public:
  Sorted();
  ~Sorted();
  void readFile();
  void addNode(Node*);
  void printList() const;
  void removeDuplicates();
  void reverse();

private:
  Node* head;
  int length;
};

#endif