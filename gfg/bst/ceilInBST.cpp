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

Node *ceilBST(Node *root, int x){
  Node *res=NULL;
  while(root){
    if(x==root->data)
      return root;
    else if(x>root->data)
      root=root->right;
    else{
      res=root;
      root=root->left;
    }
  }
  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(5);
  root->right=new Node(15);
  root->right->left=new Node(12);
  root->right->right=new Node(30);
  cout<<ceilBST(root, 30)->data;
  return 0;
}