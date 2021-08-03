#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map
#define nn(x) new Node(x)

struct Node{
  int data;
  Node *left, *right;

  Node(int k){
    data=k;
    left=right=NULL;
  }
};

void preorder(Node *root){
  if(!root) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}


// Construct a BST from its level order traversal

Node *constBST(vector<int> a){
  int n=a.size();
  int idx=0;
  Node *root=NULL;

  queue<pair<Node*, pair<int, int>>> q;
  q.push({NULL, {INT_MIN, INT_MAX}});

  while(idx<n && !q.empty()){
    auto p=q.front();
    q.pop();

    Node *parent=p.first;
    int pleft=p.second.first, pright=p.second.second;

    if(a[idx]<pleft || a[idx]>pright){
      continue;
    }

    Node *temp=nn(a[idx++]);

    if(!parent){
      root=temp;
    }
    else{
      if(temp->data<parent->data){
        parent->left=temp;
      }
      else{
        parent->right=temp;
      }
    }

    q.push({temp, {pleft, temp->data}});
    q.push({temp, {temp->data, pright}});
  }

  return root;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  vector<int> a={7,4,12,3,6,8,1,5,10};
  Node *root=constBST(a);
  // cout<<root->data;
  preorder(root);
  return 0;
}