#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map
#define all(x) x.begin(),x.end()


// this function sorts the adjacents according to the priority and edge weights
bool comp(pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){
  int prioa=a.second, priob=b.second;
  int wta=a.first.second, wtb=b.first.second;

  if(prioa==priob)  return wta<wtb;
  return prioa>priob;
}


int timer;

// dfs function
void dfs(int s, vector<pair<pair<int, int>, int> > adj[], int vis[], int res[]){
  vis[s]=1;
  res[s]=timer;

  for(auto it: adj[s]){
    int u=it.first.first, wt=it.first.second;
    if(!vis[u]){
      timer+=wt;
      dfs(u, adj, vis, res);
      timer+=wt;
    }
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif



  int n, m;
  cin>>n>>m;

  int prio[n+1];
  for(int i=1;i<=n;i++) cin>>prio[i];

  int a,b,wt;
  vector<pair<pair<int, int>, int> > adj[n+1];

  for(int i=0;i<m;i++){
    cin>>a>>b>>wt;
    adj[a].pb(mkp(mkp(b,wt), prio[b]));
    adj[b].pb(mkp(mkp(a,wt), prio[a]));
  }
  
  // sort adj according to priority and wt
  for(int i=0;i<=n;i++) sort(all(adj[i]), comp);

  // solve from here
  int vis[n+1]={0}, res[n+1]={0};
  timer=0;

  dfs(0, adj, vis, res);

  for(int i=1;i<=n;i++) cout<<res[i]<<" ";

  return 0;
}


/*
  TC
  
  6 8
  2 2 4 5 2 6
  0 1 7
  0 2 5
  1 5 6
  1 6 2
  2 6 6
  2 3 5
  3 6 3
  3 4 6
*/