#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

//efficient
void transpose(vector<vector<int>> &a){
  for(int i=0;i<a.size();i++)
    for(int j=i+1;j<a.size();j++)
      swap(a[i][j],a[j][i]);
}

//naive
void transpose1(vector<vector<int>> &a){
  int n=a.size();
  vector<vector<int>> temp(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j]=a[j][i];
    }
  }
  a=temp;
}

int main(){
  vector<vector<int>> a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  transpose(a);
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a.size();j++){
      cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}