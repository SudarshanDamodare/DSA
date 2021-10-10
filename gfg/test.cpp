#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

int n,m;
vector<int> adj[1001];
int color[1001];
set<int> h;

int solve(int s){
  queue<int> q;
  q.push(s);
  color[s]=1;

  int cnt=0;

  while(!q.empty()){
    int node=q.front();
    q.pop();

    if(h.count(node)==0){
      for(auto child: adj[node]){
        if(h.count(child)==0 && color[child]==-1){
          color[child]=1-color[node];
          q.push(child);
        }
        else if(h.count(child)==0 && color[child]==color[node]){
          cnt++; h.insert(child);
        }
      }
    }
  }
  // cout<<*(h.begin());
  return n-cnt;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cin>>n>>m;
  int a,b;
  for(int i=1;i<=m;i++){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  // for(int i=1;i<=4;i++){
  //   for(auto x: adj[i]) cout<<x<<" ";
  //   cout<<endl;
  // }
  memset(color, -1, sizeof(color));
  cout<<solve(1)<<endl;
  return 0;
}