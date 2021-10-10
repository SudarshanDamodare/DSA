#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// single source shortest path (SSSP) Bellman Ford Algo
// works for -ve edges and help to detect -ve cycle
struct node{
  int u,v,wt;
  node(int x, int y, int z){
    u=x, v=y, wt=z;
  }
};

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n,m,a,b,wt;
  cin>>n>>m;
  vector<node> edges;
  for(int i=0;i<m;i++){
    cin>>a>>b>>wt;
    edges.pb(node(a,b,wt));
  }

  int src; cin>>src;

  int inf=1e7;
  vector<int> dist(n,inf);

  for(int i=0;i<n-1;i++){
    for(auto it: edges){
      if(dist[it.u] + it.wt < dist[it.v])
        dist[it.v] = dist[it.u] + it.wt;
    }
  }

  // this is to check -ve cycle
  int flag=0;
  for(auto it: edges){
    if(dist[it.u] + it.wt < dist[it.v]){
      cout<<"Negative cycle\n";
      flag=1;
      break;
    }
  }

  if(!flag){
    for(int i=0;i<n;i++)  cout<<i<<" "<<dist[i]<<endl;
  }

  return 0;
}