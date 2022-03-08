testResults algoTesting::runTest(short algo, short fillType, int n)
{
  dynamicArray<int>  test(n);
  testResults testRes;
  testRes.m_algorithm = algo;
  testRes.m_fillType = fillType;
  testRes.m_size = n;
  testRes.m_swaps = 0;
  testRes.m_tmsec = 0;

  switch(fillType)
  {
    case k_RANDOM:
      test.fillRandom();
      break;

    case k_ASCENDING:
      test.fillAscending(0);
      break;

    case k_DESCENDING:
      test.fillDescending(0);
      break;

    default:
      assert(false && "ERROR: Invalid fill type");
  }

  switch(algo)
  {
    case k_HEAPSORT:
      test.heapSort();
      break;

    case k_MERGESORT:
      test.mergeSort();
      break;

    default:
      assert(false && "ERROR: Invalid Algorithm");
  }

  testRes.m_swaps = test.get_swaps();
  testRes.m_tmsec = test.get_tmsec();

  testHis.add(testRes);
  return testRes;
}

void algoTesting::printTestHistory()
{
  cout << "Printing test history..." << testHis << endl;
}

ostream& operator << (ostream& os, const testResults& in)
{
  os << "\nTest on an " << getFillType(in.m_fillType) << " array of n="
     << in.m_size << " using the " << getAlgorithmName(in.m_algorithm)
     << " algorithm." << endl << "\tTime (msec): " << in.m_tmsec
     << "\n\tSwaps: " << in.m_swaps << endl;
  return os;
}
