#include <iostream>
#include "algorithmTesting.h"
#include "dynamicArray.h"

using namespace std;

int main()
{
  dynamicArray<int> test(5);
  cout << test << endl;
  for(int i = 0; i < 10; i++)
  {
    test.add(i);
    cout << test << endl;
  }

  test.printAttributes();
  return 0;
}
