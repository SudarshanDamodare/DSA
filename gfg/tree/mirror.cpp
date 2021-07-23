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

// mirror a binary tree
void mirror(Node *root){
  if(!root){
    return;
  }

  mirror(root->left);
  mirror(root->right);

  Node *temp=root->right;
  root->right=root->left;
  root->left=temp;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}