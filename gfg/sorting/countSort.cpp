#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


//time O(n+k) to sort n elements in the range of 0 to k-1
void countSort(vector<int> &arr){
  int n=arr.size();
  //getting the maximum element in the array
  int k=arr[0];
  for(int i=1;i<n;i++){
    k=max(k,arr[i]);
  }
  //creating the count array
  vector<int> count(k+1,0);
  for(int i=0;i<n;i++)
    count[arr[i]]++;
  //prefix sum of the count array
  for(int i=1;i<=k;i++)
    count[i]+=count[i-1];
  //this will create the sorted array
  vector<int> res(n);
  for(int i=n-1;i>=0;i--) //traversing form last index makes the algo stable
    res[--count[arr[i]]]=arr[i];
  for(int i=0;i<n;i++)
    arr[i]=res[i];
}


int main(){
  vector<int> a={1,2,3,4,1,6,4,3};
  countSort(a);
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  return 0;
}