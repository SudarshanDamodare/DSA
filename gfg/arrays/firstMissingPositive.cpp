#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set


// this segregates the +ve and -ve nos. and return the index from where +ve nos. start
int segregate(vector<int> &A){
  int n=A.size();
  int l=0,r=0;
  while(r<n){
      if(A[r]<=0){
          swap(A[l],A[r]);
          l++;
      }
      r++;
  }
  return l;
}

// this function finds the 1st +ve missing no.
int firstMissing(vector<int> &A){
  int start=segregate(A);
  // for(auto x:A)
  //   cout<<x<<" ";
  // cout<<"\n"<<start<<endl;
  int m=*max_element(A.begin(),A.end());
  vector<bool> temp(m+1,0);
  for(int i=start;i<A.size();i++){
    temp[A[i]-1]=1;
    // cout<<"done"<<endl;
  }
  for(int i=0;i<temp.size();i++){
    if(!temp[i])
      return i+1;
  }
  
  return -1;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> A={1};
  // segregate(A);
  // for(auto x:A){
  //   cout<<x<<" ";
  // }
  cout<<firstMissing(A)<<endl;
  return 0;
}

