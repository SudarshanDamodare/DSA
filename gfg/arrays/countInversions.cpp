#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// return the count of inversions in an array

int merge(int arr[], int n, int left, int mid, int right){
  int temp[n]={0};
  int inv_count=0;

  int i=left, j=mid+1, k=left;

  while(i<=mid && j<=right){
    if(arr[i]<=arr[j]){
      temp[k++]=arr[i++];
    }
    else{
      temp[k++]=arr[j++];
      inv_count+=mid+1-i;
    }
  }

  while(i<=mid)
    temp[k++]=arr[i++];

  while(j<=right)
    temp[k++]=arr[j++];

  for(i=left;i<=right;i++){
    arr[i]=temp[i];
  }

  return inv_count;
}

int mergeSort(int arr[], int n, int left, int right){
  int mid, inv_count=0;

  if(left<right){
    mid=(left+right)/2;

    inv_count+=mergeSort(arr, n, left, mid);
    inv_count+=mergeSort(arr, n, mid+1, right);

    inv_count+=merge(arr, n, left, mid, right);
  }

  return inv_count;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n=5;
  int arr[n]={5,3,2,4,1};

  // int t1[6]={1,5,7,2,3,6};
  // cout<<merge(t1, 6, 0, 2, 5);
  // cout<<"Hello";

  cout<<mergeSort(arr, n, 0, 4);

  return 0;
}