#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// return min. no. of steps to convert s1 to s2 using insertion / deletion / replace operations
int editDist(string s1, string s2){
  int n=s1.size(), m=s2.size();
  int dp[n+1][m+1];

  for(int i=0;i<=n;i++)
    dp[i][0]=i;
  for(int j=1;j<=m;j++)
    dp[0][j]=j;

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(s1[i]==s2[j])
      dp[i][j]=dp[i-1][j-1];
    else
      dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
  }

  return dp[n][m];
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s1="sunday", s2="saturday";
  cout<<editDist(s1,s2)<<endl;
  return 0;
}