#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// check if there is any subset from given array which sums up to get the given sum
int subsetSum(int arr[], int n, int sum){
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

  return dp[n][sum];
}


int equalSumPartition(int arr[], int n){
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=arr[i];
  
  if(sum&1) // odd sum
    return false;
  
  return subsetSum(arr, n, sum/2);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n=3;
  int arr[]={2,3,8};
  cout<<equalSumPartition(arr, n);
  return 0;
}