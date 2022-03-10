#ifndef ALGORITHMTESTING_H
#define ALGORITHMTESTING_H

#include <chrono>
#include "algorithmDict.h"
#include "dynamicArray.h"


struct testResults
{
  short m_algorithm;
  short m_fillType;
  int m_size; //size n
  int m_swaps;
  int m_tmsec; //in microseconds
};

ostream& operator << (ostream& os, const testResults& in);

class algoTesting
{
  private:
    dynamicArray<testResults> testHis; //Record of Test History

  public:

    testResults runTest(short algo, short fillType, int n, string name);

    void printTestHistory();
};

#include "algorithmTesting.hpp"

#endif
