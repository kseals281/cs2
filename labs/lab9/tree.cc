#include "tree.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

tree::tree()
{
  head = NULL;
}

void tree::insertNode(int num)
{
  node* new_node;
  node* parent;
  new_node->data = num;
  new_node->left_child = NULL;
  new_node->right_child = NULL;
  parent = NULL;

  if(head == NULL)
    head = new_node;
  //Leaves assignments
  else
  {
    node* current;
    current = head;
    // Find parent
    while(current != NULL)
    {
      parent = current;
      if(new_node->data > current->data)
        current = current->right_child;
      else
        current = current->left_child;
    }

    if(new_node->data < parent->data)
       parent->left_child = new_node;
    else
       parent->right_child = new_node;
  }
}