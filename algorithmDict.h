#ifndef ALGORITHMDICT_H
#define ALGORITHMDICT_H

short k_HEAPSORT = 0;
short k_MERGESORT = 1;

string getAlgorithmName(short key)
{
  string name = "";
  switch (key)
  {
    case k_HEAPSORT:
      name = "Heapsort";
      break;

    case k_MERGESORT:
      name = "Mergesort";
      break;

    default:
      name = "\tERROR: Name not found\t"

  }

  return name;
}

short k_RANDOM = 0;
short k_ASCENDING = 1;
short k_DESCENDING = 2;

string getFillType(short key)
{
  string name = "";
  switch (key)
  {
    case k_RANDOM:
      name = "Random";
      break;

    case k_ASCENDING:
      name = "Ascending";
      break;

    case k_DESCENDING:
      name = "Descending";
      break;

    default:
      name = "\tERROR: Name not found\t"

  }

  return name;
}
#endif
