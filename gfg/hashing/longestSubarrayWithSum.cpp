#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set


int solution(vector<int> A, int sum){
  int n=A.size();
  unordered_map<int,int> m;
  int preSum=0,res=-1;
  for(int i=0;i<n;i++){
    preSum+=A[i];
    if(preSum==sum){
      res=i+1;
    }
    if(m.find(preSum)==m.end()){
      m.insert({preSum,i});
    }
    if(m.find(preSum-sum)!=m.end()){
      res=max(res,i-m[preSum-sum]);
    }
  }
  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  vector<int> A={1,2,-4,2,2};
  return 0;
}