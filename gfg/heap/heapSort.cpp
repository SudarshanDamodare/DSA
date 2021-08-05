#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// Heap Sort
void maxHeapify(int arr[], int n, int i){
  int largest=i, left=2*i+1, right=2*i+2;

  if(left<n && arr[left]>arr[largest])
    largest=left;
  if(right<n && arr[right]>arr[largest])
    largest=right;
  
  if(largest!=i){
    swap(arr[largest], arr[i]);
    maxHeapify(arr, n, largest);
  }
}

void buildMaxHeap(int arr[], int n){
  for(int i=(n-2)/2;i>=0;i--){
    maxHeapify(arr, n, i);
  }
}

void heapSort(int arr[], int n){
  buildMaxHeap(arr, n);
  for(int i=n-1;i>=1;i--){
    swap(arr[0], arr[i]);
    maxHeapify(arr, i, 0);
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif



  int arr[]={5,8,3,9,1,0};
  heapSort(arr, 6);
  for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}