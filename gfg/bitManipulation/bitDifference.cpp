#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n){
  int res = 0;
  while(n > 0){
    n = (n & (n - 1));
    res++;
  }
  return res;
}
int countBitsFlip(int a, int b){
    
  // Your logic here
  int x = a ^ b; //this gives the different bits in a and b
  int count = countSetBits(x); //this counts the set bits of x i.e the different bits of a and b
}