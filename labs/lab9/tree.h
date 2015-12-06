#ifndef TREE
#define TREE
#include "node.h"

class tree
{
public:
  tree();
  void insertNode(int num);
  void inOrder();
  void postOrder();
  void preOrder();

private:
  node* head;

};
#endif