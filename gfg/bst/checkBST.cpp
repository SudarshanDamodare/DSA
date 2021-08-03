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

// Method 1 passing range for node O(n) time & O(h) space
bool check(Node *root, int low, int high){
  if(!root){
    return true;
  }
  if(root->data<=low || root->data>=high){
    // cout<<root->data<<endl;
    return false;
  }
  return check(root->left, low, root->data) && check(root->right, root->data, high);
}

bool checkBST(Node *root){
  if(!root){
    return true;
  }
  return check(root, INT_MIN, INT_MAX);
}


// Method 2 Inorder Traversal O(n) time & O(h) sapce
int previous=INT_MIN;
bool isBST(Node *root){
  if(!root){
    return true;
  }
  if(!isBST(root->left))
    return false;
  
  if(root->data<=previous)
    return false;

  previous=root->data;
  return isBST(root->right);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(20);
  root->left=new Node(8);
  root->right=new Node(30);
  root->right->left=new Node(18);
  root->right->right=new Node(35);
  cout<<checkBST(root)<<endl;
  cout<<isBST(root)<<endl;
  return 0;
}