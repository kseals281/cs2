#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "sorted.h"

using namespace std;

// Initialize the length
Sorted::Sorted()
{
  length = 0;
}

// Deletes all nodes in the list when object is no longer used.
Sorted::~Sorted()
{
  Node* temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    delete temp;
  }
  delete head;
}

// Reads the values from the file into the linked list
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

// Adds a new node to it's correct ordered position in the list
void Sorted::addNode(Node* new_node)
{
  bool moreToSearch = true;
  Node* current_node = head;
  Node* previous_node = head;
  while ( moreToSearch ) // Run until spot found or end of list
  {
    if(length == 0) // When the list is empty
    {
      head = new Node;
      head->next = new_node;
      break;
    }
    if(current_node == NULL) // End of list
    {
      previous_node->next = new_node;
      break;
    }
    // Compare new node to each node already in the list to find if correct spot
    switch ( new_node->ComparedTo( current_node ) )
    {
      case LESS: // The new node value won't be before the current node
        moreToSearch = true;
        previous_node = current_node;
        current_node = current_node->next;
        break;
      case EQUAL:
      case GREATER: // The new node's value fits right before the current node
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

// Goes through each node and outputs it's value
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

// Walks through the list and removes and duplicates and their pointers. The
// node's next values will be reassigned if something is removed.
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

// Reverses the list by having every node point to what was previously pointing
// to it and the head switching to the other end of the list
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