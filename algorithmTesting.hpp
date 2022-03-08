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
      test.fillAscending();
      break;

    case k_DESCENDING:
      test.fillDescending();
      break;

    default:
      assert(false & "ERROR: Invalid fill type");
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
      assert(false & "ERROR: Invalid Algorithm")
  }

  testRes.m_swaps = test.get_swaps();
  testRes.m_tmsec = test.get_

}
