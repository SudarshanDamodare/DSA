#include <bits/stdc++.h>
using namespace std;

void revInGroups(vector<long long>& arr, int n, int k){
  for(int i=0; i<n; i=i+k){
    int start = i;
    int end = min(i+k-1, n-1);
    while(start<end){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
  }
}

int main(){
  vector<long long> arr = {1,2,3,4,5};
  revInGroups(arr, 5, 3);
  for(int i=0; i<5; i++)
    cout<<arr[i]<<" ";
  return 0; 
}