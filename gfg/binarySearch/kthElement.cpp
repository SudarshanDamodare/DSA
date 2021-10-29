#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

/*
  Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. 
  The task is to find the element that would be at the k’th position of the final sorted array.
*/


// Merge sort O(K) time O(1) space
int solve(int arr1[], int arr2[], int n, int m, int k){
  int cnt = 0;
  int i = 0, j = 0;
  int curr;

  while (i < n && j < m)
  {
    cnt++;
    if (arr1[i] <= arr2[j])
      curr = arr1[i++];
    else
      curr = arr2[j++];
    if (cnt == k)
      return curr;
  }

  while (i < n)
  {
    cnt++;
    curr = arr1[i++];
    if (cnt == k)
      return curr;
  }
  while (j < m)
  {
    cnt++;
    curr = arr2[j++];
    if (cnt == k)
      return curr;
  }

  return -1;
}


// Binary Search O(log(min(n,m))) time O(1) space
int solve2(int arr1[], int arr2[], int n, int m, int k){
  if(n>m) return solve2(arr2, arr1, m, n, k);
  // considering n<=m
  int low=max(0,k-m);
  int high=min(n,k);
  int l1,l2,r1,r2;

  while(low<=high){
    int cut1=(low+high)>>1;
    int cut2=k-cut1;

    l1=(cut1==0)?INT_MIN:arr1[cut1-1];
    l1=(cut2==0)?INT_MIN:arr2[cut2-1];
    r1=(cut1>=n)?INT_MAX:arr1[cut1];
    r2=(cut2>=m)?INT_MAX:arr2[cut2];

    if(l1<=r2 && l2<=r1){
      return max(l1,l2);
    }
    else if(l1>r2)  high=cut1-1;
    else  low=cut1+1;
  }

  return -1;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}