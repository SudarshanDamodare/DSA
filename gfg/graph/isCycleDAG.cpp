#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// Method I: recursive
bool dfsCycle(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &recSt)
{
  recSt[s] = true;
  visited[s] = true;

  for (auto it : adj[s])
  {
    if (!visited[it] && dfsCycle(adj, it, visited, recSt))
    {
      return true;
    }
    else if (recSt[it])
    {
      return true;
    }
  }
  recSt[s] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  //	recursive soln
  vector<bool> visited(V, false);
  vector<bool> recSt(V, false);

  for (int i = 0; i < V; i++)
  {
    if (!visited[i])
    {
      if (dfsCycle(adj, i, visited, recSt))
      {
        return true;
      }
    }
  }
  return false;
}



// Method II Kahn's Algo (topological sort)
void getIndegree(vector<int> adj[], int V, int indegree[]){
  for(int i=0;i<V;i++){
    for(auto it:adj[i]){
      indegree[it]++;
    }
  }
}

bool isCycle(vector<int> adj[], int V){
  int indegree[V]={0};
  getIndegree(adj, V, indegree);

  queue<int> q;
  int count=0;

  for(int i=0;i<V;i++){
    if(indegree[i]==0)
      q.push(i);
  }

  while(!q.empty()){
    int u=q.front();
    q.pop();

    for(auto v: adj[u]){
      indegree[v]--;
      if(indegree[v]==0){
        q.push(v);
      }
    }

    count++;
  }

  return (count!=V);

}






int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}