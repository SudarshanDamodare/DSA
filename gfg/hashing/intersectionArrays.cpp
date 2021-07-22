#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

//return the intersecting distinct elements of two unsorted arrays
vector<int> intersection(vector<int> a, vector<int> b){
  us<int> s;
  for(auto x: a){
    s.insert(x);
  }
  vector<int> res;
  for(auto x: b){
    if(s.find(x) != s.end()){
      res.pb(x);
      s.erase(x);
    }
  }
  return res;
}

int main(){
  vector<int> a={10,15,20,15,5,30,30}, b={5,30,5,30,80};
  vector<int> res = intersection(a,b);
  for(auto x: res){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}