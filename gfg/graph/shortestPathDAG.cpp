#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

void findTopoSort(int s, int visited[], stack<int> &st, vector<pair<int,int>> adj[]){
  visited[s]=1;
  for(auto u:adj[s]){
    if(!visited[u.first]){
      findTopoSort(u.first, visited, st, adj);
    }
  }
  st.push(s);
}

void shortestPath(int src, int n, vector<pair<int,int>> adj[]){
  int visited[n]={0};
  stack<int> st;

  for(int i=0;i<n;i++){
    if(!visited[n])
      findTopoSort(i, visited, st, adj);
  }

  int dist[n];
  for(int i=0;i<n;i++)
    dist[i]=1e9;
  dist[src]=0;

  while(!st.empty()){
    int node=st.top();
    st.pop();

    if(dist[node]!=1e9){
      for(auto it: adj[node]){
        if(dist[node]+it.second<dist[it.first])
          dist[it.first]=dist[node]+it.second;
      }
    }
  }

  for(int i=0;i<n;i++){
    (dist[i]==1e9) ? cout<<"INF " : cout<<dist[i]<<" ";
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> adj[n];
  for(int i=0;i<m;i++){
    int u,v,wt;
    cin>>u>>v>>wt;
    adj[u].pb({v,wt});
  }

  shortestPath(0, n, adj);
  return 0;
}