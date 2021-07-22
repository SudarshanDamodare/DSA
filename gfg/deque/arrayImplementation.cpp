#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct Deque{
  int *arr;
  int front,cap,size;
  Deque(int c){
    arr = new int[c];
    cap=c;
    front=0;
    size=0;
  }

  // Funtions here
  bool isEmpty(){
    return (size==0);
  }

  bool isFull(){
    return (size==cap);
  }
  
  void deleteFront(){
    if(isEmpty())
      return;
    front=(front+1)%cap;
    size--;
  }

  void deleteRear(){
    if(isEmpty())
      return;
    size--;
  }

  void insertRear(int x){
    if(isFull())
      return;
    int new_rear=(front+size)%cap;
    arr[new_rear]=x;
    size++;
  }

  void insertFront(int x){
    if(isFull())
      return;
    front=(front-1+cap)%cap;
    arr[front]=x;
    size++;
  }

  int getFront(){
    if(isEmpty())
      return -1;
    return front;
  }

  int getRear(){
    if(isEmpty())
      return -1;
    return (front+size-1)%cap;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}