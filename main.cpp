#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  algoTesting t;
  int n = 10001;
  for(int i = 10; i < n; i *= 10)
  {
    t.runTest(k_HEAPSORT, k_ASCENDING, i);
    t.runTest(k_HEAPSORT, k_DESCENDING, i);
    t.runTest(k_HEAPSORT, k_RANDOM, i);
  }
  for(int i = 10; i < n; i *= 10)
  {
    t.runTest(k_MERGESORT, k_ASCENDING, i);
    t.runTest(k_MERGESORT, k_DESCENDING, i);
    t.runTest(k_MERGESORT, k_RANDOM, i);
  }
  t.printTestHistory();
  return 0;
}
