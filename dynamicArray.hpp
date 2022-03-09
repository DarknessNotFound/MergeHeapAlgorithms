template <typename T>
void dynamicArray<T>::grow()
{
  m_max *= 2;
  T *tmp = new T[m_max];

  for(int i = 0; i < m_size; i++)
    tmp[i] = m_data[i];

  delete[] m_data;
  m_data = tmp;
  return;
}

template <typename T>
void dynamicArray<T>::merge(int start, int mid, int end)
{
  dynamicArray<T> tmp(end-start);
  int i = start;
  int j = mid + 1;
  while( (i <= mid) | (j < end) )
  {
    if( (i < mid) & (j < end) )
    {
      if(m_data[i] <= m_data[j])
      {
        tmp.add(m_data[i]);
        i++;
      }
      else //m_data[i] > m_data[j]
      {
        tmp.add(m_data[j]);
        j++;
      }
    }
    else
    {
      if(i <= mid)
      {
        tmp.add(m_data[i]);
        i++;
      }
      else
      {
        tmp.add(m_data[j]);
        j++;
      }
    }
  }
  cout << "Start: " << start << "   Mid: " << mid << "   End: " << end << endl
       << tmp << endl;
  print();
  cout << endl << endl;
  for(int i = 0; i < (end - start); i++)
  {
    m_data[start + i] = tmp.get_data(start + i);
  }
  return;
}

template <typename T>
void dynamicArray<T>::add(T x)
{
  if(m_size == m_max)
    grow();

  m_data[m_size] = x;
  m_size++;
  return;
}

template <typename T>
void dynamicArray<T>::heapSort()
{
  return;
}

template <typename T>
void dynamicArray<T>::mergeSort(int start, int end)
{
  //Check against single element list
  if(end - start + 1 == 1)
    return;

  int half = (start + end) / 2;
  mergeSort(start, half); //left side
  mergeSort(half + 1, end); //right side
  merge(start, half, end);
  return;
}

template <typename T>
void dynamicArray<T>::fillRandom()
{
  for(int i = m_size; i < m_max; i++)
    add(rand() % 100);
  return;
}

template <typename T>
void dynamicArray<T>::fillAscending()
{
  int num = 0;
  for(int i = m_size; i < m_max; i++)
  {
    add(num);
    num++;
  }
  return;
}

template <typename T>
void dynamicArray<T>::fillDescending()
{
  int num = m_max-m_size-1;
  for(int i = m_size; i < m_max; i++)
  {
    add(num);
    num--;
  }
  return;
}

template <typename T>
void dynamicArray<T>::print()
{
  //Check against empty list
  if(m_size == 0)
  {
    cout << "[]";
    return;
  }

  //Output the list
  cout << "[";
  for(int i = 0; i < m_size; i++)
  {
    if(i + 1 < m_size)
      cout << m_data[i] << ", ";
    else
      cout << m_data[i] << "]";
  }
  return;
}

template <typename T>
ostream& operator<< (ostream& os, const dynamicArray<T>& l)
{

    //Check against empty list
    if(l.m_size == 0)
    {
      os << "[]";
      return os;
    }

    //Output the list
    os << "[";
    for(int i = 0; i < l.m_size; i++)
    {
      if(i + 1 < l.m_size)
        os << l.m_data[i] << ", ";
      else
        os << l.m_data[i] << "]";
    }
    return os;
  }
