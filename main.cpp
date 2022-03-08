#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  dynamicArray<int> g(10);
  g.fillRandom();
  g.mergeSort(0, g.get_size());
  cout << "size: " <<g.get_size() << endl;
  cout << g << endl;
  return 0;
}
