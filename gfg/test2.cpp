#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST_IO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


ll solution(int arr[], int n, int k, int count, int sum){
  if(count==0)  return 0;
  if(k==0) return sum;
  int time=0;
  priority_queue<int, vector<int>, greater<int>> pq;

  // for(ll i=0;i<n;i++)
  ll i=0, cnt=0, x=0;
    while(i<n && arr[i] == 0) x++,i++;
    while(i<n){
        cnt = 0;
        while(i<n && arr[i] == 0) cnt++,i++;
        if(i == n) break;
        else if(cnt > 0) pq.push(cnt);
        else i++;
    }
    if(x+cnt > 0)
    pq.push(x+cnt);



  while(pq.size()>0 && time<k){
    sum+=2*count;
    time++;
    while(pq.size()>0 && 2*time>=pq.top()){
      ll x=pq.top();
      count+=(x%2==0)?2:1;
      pq.pop();
    }
    count+=2*pq.size();
  }

  if(time<k){
    sum+=(k-time)*2*n;
  }

  return sum;
}


int main(){
  FAST_IO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int t;cin>>t;
  while(t--){
    int n, k;
    cin>>n>>k;
    int arr[n];
    int count=0, sum=0;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(arr[i]>0) count++;
      sum+=arr[i];
    }
    cout<<solution(arr, n, k, count, sum)<<endl;
  }

  return 0;
}