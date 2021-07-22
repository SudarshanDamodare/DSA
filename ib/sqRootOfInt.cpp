#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


// Given an integar A.

// Compute and return the square root of A.

// If A is not a perfect square, return floor(sqrt(A)).

int sqRoot(int A){
  int l = 1, r = A, res = 0;
  while (l <= r)
  {
    ll mid = r + (l - r) / 2;
    ll msq = mid * mid;
    if (msq <= A)
    {
      l = mid + 1;
      res = mid;
      // return mid;
    }
    else
      r = mid - 1;
  }
  return res;
}



int main(){

  return 0;
}