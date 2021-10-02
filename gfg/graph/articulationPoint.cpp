#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], int &timer, set<int> &points){
  vis[node]=1;
  tin[node]=low[node]=timer++;
  int child=0;

  for(auto it: adj[node]){
    if(it==parent) continue;

    if(!vis[it]){
      dfs(it,node,vis,tin,low,adj,timer,points);

      low[node]=min(low[node], low[it]);
      if(low[it]>=tin[node] && parent!=-1){
        points.insert(node);  // we can get repeated articulation points so use hash array
        // cout<<node<<"-"<<it<<endl;  
      }
      child++;  // to count individual childs
    }
    else
      low[node]=min(low[node],tin[it]);
  }

  if(parent==-1 && child>1){
    points.insert(node);
  }
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,m,a,b;
  cin>>n>>m;
  vector<int> adj[n];

  for(int i=0;i<m;i++)  cin>>a>>b, adj[a].pb(b), adj[b].pb(a);

  vector<int> tin(n,-1), low(n,-1), vis(n,0);
  int timer=0;

  set<int> points;

  for(int i=0;i<n;i++){
    if(!vis[i])
      dfs(i,-1,vis,tin,low,adj,timer,points);
  }

  return 0;
}