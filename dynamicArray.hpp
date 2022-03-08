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
void dynamicArray<T>::merge()
{
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
void dynamicArray<T>::mergeSort()
{
  return;
}

template <typename T>
void dynamicArray<T>::fillRandom()
{
  return;
}

template <typename T>
void dynamicArray<T>::fillAscending(T start)
{
  T obj = start;
  for(int i = m_size; i < m_max; i++)
  {
    add(obj);
    obj++;
  }
  return;
}

template <typename T>
void dynamicArray<T>::fillDescending(T start)
{
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
