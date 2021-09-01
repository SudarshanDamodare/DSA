#include <bits/stdc++.h>
using namespace std;
#define FAST_IO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map



int setBits(int n){
  int res=0;
  while(n>0){
    n=n&(n-1);
    res++;
  }
  return res;
}

bool comp(int a, int b){
  if(setBits(a)==setBits(b))
    return a>b;
  return setBits(a)>setBits(b);
}

int solution(int arr[], int n, int m){
  sort(arr, arr+n, comp);
  // map<int, vector<int>, greater<int> > mp;
  // for(int i=0;i<n;i++){
  //   mp[setBits(arr[i])].pb(arr[i]);
  // }

  // vector<int> res;
  // for(auto it:mp){
  //   for(auto x: it.second)
  //     res.pb(x);
  // }
  for(int i=0;i<m;i++)
    cout<<arr[i]<<" ";
  return -1;
}


int main(){
  FAST_IO;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int t;cin>>t;
  while(t--){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<solution(arr, n, m)<<endl;
    // cout<<setBits(5);
  }

  return 0;
}