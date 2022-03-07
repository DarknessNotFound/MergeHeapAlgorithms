template <typename T>
dynamicArray::print()
{
  //Check against empty list
  if(m_len == 0)
  {
    cout << "[]";
    return;
  }

  //Output the list
  for(int i = 0; i < m_len; i++)
  {
    cout << "[";
    if(i - 1 == m_len)
      cout << m_data[i] << "]";
    else
      cout << m_data[i] << ", ";
  }
  return;
}
