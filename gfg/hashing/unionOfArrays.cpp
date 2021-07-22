#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

vector<int> unionArrays(vector<int> a, vector<int> b){
  vector<int> res;
  us<int> s;
  for(auto x: a){
    s.insert(x);
  }
  for(auto x: b){
    s.insert(x);
  }
  for(auto x: s){
    res.pb(x);
  }
  return res;
}

int main(){
  vector<int> a={15,20,5,15}, b={15,15,15,20,10};
  vector<int> res=unionArrays(a,b);
  for(auto x: res){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}