#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// O(V+E) time
bool bfsBipartite(vector<int> adj[], int s, vector<int> &color){
  queue<int> q;
  q.push(s);
  color[s]=1;

  while(!q.empty()){
    int curr=q.front();
    q.pop();

    for(auto v: adj[curr]){
      if(color[v]==0){
        color[v]=-color[curr];
        q.push(v);
      }
      else if(color[v]==color[curr]){
        return false;
      }
    }
  }

  return true;
}

bool isBipartite(int V, vector<int> adj[]){
  vector<int> color(V, 0);

  for(int i=0;i<V;i++){
    // bfs call
    if(color[i]==0){
      if(!bfsBipartite(adj, i, color))
        return false;
    }
  }

  return true;
}


// dfs Bipartite
// O(V+E) time
bool dfsBipartite(vector<int> adj[], int s, int color[]){
  if(color[s]== -1) color[s]=1;

  for(auto v: adj[s]){
    if(color[v]== -1){
      color[v]= 1-color[s];
      if(!dfsBipartite(adj, v, color)){
        return false;
      }
    }
    else if(color[v]==color[s])
      return false;
  }

  return true;
}

bool isBipartite2(int V, vector<int> adj[]){
  int color[V];
  memset(color, -1, sizeof color);

  for(int i=0;i<V;i++){
    if(color[i]== -1){
      if(!dfsBipartite(adj, i, color))
        return 0;
    }
  }

  return 1;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int t;cin>>t;

  while(t--){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];

    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    if(isBipartite(n, adj))
      cout<<"Yes\n";
    else
      cout<<"No\n";
  }
  return 0;
}

/*
2
7 7
0 1
1 2
2 3 -----> no
3 4
4 7
4 5
5 1

8 8
0 1
1 2
2 3
3 4 ----------> yes
4 7
4 5
5 6
6 1
*/