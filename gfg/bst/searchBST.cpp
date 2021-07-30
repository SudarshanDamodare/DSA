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

bool search(Node* root, int x){
  if (!root)
    return 0;

  while (root){
    if (x == root->data)
      return 1;
    else if (x < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return 0;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  
  return 0;
}