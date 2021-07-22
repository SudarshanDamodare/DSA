#include <bits/stdc++.h>
using namespace std;


vector<int> largestAndSecondLargest(int n, int arr[])
{
  int max1 = INT_MIN, max2 = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    max1 = max(max1, arr[i]);
  }
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < max1)
      max2 = max(arr[i], max2);
  }
  if (max2 == INT_MIN)
    max2 = -1;
  vector<int> res;
  res.push_back(max1);
  res.push_back(max2);
  return res;
}