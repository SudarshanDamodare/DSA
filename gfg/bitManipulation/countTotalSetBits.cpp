#include <bits/stdc++.h>
using namespace std;

int largestPowOf2inRange(int n){
  int x = 0;
  while((1 << x) <= n){
    x++;
  }
  return (x - 1);
}

int countSetBits(int n)
{
  // Your logic here
  if(n ==0)
    return 0;
  int x = largestPowOf2inRange(n);
  int count;
  int a1, a2, a3;
  a1 = ((1 << (x - 1))*x); //number of set bits till highest power of 2
  a2 = (n + 1 - (1 << x)); //number of MSB set bits from highest power of 2 till n
  a3 = (n - (1 << x)); //again same process for remaining numbers
  count = a1 + a2 + countSetBits(a3);
  return count;
}

int main()
{
  int count = countSetBits(17);
  cout<<count;
  return 0;
}