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


// Kahn's Algo
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

  return 0;
}