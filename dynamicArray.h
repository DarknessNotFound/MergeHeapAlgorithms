#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

//Forward Declaration
template <typename T>
class dynamicArray;

template <typename T>
class dynamicArray
{
  private:
    T *m_data;
    int m_len;
    int m_swaps;
  public:
    dynamicArray(): m_len(4), m_swaps(0) { m_data = new T[m_len]; };

    dynamicArray(int len): m_len(len), m_swaps(0)
    {
      assert(m_len > 0); //Only allow positive sizes
      m_data = new T[len];
    };

    ~dynamicArray() {delete[] m_data;};

    void add(T x);

    void heapSort();
    void mergeSort();
    void merge();

    // PURPOSE: Prints the list out for easier viewing.
    // OUTPUT: Text is displayed to console.
    void print();
};

#include "dynamicArray.hpp"
#endif
