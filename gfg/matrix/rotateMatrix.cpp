#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

void transpose(vector<vector<int>> &a){
  for(int i=0;i<a.size();i++)
    for(int j=i+1;j<a.size();j++)
      swap(a[i][j],a[j][i]);
}

void rotate(vector<vector<int>> &a){
  for(int i=0;i<a.size();i++){
    reverse(a[i].begin(),a[i].end());
  }
  transpose(a);
}

void rotate2(vector<vector<int>> &a){
  transpose(a);
  reverse(a.begin(),a.end()); //this reverses the columns
}

int main(){
  vector<vector<int>> a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  rotate(a);
  rotate2(a);
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a.size();j++){
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}