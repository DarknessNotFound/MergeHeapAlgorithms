#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  dynamicArray<int> g(50);
  g.add(30);
  g.add(40);
  g.fillRandom();
  cout << g << endl;
  return 0;
}
