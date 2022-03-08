#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  dynamicArray<int> g(50);
  g.fillAscending(0);
  cout << g << endl;
  return 0;
}
