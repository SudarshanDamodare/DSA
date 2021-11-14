#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

// doubly LL
struct Node
{
  int key,val;
  Node *next, *prev;

  Node(int x, int y)
  {
    key=x;
    val = y;
    next = prev = NULL;
  }
};

// DLL helper functions
void insertFront(Node *head, Node *newNode)
{
  // Node *newNode = new Node(key, val);
  newNode->next = head->next;
  newNode->prev = head;
  head->next = newNode;
  newNode->next->prev = newNode;
}

void removeEnd(Node *tail)
{
  Node *temp = tail->prev;
  tail->prev = temp->prev;
  tail->prev->next = tail;

  delete temp;
}

void deleteNode(Node *t)
{
  Node *prevNode = t->prev, *nextNode = t->next;

  prevNode->next = nextNode;
  nextNode->prev = prevNode;

  delete t;
}


// init func
Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);
void setList(){
  head->next = tail;
  tail->prev = head;
}



// LRU struct
struct LRU{
  int size;
  map<int, Node*> mp;

  LRU(int x){
    size = x;
    setList();
  }

  void get(int key){
    if(mp.find(key)==mp.end())  {cout<<-1<<endl; return;}
    else{
      int val=mp[key]->val;
      // delete the curr Node and insert the Node after head
      deleteNode(mp[key]);
      Node *n=new Node(key,val);
      insertFront(head,n);
      mp[key]=n;
      cout<<mp[key]->val<<endl;
      return;
    }
  }


  void put(int key, int val){
    if(mp.find(key)!=mp.end()){ // if the node is lready present
      deleteNode(mp[key]);
      Node *n=new Node(key,val);
      insertFront(head,n);
      mp[key]=n;
    }
    else{
      if(mp.size()==size){
        // remove the last Node from DLL and insert the newNode at front
        // cout<<"deleting last node\n";
        
        int x=tail->prev->key;
        mp.erase(x);  // removing the key from map
        removeEnd(tail);  // removinf from DLL
      }

      Node *n=new Node(key,val);
      insertFront(head,n);
      mp[key]=n;
    }
  }

};

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif


  struct LRU ob(3);

  ob.put(2,2);
  ob.put(1,1);
  ob.get(2);
  ob.get(1);
  ob.get(2);
  ob.put(3,3);
  ob.put(4,4);
  ob.get(3);
  ob.get(2);
  ob.get(1);
  ob.get(4);

  // cout<<head->next->key<<" "<<head->next->val<<endl;
  return 0;
}