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

Node *getSuccessor(Node *curr){
  curr = curr->right;
  while (curr && curr->left)
    curr = curr->left;

    return curr;
}
Node *deleteNode(Node *root,  int X){
  if(!root)
    return root;

  if (X < root->data)
    root->left = deleteNode(root->left, X);

  else if (X > root->data)
    root->right = deleteNode(root->right, X);

  else
  {
    if (!root->left)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if (!root->right)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      Node *s = getSuccessor(root);
      root->data = s->data;
      root->right = deleteNode(root->right, s->data);
    }
  }
  return root;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}