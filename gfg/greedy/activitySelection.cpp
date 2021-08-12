#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// given a list of activities with start and end time maximise the number of activites done
// by a single tasking machine
bool myComp(pair<int, int> a, pair<int, int> b){
  return a.second<b.second;
}

int activitySelection(vector<pair<int, int>> v){
  int n=v.size();
  sort(v.begin(), v.end(), myComp);
  int prev=0;
  int res=1;

  for(int i=1;i<n;i++){
    if(v[i].first>=v[prev].second){
      res++;
      prev=i;
    }
  }
  return res;
}




int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<pair<int,int>> v={{3,8},{2,4},{1,3},{10,11}};
  cout<<activitySelection(v);
  // for(auto x:v){
  //   cout<<x.first<<" "<<x.second<<endl;
  // }
  return 0;
}