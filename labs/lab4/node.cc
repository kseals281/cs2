#include "node.h"

using namespace std;

RelationType Node::ComparedTo(Node other_node)
{
  if(data > other_node.data)
    return GREATER;
  return LESS;
}