#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "sorted.h"

using namespace std;

Sorted::Sorted()
{
  head = new Node;
  length = 0;
}

Sorted::~Sorted()
{
  Node* tempPtr;
  while (head != NULL)
  {
    tempPtr = head;
    head = head->next;
    delete tempPtr;
  }
  delete head;
}

void Sorted::readFile()
{
  ifstream int_file;
  int_file.open("numbers.txt");
  int num;

  while(!int_file.eof())
  {
    Node* new_node = new Node;
    int_file >> new_node->data;
    addNode(new_node);
    new_node = NULL;
    delete new_node;
  }
}

void Sorted::addNode(Node* new_node)
{
  bool moreToSearch = true;
  Node* current_node = head;
  Node* previous_node = head;
  while ( moreToSearch )
  {
    if(length == 0)
    {
      head->next = new_node;
      break;
    }
    if(current_node == NULL)
    {
      previous_node->next = new_node;
      break;
    }
    switch ( new_node->ComparedTo( current_node ) )
    {
      case LESS :
        moreToSearch = true;
        previous_node = current_node;
        current_node = current_node->next;
        break;
      case EQUAL :
      case GREATER :
        previous_node->next = new_node;
        new_node->next = current_node;
        moreToSearch = false;
        break;
    }
  }
  previous_node = NULL;
  delete previous_node;
  current_node = NULL;
  delete current_node;
  length++;
}

void Sorted::printList() const
{
  Node* current_node = head->next;
  while(current_node != NULL)
  {
    cout << current_node->data << ' ';
    current_node = current_node->next;
  }
  cout << endl;
  current_node = NULL;
  delete current_node;
}

void Sorted::removeDuplicates()
{
  Node* current_node = head->next;
  Node* previous_node = head;

  while(current_node != NULL)
  {
    if(previous_node->data == current_node->data)
    {
      previous_node->next = current_node->next;
      delete current_node;
      Node* current_node = previous_node->next;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
  previous_node = NULL;
  delete previous_node, current_node;
}

void Sorted::reverse()
{
  Node* next_node = new Node;
  Node* previous_node = NULL;
  Node* current_node = head->next;

  while(next_node != NULL)
  {
    next_node = current_node->next;
    current_node->next = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }
  head->next = previous_node;
  previous_node = NULL;
  current_node = NULL;
  delete previous_node, current_node, next_node;
}