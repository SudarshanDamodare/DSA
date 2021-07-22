#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set


void rbSearch(string& txt, string& pat){
  int n=txt.size(),m=pat.size();
  // cout<<m<<"patSize\n";

  int d=5,q=1000000007;

  int h=1;
  for(int i=1;i<m;i++)
    h=(h*d)%q;
  // cout<<h<<endl;

  //computing intial hash value p and t
  int p=0,t=0;
  for(int i=0;i<m;i++){
    p=(p*d + pat[i]);
    t=(t*d + txt[i]);
  }
  // cout<<p<<"pat hash\n";

  for(int i=0;i<=n-m;i++){

    //check for spurious hit
    if(t==p){
      bool flag=true;
      for(int j=0;j<m;j++){
        if(pat[j]!=txt[i+j]){
          flag=false;
          break;
        }
      }
      if(flag){
        cout<<i<<" ";
      }
    }

    //computing next window hash
    if(i<n-m){
      t=(d*(t-txt[i]*h) + txt[i+m])%q;
      if(t<0)
        t=t+q;
      // cout<<t<<"next hash\n";
    }
  }
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string txt;
  cin>>txt;
  string pat; cin>>pat;
  rbSearch(txt,pat);
  return 0;
}