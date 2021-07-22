#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

// Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.
// Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.

int hammingDistance(vector<int> &a){
  ll res=0,n=a.size();
  for(int i=0;i<32;i++){
    int count=0;
    for(int j=0;j<n;j++)
      if(a[j] & (1<<i)) //this checks and count the number of elements with ith bit set
        count++;
    res+=count*(n-count)*2; //n-count gives the number of elements with ith bit not set
  }
  return res%1000000007;
}

int main(){
  vector<int> a ={2,4,6};
  cout<<hammingDistance(a);
  return 0;
}