#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

// find median of row-wise sorted matrix

// it return the count of elements small than or equal to x
int countSmaller(vector<int> &v, int x){
  int low=0, high=v.size()-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(v[mid]<=x) low=mid+1;
    else  high=mid-1;
  }

  return low;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;

  vector<vector<int> > A(n,vector<int>(m));
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)  cin>>A[i][j];


  int low=0, high=1e9;

  while(low<=high){
    int mid = (low+high)/2;
    int cnt=0;
    for(int i=0;i<n;i++)  cnt+=countSmaller(A[i], mid);

    if(cnt<=(n*m)/2)  low=mid+1;
    else  high=mid-1;
  }

  cout<<low<<endl;

  return 0;
}