#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  ll mod=1e9+7;

  ll n; cin>>n;
  ll sum=0;
  vector<ll> v(n);
  for(ll i=0;i<n;i++) {cin>>v[i];sum+=v[i];}

  ll x=sum/n;

  vector<pair<ll,ll>> rem,temp;

  for(int i=0;i<n;i++){
    if(v[i]>x){
      rem.pb({i,v[i]-x});
    }
    if(v[i]<x){
      temp.pb({i,x-v[i]});
    }
  }

  ll res=0;
  if(rem.size()==0) {cout<<0<<endl;}
  else{
    ll j=0,i=(rem[0].first+1)%n;
    
    while(i!=rem[0].first){

      if(v[i]<x){
        if(x-v[i]<=rem[j].second){
          rem[j].second-=x-v[i];
          res=(res+(x-v[i])*((i-rem[j].first+n)%n))%mod;
        }
        else{
          res=(res+(rem[j].second)*((i-rem[j].first+n)%n))%mod;
          rem[j].second=0;
        }

        if(rem[j].second==0)j++;
      }

      i=(i+1)%n;
    }
    cout<<res<<endl;
  }



  return 0;
}