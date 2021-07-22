#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


// Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
// All elements in the array are in the range [0, N-1]
// N * N does not overflow for a signed integer
void rearrange(vector<int> &a){
  int n=a.size();
  for(int i=0;i<n;i++){
    a[i]+=(a[a[i]]%n)*n;
  }
  for(int i=0;i<n;i++)
    a[i]/=n;
}

int main(){
  vector<int> a={4,0,2,1,3};
  rearrange(a);
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  return 0;
}