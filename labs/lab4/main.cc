#include <iostream>
#include "node.h"
#include "sorted.h"

using namespace std;

int main()
{
  Sorted int_list;

  int_list.readFile();
  int_list.printList();
  int_list.removeDuplicates();
  int_list.printList();
  int_list.reverse();
  int_list.printList();

  return 0;
}