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

  // this is for printing lis
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



// Binary search approach
int ceilIdx(int arr[], int l, int r, int x){
  while(l<r){
    int mid=l+(r-l)/2;
    if(arr[mid]>=x) r=mid;
    else  l=mid+1;
  }

  return r;
}

int lis(vector<int> v){
  int n=v.size(), tail[n], len=1;
  tail[0]=v[0];

  for(int i=1;i<n;i++){
    if(v[i]>tail[len-1]){
      tail[len++]=v[i];
    }
    else{
      int next=ceilIdx(tail,0,len-1,v[i]);
      tail[next]=v[i];
    }
  }

  return len;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={5,8,7,1,9};
  cout<<LIS(v)<<endl;
  cout<<lis(v)<<endl;
  return 0;
}