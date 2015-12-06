#ifndef LIST
#define LIST
#include <string>
#include "node.h"

class mylist
{
public:
  mylist();
  ~mylist();
  void addNum();
  bool InToTable(int int_to_add);
  void removeDuplicates();
  void removeNode(node& node_to_remove);
  void partition(int value);
  void printList();

private:
  int max;
  node* head;
  int length;
  bool* hashtable;
};
#endif