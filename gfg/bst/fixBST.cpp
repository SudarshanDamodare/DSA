#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct Node{
  int data;
  Node *left, *right;

  Node(int k){
    data=k;
    left=right=NULL;
  }
};

void inorder(Node *root){
  if(!root){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

// Fix the BST whose 2 nodes are swapped
Node *previous=NULL, *first=NULL, *second=NULL;
void findPtrs(Node *root){
  if(!root){
    return;
  }
  findPtrs(root->left);
  if(previous && root->data<previous->data){
    if(!first){
      first=previous;
    }
    second=root;
  }
  previous=root;
  findPtrs(root->right);
}

void fixBST(Node *root){
  findPtrs(root);
  // cout<<first->data<<" "<<second->data<<endl;
  int temp=first->data;
  first->data=second->data;
  second->data=temp;
  inorder(root);
}




int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(18);
  root->left=new Node(60);
  root->left->left=new Node(4);
  root->right=new Node(70);
  root->right->left=new Node(8);
  root->right->right=new Node(80);
  fixBST(root);
  return 0;
}