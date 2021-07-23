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

// replace the node data with sum of node->left->data + node->right->data + node->data
void sumReplace(Node *root){
  if(!root)
    return;
  
  sumReplace(root->left);
  sumReplace(root->right);

  if(root->left){
    root->key+=root->left->key;
  }
  if(root->right){
    root->key+=root->right->key;
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}