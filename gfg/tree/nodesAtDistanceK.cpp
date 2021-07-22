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

void printAtK(Node *root, int k){
  if(!root)
    return;
  if(k==0)
    cout<<root->key<<" ";
  else{
    printAtK(root->left, k-1);
    printAtK(root->right, k-1);
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->right->right=new Node(50);
  printAtK(root, 1);
  return 0;
}