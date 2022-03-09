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
void dynamicArray<T>::merge(int start, int secStart, int size)
{
  dynamicArray<T> tmp(size);
  int i = start;
  int j = secStart;
  while( (i < secStart) && (j < start+size) )
  {
    if(m_data[i] < m_data[j]) //Left side is smaller
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

  while( i < secStart )
  {
    tmp.add(m_data[i]);
    i++;
  }

  while( j < start+size)
  {
    tmp.add(m_data[j]);
    j++;
  }

  for(int a = 0; a < size; a++)
  {
    m_data[start + a] = tmp.get_data(a);
  }
  return;
}

template <typename T>
void dynamicArray<T>::swap(int i, int j)
{
  T tmp = m_data[j];
  m_data[j] = m_data[i];
  m_data[i] = tmp;
  m_swaps++;
  return;
}

template <typename T>
void dynamicArray<T>::heapify(int i)
{
  int lc = 2 * i + 1; //Left Child of i
  int rc = 2 * i + 2; //Right Child of i

  if( lc >= m_size) //Check against leaf
    return;

  if( (rc == m_size) && (m_data[i] < m_data[lc]) )
    swap(i, lc);
  else if ( (m_data[i] < m_data[lc]) || (m_data[i] < m_data[rc]) )
  {
    if(m_data[lc] > m_data[rc])
    {
      swap(i, lc);
      heapify(lc);
    }
    else
    {
      swap(i, rc);
      heapify(rc);
    }
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
  int lc; //Left Child
  int rc; //Right Child
  for(int i = m_size - 1; i >= 0; i--)
    heapify(i);
  return;
}

template <typename T>
void dynamicArray<T>::mergeSort(int start, int size)
{
  //Check against single element list
  if(size == 1)
    return;

  //Half is the starting index of the second list
  //If size is even then... otherwise....
  int secStart = (size % 2) ? ( (size - 1) / 2) + start : (size / 2) + start;
  int secSize = (size % 2) ?  (size + 1) / 2 : size / 2;

  mergeSort(start, size / 2); //left side
  mergeSort(secStart, secSize); //right side
  merge(start, secStart, size);
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
