#include <iostream>
#include "node.h"
#include "list.h"

using namespace std;

int main()
{
  mylist mylist1;
  mylist1.addNum();
  mylist1.printList();
  mylist1.removeDuplicates();
  cout << endl << endl;
  mylist1.printList();
  return 0;
}