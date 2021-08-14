#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// Detect cycle in undirected graph

// method I using dfs
bool dfsRec(vector<int> adj[], int s, vector<bool> &visited, int parent){
  visited[s]=true;
  for(int u: adj[s]){
    if(!visited[u]){
      if(dfsRec(adj, u, visited, s)){
        return true;
      }
    }
    else if(u!=parent){
      return true;
    }
  }
  return false;
}

bool cycleCheckDFS(vector<int> adj[], int V){
  vector<bool> visited(V,false);
  for(int i=0;i<V;i++){
    if(!visited[i]){
      if(dfsRec(adj, i, visited, -1))
        return true;
    }
  }
  return false;
}



// Method II using bfs
bool bfsCycle(vector<int> adj[], int s, vector<bool> &visited){
  // queue<pair<int,int>> q --> node and parent resp
  queue<pair<int,int>> q;
  q.push({s,-1});
  visited[s]=true;

  while(!q.empty()){
    int curr=q.front().first;
    int parent=q.front().second;
    q.pop();

    for(auto it: adj[curr]){
      if(!visited[it]){
        visited[it]=true;
        q.push({it, curr});
      }
      else if(it!=parent){
        return true;
      }
    }
  }
  return false;
}


bool cycleCheckBFS(vector<int> adj[], int V){
  vector<bool> visited(V, false);
  for(int i=0;i<V;i++){
    if(bfsCycle(adj, i, visited))
      return true;
  }
  return false;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}