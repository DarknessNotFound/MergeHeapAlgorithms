#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdlib>
using namespace std;

//Forward Declaration
template <typename T>
class dynamicArray;

//Friend function for dynamicArray
template <typename T>
ostream& operator<< (ostream& os, const dynamicArray<T>& l);

template <typename T>
class dynamicArray
{
  private:
    T *m_data;
    int m_max;
    int m_size;
    int m_swaps;
    float m_tmsec;

    void grow();

    void merge();
  public:

    ///////////////////
    ////   Big 3   ////
    ///////////////////

    dynamicArray(): m_max(4), m_size(0), m_swaps(0), m_tmsec(0)
                    { m_data = new T[m_max]; };

    dynamicArray(int max): m_max(max), m_size(0), m_swaps(0), m_tmsec(0)
    {
      //Only allow positive sizes
      assert(m_max > 0 && "\nERROR: array created with nonpositive number.");
      m_data = new T[m_max];
    };

    ~dynamicArray() {delete[] m_data;};


    ///////////////////////////
    ////   Get Functions   ////
    ///////////////////////////

    int get_max() {return m_max;};
    int get_size() {return m_size;};
    int get_swaps() {return m_swaps;};


    ///////////////////////////////
    ////   Data Manipulation   ////
    ///////////////////////////////

    void add(T x);

    void heapSort();
    void mergeSort();

    void fillRandom();
    void fillAscending();
    void fillDescending();
    ////////////////////////
    ////   Print Data   ////
    ////////////////////////

    void printAttributes()
    {
      cout << "Max: " << get_max() << endl;
      cout << "Size: " << get_size() << endl;
      cout << "Swaps: " << get_swaps() << endl;
      return;
    };

    void printTree()
    {
      return;
    }
    // PURPOSE: Prints the list out for easier viewing.
    // OUTPUT: Text is displayed to console.
    void print();

    friend ostream& operator << <> (ostream& os, const dynamicArray<T>& l);
};

#include "dynamicArray.hpp"

#endif
