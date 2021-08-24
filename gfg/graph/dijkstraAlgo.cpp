#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


void dijkstra(int src, int n, vector<pair<int,int>> adj[]){
  // min heap    pair(dist, node)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> distTo(n+1,INT_MAX);

  distTo[src]=0;
  pq.push(mp(distTo[src],src));

  while(!pq.empty()){
    int dist=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    // traversing adjacents of the curr node
    for(auto it:adj[node]){
      int next=it.first;
      int nextDist=it.second;

      if(distTo[next]>dist+nextDist){
        distTo[next]=dist+nextDist;
        pq.push(mp(distTo[next], next));
      }

    }

  }

  cout<<"Shortest dist from source :\n";
  for(int i=1;i<=n;i++) cout<<distTo[i]<<" ";
  cout<<"\n";
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,m,source;
  cin>>n>>m;

  vector<pair<int,int>> adj[n+1]; // a-indexed adj list
  int u,v,wt;

  for(int i=0;i<m;i++){
    cin>>u>>v>>wt;
    adj[u].pb(mp(v,wt));
    adj[v].pb(mp(u,wt));
  }

  cin>>source;

  dijkstra(source, n, adj);


  return 0;
}