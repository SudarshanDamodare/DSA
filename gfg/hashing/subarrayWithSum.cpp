#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

bool subarraySum(vector<int> a, int sum){
  us<int> h;
  int preSum=0;
  for(auto x:a){
    preSum+=x;
    if(preSum==sum)
      return true;
    if(h.find(preSum-sum)!=h.end())
      return true;
    h.insert(preSum);
  }
  return false;
}

int main(){
  cout<<subarraySum({1,5,7,10,-1},0)<<endl;
  return 0;
}