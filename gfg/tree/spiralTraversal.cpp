#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// Q. Print the tree in spiral form

struct Node{
  int key;
  Node *left, *right;

  Node(int k){
    key=k;
    left=right=NULL;
  }
};

// Method 1 
// O(n) time & O(width) space
void spiralTraversal(Node *root){
  if(!root)
    return;
  
  queue<Node*> q;
  stack<int> s;
  bool reverse=false;

  q.push(root);

  while(!q.empty()){
    int count=q.size();

    for(int i=0;i<count;i++){
      Node *curr=q.front();
      q.pop();

      if(reverse){
        s.push(curr->key);
      } else{
        cout<<curr->key<<" ";
      }

      if(curr->left)
        q.push(curr->left);
      if(curr->right)
        q.push(curr->right);
    }

    // printing the items push in stack i.e reverse order
    if(reverse){
      while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
      }
    }

    reverse=!reverse;
    cout<<endl;
  }
}


// Method 2
// O(n) time & O(width) sapce
void spiralTraversal1(Node *root){
  if(!root)
    return;
  
  stack<Node*> s1,s2;
  s1.push(root);

  while(!s1.empty() || !s2.empty()){
    while(!s1.empty()){
      Node *curr=s1.top();
      s1.pop();

      cout<<curr->key<<" ";
      if(curr->left)
        s2.push(curr->left);
      if(curr->right)
        s2.push(curr->right);
    }

    if(!s2.empty())
      cout<<endl;

    while(!s2.empty()){
      Node *curr=s2.top();
      s2.pop();

      cout<<curr->key<<" ";
      if(curr->right)
        s1.push(curr->right);
      if(curr->left)
        s1.push(curr->left);
    }

    cout<<endl;
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  root->left->left->left=new Node(8);
  root->left->left->right=new Node(9);
  root->right->left->left=new Node(10);

  spiralTraversal(root);
  spiralTraversal1(root);

  return 0;
}