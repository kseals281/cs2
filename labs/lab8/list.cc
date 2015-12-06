#include "list.h"
#include "node.h"
#include <iostream>
#include <fstream>

using namespace std;

mylist::mylist()
{
  head = NULL;
  length = 0;
  max = 0;
}

mylist::~mylist()
{
  node* temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
  delete head;
}

void mylist::addNum()
{
  ifstream file;
  file.open("numbers.txt");
  while(!file.eof())
  {
    node* new_node = new node;
    file >> new_node->data;
    if (new_node->data > max)
      max = new_node->data;
    if (head == NULL)
    {
      head = new_node;
    }
    else
    {
      cout << new_node;
      new_node->next = head;
      head = new_node;
    }
    new_node = NULL;
    delete new_node;
    length++;
  }
  file.close();
  hashtable = new bool[max + 1];
}

bool mylist::InToTable(int int_to_add)
{
  if(hashtable[int_to_add] == false)
  {
    hashtable[int_to_add] = true;
    return false;
  }
  return true;
}

//Complexity O(n)
//Iterates through the list and compares it to the hashmap value
void mylist::removeDuplicates()
{
  node* current;
  node* previous;
  previous = head;
  current = previous->next;
  InToTable(previous->data);
  while(current != NULL)
  {
    if(InToTable(current->data) == true)
    {
      node* node_to_remove;
      node_to_remove = current;
      current = current->next;
      previous->next = current;
      delete node_to_remove;
    }
    previous = current;
    current = current->next;
  }
}

//Iterates through the memory address of the nodes until it finds a match
//Complexity O(n)
void mylist::removeNode(node& node_to_remove)
{
  node* current;
  node* previous;
  previous = head;
  current = previous->next;
  while(current != NULL)
  {
    if (current == node_to_remove)
      previous->next = current->next;
    previous = current;
    current = current->next;
  }
}

void mylist::partition(int value)
{
  node* head_left = NULL, head_right = NULL, head_value = NULL;
  node* tail_left, tail_value;
  node* current = head;
  node* final = new node;
  while(current != NULL)
  {
    if (current->value < value)
    {
      if (head_left == NULL)
      {
        tail_left = current
      }
      current->next = head_left;
      head_left = current;
    }
    if (current->value == value)
    {
      if (head_value == NULL)
      {
        tail_value = current
      }
      current->next = head_value;
      head_value = current;
    }
    if (current->value > value)
    {
      current->next = head_right;
      head_right = current;
    }
  }
  tail_left->next = head_value;
  tail_value->next = head_right;
  head = head_left;
}

void mylist::printList()
{
  node* current;
  current = head;
  while(current != NULL)
  {
    cout << current->data << endl;
    current = current->next;
  }
  delete current;
}