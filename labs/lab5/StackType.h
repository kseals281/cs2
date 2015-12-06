#ifndef STACKTYPE
#define STACKTYPE

struct NodeType;

class StackType
{
public:
  StackType();
  ~StackType();
  void getValues();
  void Push(int item);
  int Pop();
  int getLength();
  // void recursively_print();

private:
  NodeType* head;
  int length;
};

struct NodeType
{
  int info;
  NodeType* next;
};

#endif