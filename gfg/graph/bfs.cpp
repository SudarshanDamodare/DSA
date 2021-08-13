#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


void addEdge(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}


// version 1: source is given
void bfs1(vector<int> adj[], int v, int s){
  vector<bool> visited(v+1, false);

  queue<int> q;
  visited[s]=true;
  q.push(s);

  while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    // get the adjacents of curr vertex
    for(int x:adj[curr]){
      if(visited[x]==false){
        visited[x]=true;
        q.push(x);
      }
    }
  }
}


// version 2: source is not given and graph may be disconnected
void bfs(vector<int> adj[], int s, vector<bool> &visited){
  queue<int> q;
  visited[s]==true;
  q.push(s);

  while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";

    for(int x:adj[curr]){
      if(visited[x]==false){
        visited[x]=true;
        q.push(x);
      }
    }
  }
}

int bfsDisconnected(vector<int> adj[], int v){
  int count=0; // this is for getting the number of connected components in graph
  vector<bool> visited(v+1, false);
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      count++;
      bfs(adj, i, visited);
    }
  }

  return count;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> adj[5];
  addEdge(adj, 0,1);
  addEdge(adj, 0,2);
  addEdge(adj, 1,2);
  addEdge(adj, 1,3);
  addEdge(adj, 2,3);
  addEdge(adj, 2,4);
  addEdge(adj, 3,4);

  bfs1(adj, 5, 0); // 0 is source vertex and 5 are the number of vertices
  cout<<endl;
  return 0;
}