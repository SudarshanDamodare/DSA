#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// return max profit you can get with the given knapsack

ll knapsack(ll val[], ll wt[], ll w, ll n){
  ll dp[n+1][w+1];
  
  // initialising
  for(ll i=0;i<n+1;i++)
    for(ll j=0;j<w+1;j++)
      if(i==0 || j==0)
        dp[i][j]=0;
  
  for(ll i=1;i<n+1;i++){
    for(ll j=1;j<w+1;j++){

      if(wt[i-1]<=j){
        dp[i][j] = max(wt[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i-1][j]);
      }
      else  
        dp[i][j]=dp[i-1][j];
    }
  }

  return dp[n][w];
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  
  return 0;
}