#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//given an unsorted array with non-negative integers find a subarray which adds to the given sum
//output the index of starting element and ending element (1based indexing)
vector<int> subarrayWithSum(vector<int> &arr, int S){
  vector<int> res;
  int n=arr.size();
  int start=0,end,currSum=arr[0];
  for(end=1;end<=n;end++){
    while(currSum>S && start<n-1){
      currSum-=arr[start];
      start++;
    }
    if(currSum==S){
      res.pb(start+1);
      res.pb(end);
      return res;
    }
    //add this element
    if(end<n)
      currSum+=arr[end];
  }
  
  res.pb(-1);
  res.pb(-1);
  return res;
}

int main(){
  vector<int> a={1,2,3,8};
  int S=5;
  vector<int> res=subarrayWithSum(a,S);
  for(int x: res)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}