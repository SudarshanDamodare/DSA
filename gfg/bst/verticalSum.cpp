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

// print the vertical sum of a binary tree
// O(n*log(hd)) time & O(h+w) sapce
void getSum(Node *root, int hd, map<int, int> &m){
  if(!root)
    return;
  getSum(root->left, hd-1, m);
  m[hd]+=root->data; // This statement takes log(hd) time hd being size of map
  getSum(root->right, hd+1, m);
}
void vSum(Node *root){
  if(!root)
    return;
  map<int, int> m;
  getSum(root, 0, m);
  for(auto x:m){
    cout<<x.second<<" ";
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=nn(10);
  root->left=nn(20);
  root->right=nn(50);
  root->left->left=nn(30);
  root->left->right=nn(40);
  vSum(root);
  return 0;
}