#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

// find Nth root of the given no. 
double mul(double x, double n){
  double res=1.0;
  for(int i=0;i<n;i++)  res*=x;
  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n, m;
  cin>>n>>m;
  // cout<<n<<" "<<m<<endl;
  double eps=1e-6;

  double low=1, high=m, mid;
  while((high-low)>eps){
    mid=(high+low)/2.0;

    if(mul(mid,n)<m) low=mid;
    else  high=mid;
  }

  cout<<high<<" "<<low<<endl;

  return 0;
}