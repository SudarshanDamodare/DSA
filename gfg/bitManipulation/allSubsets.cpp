#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// using bitmasking print all the subsets


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n;cin>>n;
  char arr[n];
  for(int i=0;i<n;i++)  cin>>arr[i];

  int total=1<<n; // count of total subsets (2^n)

  for(int mask=0;mask<total;mask++){
    // getting each subset
    for(int i=0;i<n;i++){
      int f=1<<i;
      if((mask & f)!=0) cout<<arr[i];
    }
    cout<<endl;
  }

  return 0;
}