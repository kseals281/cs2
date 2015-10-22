#include "StackType.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

StackType::StackType()
{
  head = NULL;
  first = true;

  for(int i = 0; i < 20; i++)
  {
    int num = (rand() % 50) + 1;
    Push(num);
  }
}

StackType::~StackType()
{
  delete head;
}

void StackType::Push(int item)
{
  NodeType* new_node = new NodeType;
  // cout << "here" << endl;
  if(!first)
  {
    new_node->next = head;
  }
  first = false;
  new_node->info = item;
  head = new_node;
  // cout << endl << head->info << endl;
}

int StackType::Pop()
{
  // cout << head->info << endl;
  NodeType* temp;
  temp = head;
  head = head->next;
  // cout << "here" << endl;
  // cout << endl << (head->next)->info << endl;
  delete temp;
  return head->info;
}

void StackType::recursively_print()
{
  int num;
  if(head->next == NULL)
  {
    return;
  }
  num = Pop();
  recursively_print();
  cout << num << endl;
}
