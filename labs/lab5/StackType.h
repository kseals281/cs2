#ifndef STACKTYPE
#define STACKTYPE

struct NodeType;

class StackType
{
public:
  StackType();
  ~StackType();
  void Push(int item);
  int Pop();
  void recursively_print();

private:
  NodeType* head;
  bool first;
};

struct NodeType
{
  int info;
  NodeType* next;
};

#endif