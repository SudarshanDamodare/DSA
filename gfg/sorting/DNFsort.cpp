#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//sorting array containing 0s,1s and 2s
void DNFsort(vector<int> &arr){
  int low=0,mid=0,high=arr.size()-1;
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr[low],arr[mid]);
      low++;mid++;
    }
    else if(arr[mid]==1)
      mid++;
    else{
      swap(arr[high],arr[mid]);
      high--;
    }
  }
}

int main(){
  vector<int> a={1,0,2,1,0,1,2,1,2};
  DNFsort(a);
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  return 0;
}