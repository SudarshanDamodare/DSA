#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void waveSort(vector<int> &arr){
  int n=arr.size();
  for(int i=1;i<n;i+=2){
    if(arr[i]>arr[i-1])
      swap(arr[i],arr[i-1]);
    if(arr[i]>arr[i+1] && i<=n-2)
      swap(arr[i],arr[i+1]);
  }
}

int main(){
  vector<int> a={2,3,2,1,3,1};
  waveSort(a);
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  return 0;
}