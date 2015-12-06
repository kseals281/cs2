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
  int stack1_pop, stack2_pop, stack3_pop;

  stack2.getValues();

  // Print out the stack and store the output in another stack
  for (int i = 0; i < 20; i++)
  {
    int x = stack2.Pop();
    cout << x << " ";
    stack1.Push(x);
  }

  stack2.Push(stack1.Pop()); // Push the first thing into the other stack

  while(stack1.getLength() > 0) // While still unsorted numbers
  {
    stack2_pop = stack2.Pop();// Get the numbers to compare
    stack1_pop = stack1.Pop();
    if (stack1_pop > stack2_pop) // Add bigger number to sorted stack
    {
      stack2.Push(stack2_pop);
      stack2.Push(stack1_pop);
    }
    else // Move sorted stack to 3rd array until smaller than value from unsorted stack
    {
      while(stack1_pop < stack2_pop) // Move the bigger things to the third stack
      {
        stack3.Push(stack2_pop);
        if (stack2.getLength() == 0)
          break;
        stack2_pop = stack2.Pop();
      }
      stack2.Push(stack2_pop); // Push the smaller thing back onto the stack
      stack2.Push(stack1_pop); // Push the bigger thing onto the stack
      while(stack3.getLength() > 0) //Move everything back to the sorted stack
      {
        stack3_pop = stack3.Pop();
        stack2.Push(stack3_pop);
      }
    }
  }

  cout << endl;

  for (int i = 0; i < 20; i++) // Print out the stack and store it in the other stack
  {
    int x = stack2.Pop();
    cout << x << " ";
    stack1.Push(x);
  }

  cout << endl;

  return 0;
}

