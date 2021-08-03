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

// Traverse the binary tree in vertical order
// O(n*log(w)) time & O(n+h) space

void verticalTraversal(Node *root){
  if(!root)
    return;
  map<int, vector<int>> m;

  // using level order traversal
  queue<pair<Node*, int>> q;
  q.push({root, 0});

  while(!q.empty()){
    auto p=q.front();
    q.pop();

    Node *curr=p.first;
    int hd=p.second;
    m[hd].push_back(curr->data);

    if(curr->left){
      q.push({curr->left, hd-1});
    }
    if(curr->right){
      q.push({curr->right, hd+1});
    }
  }

  // printing the content of map
  for(auto x:m){
    for(auto y:x.second)
      cout<<y<<" ";
    cout<<endl;
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=nn(10);
  root->left=nn(20);
  root->right=nn(30);
  root->left->right=nn(15);
  root->right->left=nn(40);
  root->right->right=nn(50);
  verticalTraversal(root);
  return 0;
}