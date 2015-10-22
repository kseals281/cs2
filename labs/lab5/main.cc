#include "StackType.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
  srand(time(0));

  StackType stack1;
  StackType stack2;
  StackType stack3;

  stack1.recursively_print();

  return 0;
}

