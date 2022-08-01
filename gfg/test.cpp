#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map
#define all(x) x.begin(),x.end()

int n,k;
vector<vector<int>>  dp;

int solve(int idx, int prev, vector<vector<int>> &data){
  int maxi=INT_MIN;
  if(dp[idx][prev]!=-1) return dp[idx][prev];
  if(idx==0){
    for(int i=0;i<k;i++){
      if(i!=prev){
        maxi=max(maxi,data[idx][i]);
      }
    }
    return dp[idx][prev] = maxi;
  }


  for(int i=0;i<k;i++){
    if(i!=prev){
      int points = data[idx][i] + solve(idx-1, i, data);
      maxi=max(maxi,points);
    }
  }
  return dp[idx][prev] = maxi;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cin>>n>>k;
  dp.resize(n,vector<int>(k+1,-1));
  vector<vector<int>> data(n,vector<int>(k));

  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      cin>>data[i][j];
    }
  }

  cout<<solve(n-1,k,data)<<endl;

  return 0;
}