#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// brute approach
void prims1(int n, vector<pair<int,int>> adj[]){
  int parent[n];
  int key[n];
  bool mstSet[n];

  for(int i=0;i<n;i++)
    key[i]=INT_MAX, mstSet[i]=false, parent[i]=-1;
  
  key[0]=0; // this is the starting vertex
  parent[0]=-1; // as it won't have parent

  for(int count=0;count<n-1;count++){
    
    // getting minimum key value
    int mini=INT_MAX, u;
    for(int v=0;v<n;v++){
      if(mstSet[v]==false && key[v]<mini)
        mini=key[v], u=v;
    }

    mstSet[u]=true;

    for(auto it:adj[u]){
      int v=it.first;
      int weight=it.second;

      if(mstSet[v]==false && weight<key[v])
        parent[v]=u, key[v]=weight;
    }
  }

  // printing the edges
  for(int i=1;i<n;i++)
    cout<<parent[i]<<" - "<<i<<" \n";
}


// optimal approach using heap
void primsMST(int n, vector<pair<int,int>> adj[]){
  int parent[n];
  int key[n];
  bool mstSet[n];

  for(int i=0;i<n;i++)
    parent[i]=-1, key[i]=INT_MAX, mstSet[i]=false;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (key[i], i)
  parent[0]=-1;
  key[0]=0;
  pq.push({0,0});

  for(int count=0;count<n-1;count++){
    int u=pq.top().second;
    pq.pop();

    mstSet[u]=true;

    for(auto it: adj[u]){
      int v=it.first;
      int weight=it.second;
      if(mstSet[v]==false && weight<key[v]){
        key[v]=weight;
        parent[v]=u;
        pq.push({key[v], v});
      }
    }
  }

  // printing the edges
  for(int i=1;i<n;i++)
    cout<<parent[i]<<" - "<<i<<" \n";

}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> adj[n];
  int a,b,wt;
  for(int i=0;i<m;i++){
    cin>>a>>b>>wt;
    adj[a].pb(mp(b,wt));
    adj[b].pb(mp(a,wt));
  }

  prims1(n, adj);

  return 0;
}