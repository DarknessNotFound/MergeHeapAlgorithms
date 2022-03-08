#ifndef ALGORITHMTESTING_H
#define ALGORITHMTESTING_H

#include "algorithmDict.h"

struct testResults
{
  short m_algorithm;
  short m_fillType;
  short m_size; //size n
  int m_swaps;
  float m_tmsec;
};

class algoTesting
{
  private:

  public:
    algoTesting();

    testResults runTest(short algo, short fillType, int n);

};

#include "algorithmTesting.hpp"

#endif
