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

// find if pair with given sum is present in a Binary tree or not
// O(n) time & O(n) space
bool check(Node *root, int sum, us<int> &h){
  if(!root)
    return false;
  if(check(root->left, sum, h)){
    return true;
  }
  if (h.find(sum - root->data) != h.end()){
    return true;
  }
  else{
    h.insert(root->data);
  }
  return check(root->right, sum, h);
}
bool isPairSum(Node *root, int sum){
  us<int> h;
  return check(root, sum, h);
} 


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  Node *root=new Node(10);
  root->left=new Node(5);
  root->right=nn(20);
  root->right->left=nn(16);
  root->right->right=nn(40);
  cout<<isPairSum(root, 22);

  return 0;
}