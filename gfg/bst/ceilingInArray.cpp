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

void printCeiling(vector<int> a){
  int n=a.size();
  cout<<-1<<" ";
  set<int> s;
  s.insert(a[0]);
  for(int i=1;i<n;i++){
    auto it = s.lower_bound(a[i]);
    if(it!=s.end()){
      cout<<*it<<" ";
    }
    else{
      cout<<-1<<" ";
    }
    s.insert(a[i]);
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={2,8,30,15,25,12};
  printCeiling(a);
  return 0;
}