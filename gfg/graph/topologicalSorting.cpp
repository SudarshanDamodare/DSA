#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


void getIndegree(vector<int> adj[], int V, int indegree[]){
  for(int i=0;i<V;i++){
    for(auto u: adj[i]){
      indegree[u]++;
    }
  }
}


// Kahn's Algo i.e using bfs
void topologicalSorting(vector<int> adj[], int V){
  int indegree[V]={0};
  getIndegree(adj, V, indegree);
  // for(auto x:indegree){
  //   cout<<x<<" ";
  // }
  // cout<<endl;

  queue<int> q;

  // add all 0 indegree vertices to queue
  for(int i=0;i<V;i++){
    if(indegree[i]==0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int u=q.front();
    q.pop();

    cout<<u<<" ";

    for(auto v: adj[u]){
      indegree[v]--;
      if(indegree[v]==0){
        q.push(v);
      }
    }
  }
  cout<<endl;
}


// topological sorting using dfs
void dfs(vector<int> adj[], int s, vector<bool> &visited, stack<int> &st){
  visited[s]=true;

  for(int v: adj[s]){
    if(!visited[v]){
      dfs(adj, v, visited, st);
    }
  }

  st.push(s);
}

void topologicalSortDFS(vector<int> adj[], int V){
  vector<bool> visited(V, false);
  stack<int> st;

  for(int i=0;i<V;i++){
    if(!visited[i]){
      dfs(adj, i, visited, st);
    }
  }

  // this is for printing the topo sort
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int V=5;
  vector<int> adj[V];
  adj[0].push_back(2);
  adj[0].push_back(3);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(3);

  int indegree[V]={0};

  topologicalSorting(adj, V);
  cout<<endl;
  topologicalSortDFS(adj, V);

  return 0;
}