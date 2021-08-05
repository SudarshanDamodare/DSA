#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

class MinHeap{
  int* arr;
  int size;
  int capacity;
  MinHeap(int c){
    arr=new int[c];
    size=0;
    capacity=c;
  }

  int left(int i){
    return 2*i+1;
  }
  int right(int i){
    return 2*i+2;
  }
  int parent(int i){
    return (i-1)/2;
  }

  // Insert and element in minHeap
  void insert(int x){
    if(size==capacity)  return;
    size++;
    arr[size-1]=x;

    int i=size-1;
    while (i!=0 && arr[parent(i)]>arr[i]){
      swap(arr[i], arr[parent(i)]);
      i=parent(i);
    }
  }

  // Heapify the min heap
  void minHeapify(int i){
    int l=left(i), r=right(i);
    int smallest=i;

    if(l<size && arr[l]<arr[smallest])
      smallest=l;
    if(r<size && arr[i]<arr[smallest])
      smallest=r;

    if(smallest!=i){
      swap(arr[i], arr[smallest]);
      minHeapify(smallest);
    }
  }

  int extractMin(){
    if(size==0){
      return INT_MAX;
    }
    if(size==1){
      size--;
      return arr[0];
    }
    swap(arr[0], arr[size-1]);
    size--;
    minHeapify(0);

    return arr[size];
  }

  void decreaseKey(int i, int x){
    arr[i]=x;
    while(i!=0 && arr[parent(i)]>arr[i]){
      swap(arr[i], arr[parent(i)]);
      i=parent(i);
    }
  }

  void deleteNode(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
  }

  void buildHeap(){
    for (int i = (size - 2) / 2; i >= 0; i--){
      minHeapify(i);
    }
  }

};



int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}