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


// array size 2n+1
void serialize(Node *root, vector<int> &v){
  if(!root){
    v.push_back(-1);
    return;
  }

  v.push_back(root->key);
  serialize(root->left, v);
  serialize(root->right, v);
}


Node* deserialize(vector<int> &v, int &index){
  if(index==v.size())
    return NULL;
  
  int val=v[index++];
  if(val==-1)
    return NULL;
  
  Node *root=new Node(val);
  root->left=deserialize(v, index);
  root->right=deserialize(v, index);
  return root;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->left->left=new Node(30);
  root->left->left->right=new Node(40);
  root->left->left->left=new Node(50);

  vector<int> res;
  serialize(root, res);
  for(auto x:res)
    cout<<x<<" ";
  cout<<endl;

  int index=0;
  Node *curr=deserialize(res, index);
  // cout<<curr->key<<" "<<curr->left->key<<" "<<curr->left->left->key<<" "<<curr->left->left->right->key<<" "<<curr->left->left->left->key<<endl;
  return 0;
}