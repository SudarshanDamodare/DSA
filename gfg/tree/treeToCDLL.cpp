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


Node *connect(Node *leftList, Node* rightList){
  if(!leftList){
    return rightList;
  }
  if (!rightList){
    return leftList;
  }

  Node *leftLast = leftList->left;
  Node *rightLast = rightList->left;

  leftLast->right = rightList;
  rightList->left = leftLast;

  leftList->left = rightLast;
  rightLast->right = leftList;

  return leftList;
}

Node *bTreeToCList(Node *root)
{
  if (!root)
  {
    return NULL;
  }

  Node *left = bTreeToCList(root->left);
  Node *right = bTreeToCList(root->right);

  root->left = root;
  root->right = root;

  return connect(connect(left, root), right);
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}