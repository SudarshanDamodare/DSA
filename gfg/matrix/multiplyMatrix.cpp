#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

vector<vector<int>> multiplyMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
  // code here
  vector<vector<int>> res;
  if (A[0].size() != B.size())
  {
    return res;
  }
  res.resize(A.size(), vector<int>(B[0].size()));

  for (int i = 0; i < A.size(); i++)
  {
    for (int j = 0; j < B[0].size(); j++)
    {
      for (int k = 0; k < A[0].size(); k++)
      {
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return res;
}

int main()
{

  return 0;
}