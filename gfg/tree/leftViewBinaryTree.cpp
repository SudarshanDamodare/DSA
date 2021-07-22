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

// print left view of a binary tree

// recursive solution
int maxLevel=0;
void printLeft(Node *root, int level){
  if(root==NULL)
    return;
  if(level>maxLevel){
    cout<<root->key<<" ";
    maxLevel=level;
  }

  printLeft(root->left, level+1);
  printLeft(root->right, level+1);
}

void printLeftView(Node *root){
  printLeft(root, 1);
}



// Iterative solution
void printLeftView2(Node *root){
  if(root==NULL)
    return;
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int count=q.size();

    for(int i=0;i<count;i++){
      Node *curr=q.front();
      q.pop();

      if(i==0)
        cout<<curr->key<<" ";

      
      if(curr->left)
        q.push(curr->left);
      if(curr->right)
        q.push(curr->right);
    }
  }
}




int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(300);
  root->left->left=new Node(40);
  root->right->right=new Node(50);
  root->right->right->right=new Node(1000);
  printLeftView(root);
  cout<<endl;
  printLeftView2(root);
  return 0;
}