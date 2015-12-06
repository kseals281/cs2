#include <iostream>
#include "node.h"
#include "sorted.h"

using namespace std;

int main()
{
  // Object creation
  Sorted int_list;

  // Class function calls
  int_list.readFile();
  int_list.printList();
  int_list.removeDuplicates();
  int_list.printList();
  int_list.reverse();
  int_list.printList();

  return 0;
}