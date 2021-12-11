#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

void subsetSum(int arr[], int n, ll sum){
  bool dp[n+1][sum+1];

  // initialise
  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0)
        dp[i][j]=false;
      if(j==0)
        dp[i][j]=true;
    }
  }

  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1]<=j)
        dp[i][j] = (dp[i-1][j-arr[i-1]] or dp[i-1][j]);
      else
        dp[i][j]=dp[i-1][j];
    }
  }

  for(int j=1;j<=sum;j++) if(dp[n][j]==true)  cout<<j<<" ";
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n;
  cin>>n;

  int a[n];
  ll sum=0;
  for(int i=0;i<n;i++)  cin>>a[i],sum+=a[i];

  subsetSum(a, n, sum);

  return 0;
}