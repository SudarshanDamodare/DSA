#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<int> intersection(vector<int> &A, vector<int> &B)
{
  int n1 = A.size(), n2 = B.size();
  int i = 0, j = 0;
  vector<int> res;
  while (i < n1 && j < n2)
  {
    if (A[i] > B[j])
      j++;
    else if (A[i] < B[j])
      i++;
    else
    {
      res.push_back(A[i]);
      i++;
      j++;
    }
  }
  return res;
}

int main()
{

  return 0;
}