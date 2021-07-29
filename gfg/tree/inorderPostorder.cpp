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

// Build binary tree from inorder and postOrder
int postIndex;
void setIndex(int n)
{
  postIndex = n - 1;
}
Node *build(int in[], int post[], int is, int ie)
{
  if (is > ie)
  {
    return NULL;
  }
  Node *root = new Node(post[postIndex--]);
  int inIndex;
  for (int i = is; i <= ie; i++)
  {
    if (in[i] == root->data)
    {
      inIndex = i;
      break;
    }
  }
  root->right = build(in, post, inIndex + 1, ie);
  root->left = build(in, post, is, inIndex - 1);

  return root;
}
Node *buildTree(int in[], int post[], int n)
{
  postIndex = 0;
  setIndex(n);

  return build(in, post, 0, n - 1);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}