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

// get the maximum width of a Binary tree

int maxWidth(Node *root){
  if(!root)
    return 0;
  queue<Node*> q;
  q.push(root);
  int res=0;

  while(!q.empty()){
    int count=q.size();
    res=max(res,count);
    // cout<<count<<" "<<res<<endl;

    for(int i=0;i<count;i++){
      Node *curr=q.front();
      q.pop();

      // cout<<curr->key<<" ";
      if(curr->left)
        q.push(curr->left);
      if(curr->right)
        q.push(curr->right);
    }
  }
  
  // cout<<res;
  return res;
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->left->left=new Node(40);
  root->left->left->left=new Node(80);
  root->right=new Node(30);
  root->right->left=new Node(50);
  root->right->right=new Node(60);

  cout<<maxWidth(root)<<endl;
  return 0;
}