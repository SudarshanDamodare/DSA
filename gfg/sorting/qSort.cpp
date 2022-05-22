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
  cout<<"c\n";
  if(l<r){
    int p=partition(arr, l , r);
    qSort(arr, l, p-1);
    qSort(arr, p+1, r);
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif
  int a[] ={15,10,12,3};
  qSort(a,0,3);
  
  for(int i=0;i<7;i++)
    cout<<a[i]<<" ";
  return 0;
}