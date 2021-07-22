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

// Return the count of nodes in complete binary tree
int countNodes(Node *root){
  int lh=0, rh=0;
  Node *curr=root;

  while(curr){
    lh++;
    curr=curr->left;
  }
  curr=root;
  while(curr){
    rh++;
    curr=curr->right;
  }

  if(lh==rh){
    return pow(2,lh)-1;
  }

  return 1+countNodes(root->left)+countNodes(root->right);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  cout<<countNodes(root);
  return 0;
}