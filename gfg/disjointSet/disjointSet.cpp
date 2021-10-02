#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


class DisjointSet{
  vector<int> parent, rank;

  public:
  DisjointSet(int n){
    parent.resize(n), rank.resize(n);
    for(int i=0;i<n;i++)  parent[i]=i, rank[i]=0;
  }

  int Find(int x){
    if(parent[x]==x)  return x;
    return Find(parent[x]);
  }

  // union bt rank
  void Union(int x, int y){
    int x_rep=Find(x), y_rep=Find(y);

    if(x_rep==y_rep)  return;

    if(rank[x_rep]<rank[y_rep]) parent[x_rep]=y_rep;
    else if(rank[y_rep]<rank[x_rep])  parent[y_rep]=x_rep;
    else  parent[y_rep]=x_rep, rank[x_rep]++;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  DisjointSet s = DisjointSet(10);

  cout<<s.Find(5)<<endl;
  s.Union(2,4);
  cout<<s.Find(4)<<endl;
  return 0;
}