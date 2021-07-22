#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int countDistinct(vector<int> arr){
  unordered_set<int> s(arr.begin(),arr.end()); //alternate this creates a set from the array elements
  // unordered_set<int> s;
  // for(auto x: arr){
  //   s.insert(x);
  // }
  return s.size();
}

int main(){
  cout<<countDistinct({10,20,10,20,30})<<"\n";
  return 0;
}