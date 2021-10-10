#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// find the strogly connected components (SCC) in the graph

void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it])  dfs(it,adj,st,vis);
  }
  st.push(node);
}

void revDfs(int node, vector<int> transpose[], vector<int> &vis){
  cout<<node<<" ";
  vis[node]=1;
  for (auto it : transpose[node]){
    if(!vis[it]){
      revDfs(it,transpose,vis); 
    }
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
  for(int i=0;i<m;i++)  cin>>a>>b, adj[a].pb(b);

  vector<int> vis(n,0);
  // topo sort
  stack<int> st;
  for(int i=0;i<n;i++){
    if(!vis[i]) dfs(i,adj,st,vis);
  }

  vector<int> transpose[n];
  for(int i=0;i<n;i++){
    vis[i]=0; // resetting visited array for further use
    for(auto it: adj[i])  transpose[it].pb(i);  // this reverses the edges
  }


  while(!st.empty()){
    int node=st.top(); st.pop();

    if(!vis[node]){
      cout<<"SCC: ";
      revDfs(node,transpose,vis);
      cout<<endl;
    }
  }

  return 0;
}