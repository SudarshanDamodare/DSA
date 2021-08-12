#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


bool myComp(pair<int,int> a, pair<int,int> b){
  double r1=(double)a.first/a.second;
  double r2=(double)b.first/b.second;
  return r1>r2;
}


// pair<value, weight>
// sort for maximum value per unit weight
double fractionalKnapsack(vector<pair<int, int>> v, int cap){
  int n=v.size();
  double res=0.0;

  sort(v.begin(), v.end(), myComp);

  for(int i=0;i<n;i++){
    if(v[i].second<=cap){
      res+=v[i].first;
      cap-=v[i].second;
    }
    else{
      res+=v[i].first*((double)cap/v[i].second);
      break;
    }
  }
  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<pair<int,int>> v={{600,50},{500,20},{400,30}};
  cout<<fractionalKnapsack(v, 50); 
  return 0;
}