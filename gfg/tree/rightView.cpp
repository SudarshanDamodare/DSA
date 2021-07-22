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

class View{
  int maxLevel=0;
  vector<int> v;

public:


  // Iterative method level order traversal
  vector<int> rightView1(Node *root)
  {
    
    vector<int> res;
    if (!root)
    {
      return res;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int count = q.size();

      for (int i = 0; i < count; i++)
      {
        Node *curr = q.front();
        q.pop();

        if (i == count - 1)
        {
          res.push_back(curr->key);
        }

        if (curr->left)
        {
          q.push(curr->left);
        }
        if (curr->right)
        {
          q.push(curr->right);
        }
      }
    }
    return res;
  }



  // recursive method root->right->left
  vector<int> right(Node *root, int level)
  {
    if (!root)
    {
      return v;
    }

    if (level > maxLevel)
    {
      v.push_back(root->key);
      maxLevel = level;
    }

    right(root->right, level + 1);
    right(root->left, level + 1);
    return v;
  }
  vector<int> rightView2(Node *root)
  {
    return right(root, 1);
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}