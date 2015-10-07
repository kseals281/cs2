#ifndef NODE
#define NODE

using namespace std;

enum RelationType {LESS, EQUAL, GREATER};

struct Node
{
  int data;
  Node* next;
  RelationType ComparedTo(Node* other_node);
};

#endif