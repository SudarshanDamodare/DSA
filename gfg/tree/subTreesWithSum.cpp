#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct Node{
  int data;
  Node *left, *right;

  Node(int k){
    data=k;
    left=right=NULL;
  }
};


// Find the count of subtrees with given sum

// this function uses the sum replacement technique and check if the sum equals the given sum
void count(Node *root, int X, int &res){
  if(!root){
    return;
  }
  count(root->left, X, res);
  count(root->right, X, res);
	
	if(root->left){
    root->data += root->left->data;
  }
	if(root->right){
    root->data += root->right->data;
  }
	if(root->data==X){
    res++;
  }
}
int countSubtreesWithSumX(Node* root, int X){
	if(!root){
    return 0;
  }
	int res=0;
	count(root, X, res);
	return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}