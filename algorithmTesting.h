#ifndef ALGORITHMTESTING_H
#define ALGORITHMTESTING_H

#include "algorithmDict.h"
#include "dynamicArray.h"


struct testResults
{
  short m_algorithm;
  short m_fillType;
  short m_size; //size n
  int m_swaps;
  float m_tmsec;
};

ostream& operator << (ostream& os, const testResults& in);

class algoTesting
{
  private:
    dynamicArray<testResults> testHis; //Record of Test History
  public:

    testResults runTest(short algo, short fillType, int n);

    void printTestHistory();
};

#include "algorithmTesting.hpp"

#endif
