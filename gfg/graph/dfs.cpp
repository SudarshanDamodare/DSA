#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map



// version 1: source given and graph is connected
void dfsRec(vector<int> adj[], int s, vector<bool> &visited){
  visited[s]=true;
  cout<<s<<" ";
  // get to the adjacents of source i.e s
  for(int u:adj[s]){
    if(visited[u]==false)
      dfsRec(adj, u, visited);
  }
}

void dfs1(vector<int> adj[], int v , int s){
  vector<bool> visited(v,false);

  dfsRec(adj, s, visited);
}

// version 2: having disconnected graph and no source is given
void dfs(vector<int> adj[], int v){
  vector<bool> visited(v, false);

  // this loop ensures that the disconnected part is also visited
  for(int i=0;i<v;i++){
    if(visited[i]==false)
      dfsRec(adj, i, visited);
      // for counting connected components cout++;
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}