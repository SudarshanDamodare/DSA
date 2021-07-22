#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//using Lumoto partition
int partition(int arr[], int l, int r){
  int pivot=arr[r];
  int i=l-1;
  for(int j=l;j<r;j++){
    if(arr[j]<pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void qSort(int arr[], int l, int r){
  if(l<r){
    int p=partition(arr, l , r);
    qSort(arr, l, p-1);
    qSort(arr, p+1, r);
  }
}

int main(){
  int a[] ={10,4,5,8,11,6,26};
  qSort(a,0,6);
  
  for(int i=0;i<7;i++)
    cout<<a[i]<<" ";
  return 0;
}