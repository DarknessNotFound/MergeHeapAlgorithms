testResults algoTesting::runTest(short algo, short fillType, int n, string name)
{
  dynamicArray<int>  test(n);
  testResults testRes;
  ofstream file;
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
      test.fillAscending();
      break;

    case k_DESCENDING:
      test.fillDescending();
      break;

    default:
      assert(false && "ERROR: Invalid fill type");
  }

  if(n <= 100)
  {
    file.open(name);
    file << test << endl;
    file.close();
  }

  auto start = std::chrono::high_resolution_clock::now();
  switch(algo)
  {
    case k_MERGESORT:
      test.mergeSort(0, test.get_size());
      break;

    case k_HEAPSORT:
      test.heapSort();
      break;

    default:
      assert(false && "ERROR: Invalid Algorithm");
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = duration_cast<std::chrono::microseconds>(stop - start);

  if(n <= 100)
  {
    file.open(name, std::fstream::app);
    file << test << endl;
    file.close();
  }

  testRes.m_swaps = test.get_swaps();
  testRes.m_tmsec = duration.count();

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
     << " algorithm." << endl << "\tTime (microsec): " << in.m_tmsec
     << "\n\tSwaps: " << in.m_swaps << endl;
  return os;
}
