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

class Diameter{
  int res=0;

public:

  int height(Node *root){
    if(!root)
      return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    res=max(res, 1+lh+rh);
    return 1+max(lh,rh);
  }

  int diameter(Node *root){
    height(root);
    return res;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  root->left->left->left=new Node(8);
  root->left->left->right=new Node(9);
  root->right->left->left=new Node(10);
  
  Diameter ob;
  cout<<ob.diameter(root);
  return 0;
}