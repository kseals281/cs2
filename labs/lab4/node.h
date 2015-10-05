#include <string>

using namespace std;

enum RelationType {LESS, GREATER}

struct Node()
{
  int data;
  Node* next;
  RelationType ComparedTo(Node item);
};