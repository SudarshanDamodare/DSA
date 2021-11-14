#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map


void heapify(vector<int> &heap, int curr, int size){
  int largest=curr;
  int l=2*curr+1; // left child
  int r=2*curr+2; // right child

  if(l<size && heap[l]>heap[largest]) largest=l;
  if(r<size && heap[r]>heap[largest]) largest=r;
  if(largest!=curr){
    swap(heap[curr],heap[largest]);

    heapify(heap,largest,size);
  }
}

void heapSort(vector<int> &v){
  // build heap
  for(int i=v.size()/2-1;i>=0;i--){
    heapify(v,i,v.size());
  }
  // extract max/min and heapify
  for(int i=v.size()-1;i>0;i--){
    int temp=v[0];  // swap heap root with last element
    v[0]=v[i];
    v[i]=temp;

    heapify(v,0,i); // heapify root with heap size i
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n=5;
  vector<int> v={5,1,2,10,6};
  heapSort(v);
  for(auto x: v)  cout<<x<<" ";
  return 0;
}