#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


// print shortest path from source to all the vertices
void printShortest(vector<int> adj[], int s, int v){
  vector<int> dist(v, INT_MAX);
  vector<bool> visited(v, false);

  dist[s]=0;
  queue<int> q;
  q.push(s);
  visited[s]=true;

  while(!q.empty()){
    int curr=q.front();
    q.pop();
    for(int u:adj[curr]){
      if(visited[u]==false){
        dist[u]=dist[curr]+1;
        visited[u]=true;
        q.push(u);
      }
    }
  }

  for(int x:dist){
    if(x!=INT_MAX){
      cout<<x<<" ";
    }
  }
  cout<<endl;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}