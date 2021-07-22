#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

vector<int> searchMatrix(vector<vector<int>> a, int x){
  int r=a.size(),c=a[0].size();
  vector<int> res(2,-1);
  int i=0,j=c-1;
  while(i<r && j>=0){
    if(x==a[i][j]){
      // cout<<"Found";
      res[0]=i;res[1]=j;
      break;
    }else if(x<a[i][j]){
      j--;
    }else{
      i++;
    }
  }
  return res;
}

int main(){
  vector<vector<int>> a={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
  
  vector<int> res=searchMatrix(a,100);
  cout<<res[0]<<" "<<res[1]<<endl;
  return 0;
}