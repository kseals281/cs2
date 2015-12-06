#include "StackType.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

StackType::StackType()
{
  length = 0;
  head = NULL;
}

StackType::~StackType()
{
  delete head;
}

void StackType::getValues()
{
  for(int i = 0; i < 20; i++)
  {
    // int num = (rand() % 50) + 1;
    // Push(num);
    Push((i + 14) % 20);
  }
}

void StackType::Push(int item) // Put new item in stack and increase length by 1
{
  length++;
  NodeType* new_node = new NodeType;
  new_node->next = head;
  new_node->info = item;
  head = new_node;
}

int StackType::Pop() // Return an item from the stack and decrease length
{
  length--;
  int x;
  x = head->info;
  NodeType* temp;
  temp = head;
  head = head->next;
  delete temp;
  return x;
}

int StackType::getLength()
{
  return length;
}

// void StackType::recursively_print()
// {
//   int num;
//   if(head->next == NULL)
//   {
//     return;
//   }
//   num = Pop();
//   recursively_print();
//   cout << num << endl;
// }

