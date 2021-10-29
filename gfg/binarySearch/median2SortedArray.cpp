#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;
  int a[n], b[m];
  for(int i=0;i<n;i++)  cin>>a[i];
  for(int i=0;i<m;i++)  cin>>b[i];

  int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;

  int low=0, high=n;

  while(low<=high){
    int cut1=(low+high)/2;
    int cut2=(n+m+1)/2 - cut1;

    // cout<<cut1<<" "<<cut2<<endl;

    l1=(cut1==0)?INT_MIN:a[cut1-1];
    l2=(cut2==0)?INT_MIN:b[cut2-1];
    r1=(cut1==n)?INT_MAX:a[cut1];
    r2=(cut2==m)?INT_MAX:b[cut2];

    // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;

    if(l1<=r2 && l2<=r1)  {
      if((n+m)&1){
        cout<<max(l1,l2)<<endl;
      }
      else{
        double res=(min(l1,l2)+max(r1,r2))/2.0;
        cout<<res<<endl;
      }
      break;
    }
    else if(l1>r2)  high=cut1-1;
    else  low=cut1+1;
  }

  return 0;
}