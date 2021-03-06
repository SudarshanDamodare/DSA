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


// recursive traversals
void inorderTraversal(Node *root){
  // left root right
  if(root){
    inorderTraversal(root->left);
    cout<<root->key<<" ";
    inorderTraversal(root->right);
  }
}

void preorderTraversal(Node *root){
  // root left right
  if(root){
    cout<<root->key<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void postorderTraversal(Node *root){
  // left right root
  if(root){
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->key<<" ";
  }
}


// iterative traversals
void iterativeInorder(Node *root){
  stack<Node*> st;
  Node *curr=root;

  while(curr || !st.empty()){
    while(curr){
      st.push(curr);
      curr=curr->left;
    }
    curr=st.top();
    st.pop();
    cout<<curr->key<<" ";
    curr=curr->right;
  }
}


void iterativePreorder(Node *root){
  stack<Node*> st;
  Node *curr=root;

  while(curr || !st.empty()){
    while(curr){
      cout << curr->key << " ";
      st.push(curr);
      curr=curr->left;
    }
    curr=st.top();
    st.pop();
    curr=curr->right;
  }
}

void iterativePreorder2(Node *root){
  if(!root)
    return;
  
  stack<Node*> st;
  Node *curr=root;

  while(curr || !st.empty()){
    while(curr){
      cout<<curr->key<<" ";
      if(curr->right)
        st.push(curr->right);
      curr=curr->left;
    }
    if(!st.empty()){
      curr=st.top();
      st.pop();
    }
  }
}


// height of binary tree
int height(Node *root){
  if(!root)
    return 0;
  return (max(height(root->left), height(root->right))+1);
}


// size of binary tree
int getSize(Node *root){
  if(root==NULL)
    return 0;
  return (1 + getSize(root->left) + getSize(root->right));
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(20);
  root->right=new Node(30);
  root->right->left=new Node(40);
  root->right->right=new Node(50);

  inorderTraversal(root);
  cout<<endl;
  iterativeInorder(root);
  cout<<endl;
  preorderTraversal(root);
  cout<<endl;
  iterativePreorder(root);
  cout<<endl;
  postorderTraversal(root);
  cout<<endl;
  cout<<height(root);
  cout<<" ";
  cout<<getSize(root);
  return 0;
}