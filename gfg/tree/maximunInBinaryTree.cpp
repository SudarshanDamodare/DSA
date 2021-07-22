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


// maximum element in binary tree
int getMax(Node *root){
  if(root==NULL)
    return INT_MIN;
  return (max(root->key, max(getMax(root->left), getMax(root->right))));
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(300);
  root->left->left=new Node(40);
  root->right->right=new Node(50);
  cout<<getMax(root);
  return 0;
}