#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// matrix chain multiplication

// recursive approach   --> this can be memoised
int mcm(vector<int> v, int l, int r){
  if(l>=r)  return 0;
  
  int res=INT_MAX;
  for(int k=l;k<=r-1;k++){
    int temp = mcm(v, l, k) + mcm(v, k+1, r) + v[l-1]*v[k]*v[r];

    res=min(res, temp);
  }

  return res;
}


// tabulation dp
int MCM(vector<int> v){
  int n=v.size(); // no of matrices

  int dp[n][n];
  memset(dp, 0, sizeof(dp));

  // initialisation
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++){
    if(i==j)
      dp[i][j]=0;
  }

  for(int cl=2;cl<=n-1;cl++)
  for(int l=1;l<=n-cl;l++){
    int r=l+cl-1;

    int res=INT_MAX;
    // for each partiton
    for(int k=l;k<r;k++){
      int temp = dp[l][k] + dp[k+1][r] + v[l-1]*v[k]*v[r];

      res=min(res, temp);
    }

    dp[l][r]=res;
    
  }

  return dp[1][n-1];
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v = {4,2,3,1,3};
  cout<<mcm(v, 1, 4)<<endl;
  cout<<MCM(v)<<endl;
  
  return 0;
}