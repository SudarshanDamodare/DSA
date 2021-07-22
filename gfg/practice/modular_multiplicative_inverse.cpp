int modInverse(int a, int m)
{
  //Your code here
  for (int i = 0; i < m; i++)
  {
    if ((a * i) % m == 1)
    {
      return i;
    }
  }
  return -1;
}