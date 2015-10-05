#include "node.h"

using namespace std;

class Sorted
{
public:
  void Sorted();
  void ~Sorted();
  bool isfull() const;
  int getlength() const;

private:
  Node* list;
  int lenth;
  int SIZE;
};