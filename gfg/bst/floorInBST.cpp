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

Node *getFloor(Node *root, int x){
  Node *res=NULL;
  while(root){
    if(x==root->data)
      return root;
    else if(x<root->data)
      root=root->left;
    else{
      res=root;
      root=root->right;
    }
  }
  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}