#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int>&low, int &timer, vector<int> adj[]){
  vis[node]=1;
  tin[node]=low[node]=timer++;

  for(auto it: adj[node]){
    if(it==parent)  continue;

    if(!vis[it]){
      dfs(it,node,vis,tin,low,timer,adj);
      low[node]=min(low[node], low[it]);

      if(low[it]>tin[node]){
        cout<<node<<"-"<<it<<endl;
      }
    }
    else
      low[node]=min(low[node], tin[it]);  // if node is already visited
  }

}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,m,u,v;
  cin>>n>>m;
  vector<int> adj[n];
  for(int i=0;i<m;i++){
    cin>>u>>v;
    adj[u].pb(v), adj[v].pb(u);
  }


  vector<int> tin(n,-1), low(n,-1), vis(n,0);
  int timer=0;

  for(int i=0;i<n;i++){
    if(vis[i]==0){
      dfs(i,-1,vis,tin,low,timer,adj);
    }
  }

  return 0;
}