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


// This method takes unnecessary space
Node *createTree1(vector<int> parent)
{
  int N=parent.size();
  vector<Node *> v;
  for (int i = 0; i < N; i++)
  {
    Node *temp = new Node(i);
    v.push_back(temp);
  }
  for (auto x : v)
  {
    cout << x->key << " ";
  }
  cout << endl;

  int root;
  for (int i = 0; i < N; i++)
  {
    if (parent[i] == -1)
    {
      root = i;
    }
    if (parent[i] != -1 && v[parent[i]]->left == NULL)
    {
      cout << v[i]->key;
      v[parent[i]]->left = v[i];
    }
    else if (parent[i] != -1 && v[parent[i]]->right == NULL)
    {
      v[parent[i]]->right = v[i];
    }
  }
  return v[root];
}


// Using hashmap
Node *createTree(vector<int> parent){
  int n=parent.size();
  um<int, Node*> m;

  for(int i=0;i<n;i++){
    Node *temp=new Node(i);
    m.insert({i, temp});
  }

  int root;
  for(int i=0;i<n;i++){
    if(parent[i]==-1){
      root=i;
    }
    if(parent[i]!=-1 && m[parent[i]]->left==NULL){
      m[parent[i]]->left=m[i];
    }
    else if(parent[i]!=-1 && m[parent[i]]->right==NULL){
      m[parent[i]]->right=m[i];
    }
  }
  return m[root];
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> arr={-1,0,0};
  Node *root=createTree(arr);
  cout<<root->key<<" "<<root->left->key<<" "<<root->right->key;
  return 0;
}