#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

// find the pivot element in the rotated sorted array
// return how many times the array has been rotated

// output will be the index of the smallest element in the array
// for anti-clockwise rotated

int rotation(int arr[], int n){
  int low=0, high=n-1;

  while(low<=high){
    int mid = low +(high-low)/2;
    // cout<<arr[mid]<<endl;
    
    // prev idx=(mid+n-1)%n and next idx=(mid+1)%n
    if(arr[mid]<=arr[(mid+n-1)%n] && arr[mid]<=arr[(mid+1)%n]){
      return mid;
    }
    if(arr[mid]<=arr[high]){
      high=mid-1;
    }
    else {
      low=mid+1;
    }
  }

  return -1;  // this will indicate that the test case is wrong
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)  cin>>arr[i];
  cout<<rotation(arr, n)<<endl;

  return 0;
}