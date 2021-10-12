#include <bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST_IO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map
ll mod=1e9+7;

// ll dp[1000000000001];

// void solve(){
//   dp[1]=1;
//   dp[2]=2;

//   for(int i=3;i<1000;i++)  dp[i]=(dp[i-1]+dp[i-2])%mod;
// }

int main(){
  FAST_IO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int t;cin>>t;
  // solve();
  while(t--){
    ll n; cin>>n;
    ll dp[n+1];
    dp[1]=1, dp[2]=2;
    cout<<n<<" ";
    for(int i=3;i<=n;i++)  dp[i]=((dp[i-1]%mod)+(dp[i-2]%mod))%mod;
    cout<<dp[n]<<endl;
  }

  return 0;
}