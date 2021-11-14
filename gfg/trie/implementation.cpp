#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map


struct TrieNode{
  TrieNode *child[26];
  bool isEnd;
  TrieNode(){
    isEnd=false;
    for(int i=0;i<26;i++) child[i]=NULL;
  }
};

// search string in trie
bool search(string s, TrieNode *root){
  TrieNode *curr=root;

  for(auto ch: s){
    int idx=ch-'a';
    if(curr->child[idx]==NULL)  return false;
    curr=curr->child[idx];
  }

  return curr->isEnd;
}

// insert in Trie
void insert(string s, TrieNode *root){
  TrieNode *curr=root;

  for(auto ch: s){
    int idx=ch-'a';
    if(curr->child[idx]==NULL)  curr->child[idx]=new TrieNode();
    curr=curr->child[idx];
  }

  curr->isEnd=true; // to mark the end of the string
}


// delete word from trie
bool isEmpty(TrieNode *root){
  // this function return true if the child array is empty
  for(int i=0;i<26;i++){
    if(root->child[i])  return false;
  }
  return true;
}

TrieNode* delKey(TrieNode *root, string s, int i){
  if(root==NULL)  return NULL;

  if(i==s.size()){
    root->isEnd=false;
    if(isEmpty(root)){
      delete root;
      return NULL;
    }
    return root;
  }

  int idx=s[i]-'a';
  root->child[idx]=delKey(root->child[idx], s, i+1);

  if(isEmpty(root) && root->isEnd==false){
    delete root;
    return NULL;
  }
  return root;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  TrieNode *root= new TrieNode();

  insert("sudarshan", root);
  insert("darshan", root);
  insert("sudu", root);
  cout<<search("sudarshan", root)<<endl;
  delKey(root, "sudarshan", 0);
  cout<<search("sudarshan", root)<<endl;
  cout<<search("sudu", root)<<endl;
  cout<<search("darshan", root)<<endl;

  return 0;
}