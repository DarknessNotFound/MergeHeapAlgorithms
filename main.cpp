#include <iostream>
#include <fstream>
#include "algorithmTesting.h"
#include "dynamicArray.h"
using namespace std;

int main()
{
  string outputFile = "";
  algoTesting t;
  int n[4] = {100, 1000, 10000, 100000};

  auto start = std::chrono::high_resolution_clock::now();
  for(int i = 0; i < 4; i++)
  {
    t.runTest(k_HEAPSORT, k_ASCENDING, n[i], "HeapAsce");
    t.runTest(k_HEAPSORT, k_DESCENDING, n[i], "HeapDsce");
    t.runTest(k_HEAPSORT, k_RANDOM, n[i], "HeapRand");
    t.runTest(k_MERGESORT, k_ASCENDING, n[i], "MergeAsce");
    t.runTest(k_MERGESORT, k_DESCENDING, n[i], "MergeDsce");
    t.runTest(k_MERGESORT, k_RANDOM, n[i], "MergeRand");
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  t.printTestHistory();
  cout << "Program Ran in " << duration.count() << " microseconds" << endl;
  return 0;
}
