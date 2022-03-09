#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  algoTesting t;
  int n[4] = {1000, 10000, 100000, 1000000};
  for(int i = 0; i < 4; i++)
  {
    t.runTest(k_HEAPSORT, k_ASCENDING, n[i]);
    t.runTest(k_HEAPSORT, k_DESCENDING, n[i]);
    t.runTest(k_HEAPSORT, k_RANDOM, n[i]);
    t.runTest(k_MERGESORT, k_ASCENDING, n[i]);
    t.runTest(k_MERGESORT, k_DESCENDING, n[i]);
    t.runTest(k_MERGESORT, k_RANDOM, n[i]);
  }
  t.printTestHistory();
  return 0;
}
