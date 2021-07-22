#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

void maxTilli(vector<int> arr){
  int m=INT_MIN;
  for(int i=0;i<arr.size();i++){
    m=max(m,arr[i]);
    cout<<m<<" ";
  }
  cout<<endl;
}

int main(){
  vector<int> a={1,0,5,4,6,8};
  maxTilli(a);
  return 0;
}