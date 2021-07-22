#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//Longest arithmetic subarray
//find length of longest subarray whose elements are in AP
int longest(vector<int> arr){
  int n=arr.size(),diff=arr[1]-arr[0],l=2,res=2;
  for(int i=2;i<n;i++){
    int diff_curr=arr[i]-arr[i-1];
    if(diff_curr==diff){
      l++;
    }else{
      l=2;
      diff=diff_curr;
    }
    res=max(res,l);
  }
  return res;
}

int main(){
  vector<int> a={10,7,4,6,8,10,11};
  cout<<longest(a)<<endl;
  return 0;
}