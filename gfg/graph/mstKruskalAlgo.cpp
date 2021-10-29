#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


struct node{
  int u,v,wt;
  node(int first, int second, int weight){
    u=first;
    v=second;
    wt=weight;
  }
};

bool comp(node a, node b){
  return a.wt<b.wt;
}

struct DSU{
  vector<int> parent, rank;

  DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1);
    for(int i=0;i<=n;i++)  parent[i]=i, rank[i]=0;
  }

  int find(int x){
    if(parent[x]==x)  return x;
    parent[x]=find(parent[x]);
    return parent[x];
  }

  void union_(int x, int y){
    int x_rep=find(x), y_rep=find(y);
    if(x_rep==y_rep)  return;

    if(rank[x_rep]<rank[y_rep]) parent[x_rep]=y_rep;
    else if(rank[y_rep]<rank[x_rep])  parent[y_rep]=x_rep;
    else  parent[y_rep]=x_rep, rank[x_rep]++;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n;cin>>n;
  vector<node> edges;
  int a, b, wt;
  for(int i=0;i<n;i++){
    cin>>a>>b>>wt;
    edges.pb(node(a,b,wt));
  }

  sort(edges.begin(), edges.end(), comp);

  struct DSU mstSet(n);
  // for(auto it: mstSet.parent) cout<<it<<" ";
  vector<node> res;

  for(int i=0;i<n;i++){
    int a=edges[i].u, b=edges[i].v, wt=edges[i].wt;
    if(mstSet.find(a)==mstSet.find(b))  continue;

    else{
      mstSet.union_(a,b);
      res.pb(edges[i]);
    }
  }

  int len=0;
  for(auto it: res) {len+=it.wt; cout<<it.u<<"-"<<it.v<<endl;}
  cout<<len<<endl;

  return 0;
}