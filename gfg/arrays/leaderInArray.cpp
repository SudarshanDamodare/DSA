#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n)
{
  vector<int> res;
  int curr_ldr = arr[n - 1];
  res.push_back(curr_ldr);
  for (int i = n - 2; i >= 0; i--){
    if (arr[i] >= curr_ldr){
      curr_ldr = arr[i];
      res.push_back(curr_ldr);
    }
  }
  reverse(res.begin(), res.end());
  return res;
}