#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

vector<int> adj[1000];

// naive LCA 
vector<int> par(1000),level(1000);

void bfs(int root){
  par[root]=-1;
  level[root]=0;

  int vis[1000]={0};

  queue<pair<int,int>> q;
  q.push({root, level[root]});
  vis[root]=1;

  while(!q.empty()){
    int node=q.front().first, currLevel=q.front().second;
    q.pop();

    for(auto it: adj[node]){
      if(!vis[it]){
        vis[it]=1;
        par[it]=node;
        level[it]=currLevel+1;
        q.push({it, level[it]});
      }
    }
  }
}


int naiveLCA(int a, int b){
  if(level[a]>level[b]) swap(a,b);

  int d=level[b]-level[a];
  while(d>0){
    b=par[b];
    d--;
  }

  if(a==b)  return a;
  while(par[a]!=par[b]){
    a=par[a], b=par[b];
  }

  return par[a];
}


// binary lifting
vector<vector<int>> LCA;
int m;

void dfs(int node, int par, int l){
  level[node]=l;
  LCA[node][0]=par;
  for(auto it: adj[node]){
    if(it!=par){
      dfs(it,node,l+1);
    }
  }
}

void init(int root, int n){
  dfs(root,-1, 0);

  for(int j=1;j<=m;j++){
    for(int i=1;i<=n;i++){
      if(LCA[i][j-1]!=-1){
        LCA[i][j]=LCA[LCA[i][j-1]][j-1];
      }
    }
  }
}

int getLCA(int a, int b){
  if(level[a]>level[b]) swap(a,b);

  int d=level[b]-level[a];
  while(d>0){
    int i=log2(d);
    b=LCA[b][i];
    d-=(1<<i);
  }

  if(a==b)  return a;
  // while(LCA[a][0]!=LCA[b][0]){
  //   a=LCA[a][0], b=LCA[b][0];
  // }

  for(int i=m;i>=0;i--){
    if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i]))
      a=LCA[a][i], b=LCA[b][i];
  }

  return LCA[a][0];
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  // n -> no. of nodes
  int n; cin>>n;
  int root; cin>>root;
  int a,b;
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  /*
  bfs(root);

  // for(int i=1;i<=n;i++){
  //   cout<<par[i]<<" ";
  // }
  // cout<<endl;
  // for(int i=1;i<=n;i++) cout<<level[i]<<" ";
  cout<<naiveLCA(6,5);
  */

  // for optimal approach
  m=log2(n);  // globally declared
  LCA.resize(n+1, vector<int> (m+1,-1));

  init(root,n);
  cout<<getLCA(4,6);


  return 0;
}