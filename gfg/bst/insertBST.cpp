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

Node* insert(Node* root, int Key)
{
  Node *temp = new Node(Key);
  Node *parent = NULL, *curr = root;

  while (curr)
  {
    parent = curr;

    if (Key < curr->data)
      curr = curr->left;

    else if (Key > curr->data)
      curr = curr->right;

    else
      return root;
  }
  if (!parent)
    return temp;

  if (Key < parent->data)
    parent->left = temp;
  else
    parent->right = temp;

  return root;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}