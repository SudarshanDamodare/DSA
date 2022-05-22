#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

int lcm=1,mini=INT_MAX;


void sieve(int n, vector<bool> &isPrime){
  if(n<=1) return;

  for(int i=2;i*i<=n;i++){
    if(isPrime[i]){
      for(int j=i*i;j<=n;j+=i) isPrime[j]=false;
    }
  }
}

int gcd(int a, int b){
  if(b==0)  return a;
  else  return gcd(b,a%b);
}

int getLCM(int a, int b){
  return (a*b)/gcd(a,b);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n=0,a;
  vector<int> v;
  lcm=1,mini=INT_MAX;

  while(cin>>a){
    v.pb(a);
    n++;
    mini=min(a,mini);
  }


  for(auto it:v){
    if(it!=mini){
      lcm=getLCM(lcm,it);
    }
  }

  vector<bool> isPrime(lcm+mini+1,1);

  sieve(lcm+mini, isPrime);
  if(isPrime[lcm+mini]) cout<<lcm+mini<<endl;
  else  cout<<"None\n";

  return 0;
}