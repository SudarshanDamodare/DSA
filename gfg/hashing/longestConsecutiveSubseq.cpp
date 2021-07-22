#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

int longestSeq(vector<int>& A){
  // int n=A.size();
  us<int> h;
  for(int i=0;i<A.size();i++)
    h.insert(A[i]);
  //2n lookups  
  int res=1;
  for(auto x:h){
    if(h.find(x-1)==h.end()){
      int curr=1;
      while(h.find(x+curr)!=h.end()){
        curr++;
      }
      
      res=max(res,curr);
    }
  }
  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> A={1,3,4,3,3,2,9,10,13,11,13};
  cout<<longestSeq(A)<<endl;
  return 0;
}