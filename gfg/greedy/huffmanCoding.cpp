#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct Node{
  int freq;
  char ch;
  Node *left, *right;
  Node(int f, char c, Node *l=NULL, Node *r=NULL){
    freq=f;
    ch=c;
    left=l;
    right=r;
  }
};

struct compare{
  bool operator() (Node *l, Node* r){
    // return l->freq<r->freq; // this will have max freq element at top
    // reason being pq are implemented using vectors and extract operation takes place at the end of vector
    // so to get minHeap sort the vector in descending order
    return l->freq>r->freq;
  }
};

void inorder(Node *root){
  if(!root) return;
  inorder(root->left);
  cout<<root->freq<<" ";
  inorder(root->right);
}

Node *buildTree(vector<char> c, vector<int> freq){
  priority_queue<Node*, vector<Node*>, compare> pq;
  for(int i=0;i<c.size();i++){
    pq.push(new Node(freq[i], c[i]));
  }
  // cout<<pq.top()->freq<<endl;

  while(pq.size()>1){
    // cout<<pq.top()->freq<<endl;
    Node *l=pq.top();
    pq.pop();

    Node *r=pq.top();
    pq.pop();

    Node *node=new Node(l->freq+r->freq, '$', l, r);

    pq.push(node);
  }

  return pq.top();
}

void printCodes(Node *root, string str){
  if(!root){
    return;
  }
  if(root->ch!='$'){
    cout<<root->ch<<" "<<str<<endl;
  }
  printCodes(root->left, str+"0");
  printCodes(root->right, str+"1");
}


void huffmanCode(vector<char> c, vector<int> freq){
  Node *root=buildTree(c, freq);

  printCodes(root, "");
}






int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<char> c={'a','d','e','f'};
  vector<int> f={30,40,80,60};
  huffmanCode(c, f);
  return 0;
}