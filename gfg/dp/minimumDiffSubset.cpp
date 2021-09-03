#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// divide array in 2 subsets such that diff of their sum is minimum return min diff
int minimumDiffSubset(vector<int> &v){
  int n=v.size();
  int sum=0;
  for(auto x: v)
    sum+=x;

  int dp[n+1][sum+1];

  for(int i=0;i<n+1;i++)
  for(int j=0;j<sum+1;j++){
    if(j==0)
      dp[i][j]=true;
    else if(i==0)
      dp[i][j]=false;
    else if(v[i-1]>j)
      dp[i][j]=dp[i-1][j];
    else
      dp[i][j]=dp[i-1][j] or dp[i-1][j-v[i-1]];
  }

  int res=INT_MAX;
  for(int i=0;i<=sum/2;i++){
    if(dp[n][i])
      res=min(res, sum-2*i);  // here i is sum of s1 therefore s2-s1=sum-2*s1 considering s1<=s2
  }

  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={1,6,11,5};
  cout<<minimumDiffSubset(v);
  return 0;
}