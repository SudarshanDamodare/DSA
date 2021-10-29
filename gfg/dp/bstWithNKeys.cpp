#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// count no. of unique structural BSTs with n distinct keys
int count(int n){
  int dp[n+1]={0};
  dp[0]=1;

  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++)
      dp[i]+=dp[j]*dp[i-j-1];
  }
  return dp[n];
}

// this can be done using catalan Numbers formula i.e res(n) = (1/(n+1)) bino(2n,n) {2nCn}
long double fact(int n){
  long double res=1;
  while(n)  res*=(n--);
  return res;
}

long double bino(int n, int r){
  long double res=1;
  for(int i=0;i<r;i++)  res*=(n--);

  return res/fact(r);
}


//  bino coeff dp
ll nCr(int n, int r){
  int mod=1000000007;
  if (n < r)
    return 0;
  if (n - r < r)
    r = n - r;

  int dp[r + 1];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;

  for (int i = 1; i <= n; i++)
  for (int j = min(i, r); j > 0; j--){
    dp[j] = (dp[j] + dp[j - 1]) % mod;
  }

  return dp[r];
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n;cin>>n;
  cout<<count(n)<<endl;
  cout<<bino(2*n,n)/(n+1);
  return 0;
}