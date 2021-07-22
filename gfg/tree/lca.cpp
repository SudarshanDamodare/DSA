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



// Navie approach
// O(n) time 3 traversals && O(height) space

bool getPath(Node *root, int n, vector<int> &path){
  if(!root)
    return false;
  
  path.push_back(root->key);
  if(root->key==n)
    return true;
  
  if(getPath(root->left, n, path) || getPath(root->right, n, path))
    return true;
  
  path.pop_back();
  return false;
}

int LCA(Node *root, int n1, int n2){
  if(!root)
    return -1;

  vector<int> path1, path2;

  if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
    return -1;

  // for(auto x:path1)
  //   cout<<x<<" ";
  // cout<<endl;
  // for(auto x:path2)
  //   cout<<x<<" ";
  // cout<<endl;
  for(int i=0; i<path1.size()-1; i++){
    if(path1[i+1]!=path2[i+1]){
      // cout<<i<<" "<<path1[i]<<" ";
      return path1[i];
    }
  }

  return -1;
}




// Efficinet approach
// O(n) time 1 Traversal && O(height) space

Node* lca(Node* root, int n1, int n2){
  if(root==NULL)
    return NULL;
  
  if(root->key==n1 || root->key==n2){
    return root;
  }

  Node *lca1=lca(root->left,n1,n2);
  Node *lca2=lca(root->right,n1,n2);

  if(lca1!=NULL && lca2!=NULL){
    return root;
  }

  if(lca1!=NULL)
    return lca1;
  else  
    return lca2;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->right->left=new Node(5);
  root->right->right=new Node(6);
  root->right->left->left=new Node(7);

  cout<<LCA(root, 7, 6)<<endl;
  Node *res=lca(root, 7, 6);
  cout<<res->key<<endl;
  return 0;
}