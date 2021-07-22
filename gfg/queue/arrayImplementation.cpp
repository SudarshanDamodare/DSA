#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// Simple Implementation
struct queue{
  int size,cap;
  int *arr;
  queue(int c){
    cap=c;
    size=0;
    arr = new int[cap];
  }

  void enque(int x){
    if(isFull())
      return;
    arr[size]=x;
    size++;
  }

  void deque(){
    if(isEmpty())
      return;
    for(int i=0;i<size-1;i++){
      arr[i]=arr[i+1];
    }
    size--;
  }

  int getFront(){
    if(isEmpty())
      return -1;
    return 0;
  }

  int getRear(){
    if(isEmpty())
      return -1;
    return size-1;
  }

  bool isFull(){
    return (cap==size);
  }

  bool isEmpty(){
    return (size==0);
  }

  int size(){
    return size;
  }
};


// Efficient Implementation (circular array)
struct Queue{
  int *arr;
  int size,front,cap;

  Queue(int c){
    cap=c;
    arr = new int[cap];
    front=0;
    size=0;
  }

  // functions
  // rear=(front+size-1)%cap
  bool isFull(){
    return (cap==size);
  }

  bool isEmpty(){
    return (size==0);
  }

  int getFront(){
    if(isEmpty())
      return -1;
    return front;
  }

  int getRear(){
    if(isEmpty())
      return -1;
    return ((front+size-1)%cap);
  }

  void enque(int x){
    if(isFull())
      return;
    int rear=getRear();
    rear=(rear+1)%cap;
    arr[rear]=x;
    size++;
  }

  void deque(){
    if(isEmpty())
      return;
    front=(front+1)%cap;
    size--;
  }
};

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}