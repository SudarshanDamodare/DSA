#include <bits/stdc++.h>
using namespace std;

int sumUnderModulo(long long a, long long b)
{
  int M = 1000000007;
  //your code here
  long res = (a % M) + (b % M);
  if (res >= M)
  {
    return (res % M);
  }
  return res;
}