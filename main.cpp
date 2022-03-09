#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  dynamicArray<int> g(5);
  g.fillAscending();
  cout << g << "\tSize: " << g.get_size() << endl;
  g.heapSort();
  cout << g << endl;
  cout << "Swaps: " << g.get_swaps() << endl;
  return 0;
}
