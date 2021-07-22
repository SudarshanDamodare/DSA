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

// check if the tree is balanced or not
// i.e if for every node the height diff. of left and right subtree should not be greater than 1

int isBalanced(Node *root){
  if(root==NULL)
    return 0;
  
  int lh=isBalanced(root->left);
  if(lh==-1)
    return -1;
  
  int rh=isBalanced(root->right);
  if(rh==-1)
    return -1;
  
  if(abs(lh-rh)>1)
    return -1;
  
  return (max(lh,rh)+1);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->left->left=new Node(40);
  // root->left->left->left=new Node(80);
  root->right=new Node(30);
  root->right->left=new Node(50);
  root->right->right=new Node(60);

  cout<<isBalanced(root);
  return 0;
}