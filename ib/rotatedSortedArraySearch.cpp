#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

// Given an array of integers A of size N and an integer B.

// array A is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

// You are given a target value B to search. If found in the array, return its index, otherwise return -1.

int rotatedSearch(vector<int> &A, int B)
{
  int n = A.size();
  int l = 0, r = n - 1;
  while (l <= r)
  {
    int mid = r + (l - r) / 2;
    if (A[mid] == B)
      return mid;
    else if (A[l] < A[mid])
    {
      if (B >= A[l] && B < A[mid])
        r = mid - 1;
      else
        l = mid + 1;
    }
    else
    {
      if (B > A[mid] && B <= A[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return -1;
}

int main()
{

  return 0;
}