#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int a,b,c;
  cin>>a>>b>>c;

  int maxi=max(a,max(b,c));
  int sum;
  sum=a+b+c-maxi;
  // sum-=maxi;
  if(sum==maxi || sum+1==maxi || sum==maxi+1 || a==b==c || (a==b && b==c && a==c))  cout<<"possible\n";
  else cout<<"impossible\n";

  return 0;
}