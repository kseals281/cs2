#include "node.h"
#include <iostream>

// Compares the number in the other node to this node's number
RelationType Node::ComparedTo(Node* other_node)
{
  if(data < other_node->data)
    return GREATER;
  else if(data == other_node->data)
    return EQUAL;
  return LESS;
}