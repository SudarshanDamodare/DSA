#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// return length of longest increasing subsequence
int LIS(vector<int> v){
  int n=v.size();

  vector<int> dp(n,1);

  for(int i=1;i<n;i++)
  for(int j=0;j<i;j++){
    if(v[i]>v[j] && dp[i]<=dp[j])
      dp[i]=1+dp[j];
  }

  int res=dp[0], idx=0;
  for(int i=1;i<n;i++){
    res=max(res,dp[i]);
    if(dp[i]>dp[idx])
      idx=i;
  }

  int i=idx-1;
  int curr=idx;
  vector<int> temp;
  
  while(i>=0){
    while(dp[i]+1!=dp[curr]){
      i--;
    }
    temp.pb(v[curr]);
    curr=i;
  }

  reverse(temp.begin(), temp.end());
  for(auto x:temp)
    cout<<x<<" ";
  cout<<endl;

  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={5,8,7,1,9};
  cout<<LIS(v);
  return 0;
}