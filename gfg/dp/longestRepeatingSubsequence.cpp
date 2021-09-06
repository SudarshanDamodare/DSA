#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// return length of the longest repeating subsequence
int LRS(string s){
  int n=s.size();

  int dp[n+1][n+1];

  for(int i=0;i<=n;i++){
    dp[i][0]=0;
    dp[0][i]=0;
  }

  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    if(s[i-1]==s[j-1] && i!=j)
      dp[i][j]=dp[i-1][j-1] + 1;
    else
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
  }

  return dp[n][n];
}


// print LRS
string printLRS(string s){
  int n=s.size();

  int dp[n+1][n+1];

  for(int i=0;i<=n;i++){
    dp[i][0]=0;
    dp[0][i]=0;
  }

  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    if(s[i-1]==s[j-1] && i!=j)
      dp[i][j]=dp[i-1][j-1] + 1;
    else
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
  }

  int i=n,j=n;
  string res="";

  while(i>0 && j>0){
    if(dp[i][j]==dp[i-1][j-1]+1){
      res=s[i-1]+res;
      i--,j--;
    }
    else if(i && dp[i][j]==dp[i-1][j])
      i--;
    else
      j--;
  }

  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s = "aabcbdd";
  cout<<LRS(s)<<endl;
  cout<<printLRS(s);

  return 0;
}