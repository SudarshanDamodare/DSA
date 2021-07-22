#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct Node{
  int key;
  Node *left, *right;

  Node(int k){
    key=k;
    left=right=NULL;
  }
};


// O(n) time & O(n) space, space will be equal to width of binary tree
void printLevel(Node *root){
  if(!root)
    return;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    Node *curr=q.front();
    q.pop();
    cout<<curr->key<<" ";

    if(curr->left)
      q.push(curr->left);
    if(curr->right)
      q.push(curr->right);
  }
}


// O(n+h) or O(n) time & O(n) space
void printLevelLine(Node *root){
  if(!root)
    return;
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(q.size()>1){
    Node *curr=q.front();
    q.pop();

    if(curr==NULL){
      cout<<"\n";
      q.push(NULL);
      continue; // this condition is important as below this we are accessing curr's elements
    }

    cout<<curr->key<<" ";

    if(curr->left)
      q.push(curr->left);
    if(curr->right)
      q.push(curr->right);
  }
}


void printLevelLine2(Node *root){
  if(!root)
    return;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int count=q.size();
    
    for(int i=0;i<count;i++){
      Node *curr=q.front();
      q.pop();
      cout<<curr->key<<" ";
      if(curr->left)
        q.push(curr->left);
      if(curr->right)
        q.push(curr->right);
    }

    cout<<"\n";
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->right->right=new Node(50);
  printLevel(root);
  cout<<endl;
  printLevelLine(root);
  cout<<endl;
  printLevelLine2(root);
  return 0;
}