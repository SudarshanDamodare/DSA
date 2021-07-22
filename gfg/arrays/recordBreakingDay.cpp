#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//return the count of record breaking days
//if a element is greater than all the previous days and greater than the next day then it is a recordBreaking
int recordBreaking(vector<int> arr){
  int n=arr.size();
  int m=INT_MIN,count=0;
  for(int i=0;i<n;i++){
    if(arr[i]>m && (i==n-1 || arr[i]>arr[i+1])){
      count++;
      cout<<arr[i]<<" ";
    }
    m=max(m,arr[i]);
  }
  cout<<endl;
  return count;
}


int main(){
  vector<int> a={1,2,0,7,2,0,2,8};
  cout<<recordBreaking(a)<<endl;
  return 0;
}