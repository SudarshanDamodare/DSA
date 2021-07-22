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



  

class Solution{
  // int res=0;

public:
  int burnTime(Node *root, int leaf, int &dis, int &res){
    if (root == NULL)
      return 0; //base case
    if (root->key == leaf){
      dis = 0;
      return 1;
    } //base case

    int leftdis = -1;
    int rightdis = -1; //keep track of nodes which are not ancestor of the leaf node by assigning value -1
    int lh = burnTime(root->left, leaf, leftdis, res);
    int rh = burnTime(root->right, leaf, rightdis, res);
    if (leftdis != -1){
      dis = leftdis + 1;
      res = max(res, dis + rh); //calculation of farthest distance from the leaf node in the tree
    }
    if (rightdis != -1){
      dis = rightdis + 1;
      res = max(res, dis + lh); //calculation of farthest distance from the leaf node in the tree
    }
    return max(lh, rh) + 1; //function returns height
  }

  int burnTree(Node *root, int leaf){
    int dist=-1, res=0;
    burnTime(root, leaf, dist, res);
    return res;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->left->left=new Node(40);
  root->left->right=new Node(50);
  root->left->left->left=new Node(60);
  root->left->left->left->left=new Node(70);
  root->left->left->left->left->left=new Node(80);

  Solution ob;
  
  cout<<ob.burnTree(root, 50)<<endl;

  return 0;
}