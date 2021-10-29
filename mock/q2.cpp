/*
  CF make them equal question
*/
#define pb push_back
#define ll long long int

#include <bits/stdc++.h>
using namespace std;


// this won't pass all the TCs
void sol(vector<ll> &v, ll n){
  long long sum = 0;
  for (ll i = 1; i <= n; i++)
    sum += (long long)v[i];

  if (sum % n != 0)
  {
    cout << "-1\n";
    return;
  }

  vector<array<ll, 3>> ans;
  ll tar = sum / n;

  for (ll i = 2; i <= n; i++)
  {
    if (v[i] > tar)
    {
      ll d = v[i] - tar;
      v[i] -= (d / i) * i;
      v[1] += (d / i) * i;
      ans.pb({i, 1, (d / i)});
    }
  }

  for (ll i = 2; i <= n; i++)
  {
    ll d = tar - v[i];
    v[1] -= d;
    v[i] += d;
    ans.pb({1, i, d});
  }
  cout << ans.size() << "\n";
  for (auto it : ans)
    cout << it[0] << " " << it[1] << " " << it[2] << "\n";
}


void solve(vector<ll> &arr, ll n){
  long long sum=0;
  for(ll i=1;i<=n;i++){
    sum+=arr[i];
  }

  if(sum%n){
    cout<<"-1\n";
    return;
  }

  ll target=sum/n;
  vector<vector<ll>> res;

  for(ll i=2;i<=n;i++){
    if(arr[i]%i!=0){
      arr[i]+=(i-arr[i]%i);
      arr[1]-=(i-arr[i]%i);
      res.pb({1,i,i-arr[i]%i});
    }

    arr[i]-=arr[i];
    arr[1]+=arr[i];
    res.pb({i,1,arr[i]/i});
  }

  for(ll i=2;i<=n;i++){
    arr[i]=target;
    arr[1]-=target;
    res.pb({1,i,target});
  }

  cout<<res.size()<<endl;
  for(auto it:res)
    cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;

}


int main()
{

  #ifndef ONLINE_JUDGE
    freopen("../gfg/input.txt","r",stdin);
    freopen("../gfg/output.txt","w",stdout);
  #endif

  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for (ll i = 1; i <= n; i++)
      cin >> v[i];

    // sol(v,n);
    solve(v,n);
  }

  return 0;
}


/*
  3
  4
  2 16 4 18
  6
  1 2 3 4 5 6
  5
  11 19 1 1 3

*/