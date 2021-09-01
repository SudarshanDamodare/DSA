#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


int solve(vector<int> doll){
  // sort(doll.begin(), doll.end(), greater<int>());

  int res=0;
  map<int, int, greater<int> > m;
  for(int i=0;i<doll.size();i++){
    m[doll[i]]++;
  }

  for(auto it: m){
    // cout<<it.first<<" "<<it.second<<endl;
    res=max(res, it.second);
  }

  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int t;cin>>t;
  while(t--){
    ll n;
    cin>>n;
    vector<int> a(n);
    for(ll i=0;i<n;i++)
      cin>>a[i];
    cout<<solve(a)<<endl;
  }

  return 0;
}