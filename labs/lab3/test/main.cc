#include <iostream>
#include <cctype>

using namespace std;

int main()
{
  // Converts to lower case one character at a time
  char letter;
  cout << "Enter letter: ";
  cin >> letter;
  cout << (char)tolower(letter);

  // Dynamic List
  // int size;
  // cin >> size;
  // int* var = new int[size];
  // var[1] = 5;
  // cout << var[1] << endl;
  return 0;
}