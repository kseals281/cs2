  #include <iostream>

using namespace std;

int main()
{
  int size;
  cin >> size;
  int* var = new int[size];
  var[1] = 5;
  cout << var[1] << endl;
  return 0;
}