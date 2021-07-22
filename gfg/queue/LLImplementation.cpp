#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// Implementing Queue using LinkedLists
struct Node{
  int data;
  Node *next;
  Node(int x){
    data=x;
    next=NULL;
  }
};

struct Queue{
  Node *front, *rear;
  int size;
  Queue(){
    front=NULL;
    rear=NULL;
    size=0;
  }

  // Functions here
  void enque(int x){
    Node *temp = new Node(x);
    size++;
    if (front == NULL){
      front=rear=temp;
      return;
    }
    rear->next=temp;
    rear=temp;
  }

  void deque(){
    if(front==NULL)
      return;
    size--;
    Node *todelete=front;
    front=front->next;
    if(front==NULL){
      rear=NULL;
    }
    delete todelete;
  }

  int getSize(){
    return size;
  }

};

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}