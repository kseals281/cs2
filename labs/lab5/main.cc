#include "StackType.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(0));

  StackType stack1;
  stack1.recursively_print();
  // cout << stack1.Pop() << endl << stack1.Pop() << endl;

  return 0;
}

