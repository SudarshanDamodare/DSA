#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// count the no. of subsets with given sum 
int subsetWithSum(int arr[], int n, int sum){
  int dp[n+1][sum+1];

  for(int i=0;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
      if(i==0)
        dp[i][j]=0;
      if(j==0)
        dp[i][j]=1;
    }
  }

  for(int i=1;i<n+1;i++){
    for(int j=1;j<sum+1;j++){
      if(arr[i-1]>j)
        dp[i][j]=dp[i-1][j];
      else
        dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
    }
  }

  return dp[n][sum];
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int arr[] = {3,1,2,3};
  cout<<subsetWithSum(arr, 4, 6);
  return 0;
}