#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST_IO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


void indegree(vector<int> &indeg, int n, vector<int> adj[]){
  for(int i=1;i<=n;i++){
    for(auto it: adj[i])  indeg[it]++;
  }
}


int main(){
  FAST_IO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  // int t;cin>>t;
  int n,m,a,b;
  // while(t--){
    cin>>n>>m;
    // cout<<n<<" "<<m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)  cin>>a>>b, adj[a].push_back(b);

    // for(auto x: adj[1]) cout<<x<<" ";

    vector<int> indeg(n+1, 0);
    indegree(indeg, n, adj);
    vector<int> res;
    // for(auto x:indeg) cout<<x<<" ";

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=n;i++)  if(indeg[i]==0)  pq.push(i);

    while(!pq.empty()){
      int node=pq.top();
      pq.pop();
      res.push_back(node);

      for(auto child: adj[node]){
        indeg[child]--;
        if(indeg[child]==0) pq.push(child);
      }

      // cout<<node<<" "<<endl;
    }
    if(res.size()!=n)  cout<<"Sandro fails."<<endl;
    else{
      for(auto x: res)  cout<<x<<" ";
      cout<<endl;
    }
  // }

  return 0;
}