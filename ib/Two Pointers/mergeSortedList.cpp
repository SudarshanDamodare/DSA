#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void merge(vector<int> &A, vector<int> &B)
{
  int n1 = A.size(), n2 = B.size();
  vector<int> res(n1 + n2);
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2)
  {
    if (A[i] <= B[j])
    {
      res[k] = A[i];
      i++;
      k++;
    }
    else
    {
      res[k] = B[j];
      j++;
      k++;
    }
  }
  while (i < n1)
  {
    res[k] = A[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    res[k] = B[j];
    j++;
    k++;
  }
  A = res;
}

int main()
{

  return 0;
}