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

bool childSum(Node *root){
  if(!root)
    return true;
  if(!root->left && !root->right)
    return true;
  
  int sum=0;
  if(root->left)
    sum+=root->left->key;
  if(root->right)
    sum+=root->right->key;
  
  return (root->key==sum && childSum(root->left) && childSum(root->right));
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(20);
  root->left=new Node(8);
  root->right=new Node(12);
  root->left->left=new Node(3);
  root->left->right=new Node(5);
  cout<<childSum(root)<<endl;
  return 0;
}