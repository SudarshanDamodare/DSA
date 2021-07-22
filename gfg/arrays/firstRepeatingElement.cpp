#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//Input : 1 5 3 4 3 5 6
//Output: 2 //index of 5 which is repeated and occurs first (considering 1based indexing)
int firstRepeat(vector<int> arr){
  int minIndex=INT_MAX;
  const int N=1e6+2;
  vector<int> idx(N,-1);
  for(int i=0;i<arr.size();i++){
    if(idx[arr[i]]==-1)
      idx[arr[i]]=i;
    else
      minIndex=min(minIndex,idx[arr[i]]);
  }
  return minIndex!=INT_MAX ? minIndex+1: -1;
}

int main(){
  vector<int> a={1,2,3,4,7,5,6};
  cout<<firstRepeat(a)<<endl;
  return 0;
}