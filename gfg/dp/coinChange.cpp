#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

int coinChange(vector<int> &coins, int amount)
{
  int n = coins.size();

  int dp[n + 1][amount + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= amount; j++)
    {
      if (j == 0)
        dp[i][j] = 0;
      else if (i == 0)
        dp[i][j] = 1e5;
      else if (coins[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
    }
  }

  
  return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}