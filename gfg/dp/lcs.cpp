#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


// return length of longest common subsequence

// recursive approach
int lcs(string x, string y, int n, int m){
  if(n==0 || m==0)
    return 0;
  
  if(x[n-1]==y[m-1])
    return 1+lcs(x,y,n-1,m-1);
  else
    return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
}


// dp top-down
int LCS(string x, string y){
  int n=x.size();
  int m=y.size();

  int dp[n+1][m+1];

  for(int i=0;i<=n;i++)
    dp[i][0]=0;
  for(int j=0;j<=m;j++)
    dp[0][j]=0;

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(x[i-1]==y[j-1])
      dp[i][j]=1+dp[i-1][j-1];
    else
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
  }

  return dp[n][m];
}


// print LCS (longest common si=ubsequence between two strings)
string printLCS(string x, string y){
  int n=x.size(), m=y.size();

  int dp[n+1][m+1];

  for(int i=0;i<=n;i++)
    dp[i][0]=0;
  for(int j=1;j<=m;j++)
    dp[0][j]=0;

  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(x[i-1] == y[j-1])
      dp[i][j]=dp[i-1][j-1]+1;
    else
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
  }

  int i=n, j=m;
  string res="";
  while(i>0 && j>0){
    if(x[i-1]==y[j-1]){
      res=x[i-1]+res;
      i--;
      j--;
    }
    else{
      if(dp[i][j-1]>dp[i-1][j]){
        j--;
      }
      else{
        i--;
      }
    }
  }

  return res;
}


// return length of longest common substring
int lcSubstring(string x, string y){
  int n=x.size();
  int m=y.size();

  int dp[n+1][m+1];

  for(int i=0;i<=n;i++)
    dp[i][0]=0;
  for(int j=0;j<=m;j++)
    dp[0][j]=0;

  int res=INT_MIN;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++){
    if(x[i-1]==y[j-1])
      dp[i][j]=1+dp[i-1][j-1];
    else
      dp[i][j] = 0;

    res=max(res,dp[i][j]);
  }

  
  return res;
}




// shortest common supersequence return its length
int scsLength(string x, string y){
  int n=x.size(), m=y.size();

  return n+m-LCS(x,y);
}


//  print shortest common supersequence
string printSCS(string x, string y){
  int n=x.size(), m=y.size();
  string lcs=printLCS(x,y);
  int l=lcs.size();

  int i=0,j=0,k=0;
  string res="";

  while(i<n || j<m){
    while(i<n && (k>=l || x[i]!=lcs[k])){
      res+=x[i];
      i++;
    }
    while(j<m && (k>=l || y[j]!=lcs[k])){
      res+=y[j];
      j++;
    }
    
    if(k<l){
      res+=lcs[k];
      i++;
      j++;
      k++;
    }
  }

  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string x="babbb", y="bbbab";
  cout<<lcs(x,y, x.size(), y.size())<<endl;
  cout<<LCS(x,y)<<endl;
  cout<<lcSubstring(x,y)<<endl;
  cout<<printLCS(x,y)<<endl;
  cout<<scsLength(x,y)<<endl;
  cout<<printSCS(x,y);
  return 0;
}