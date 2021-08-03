#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map
#define nn(x) new Node(x)

struct Node{
  int data;
  Node *left, *right;

  Node(int k){
    data=k;
    left=right=NULL;
  }
};

// Print top view of a binary tree
// O(n*log(w)) time & O(w+h) space
void topView(Node *root){
  if(!root)
    return;
  map<int, int> m;

  // using level order traversal
  queue<pair<Node*, int>> q;
  q.push({root, 0});

  while(!q.empty()){
    auto p=q.front();
    q.pop();

    Node *curr=p.first;
    int hd=p.second;
    
    if(m.find(hd)==m.end())
      m[hd]=curr->data;

    if(curr->left){
      q.push({curr->left, hd-1});
    }
    if(curr->right){
      q.push({curr->right, hd+1});
    }
  }

  // printing the content of map
  for(auto x:m){
    cout<<x.second<<" ";
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=nn(10);
  root->left=nn(20);
  root->left->left=nn(30);
  root->left->right=nn(40);
  root->right=nn(50);
  root->right->left=nn(60);
  root->right->right=nn(70);

  topView(root);
  return 0;
}