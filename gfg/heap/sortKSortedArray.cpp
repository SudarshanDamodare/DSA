#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// Sort a K sorted array
void sortK(vector<int> &a, int k){
  int n=a.size();
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i=0;i<=k;i++){
    pq.push(a[i]);
  }

  int index=0;
  for(int i=k+1;i<n;i++){
    a[index++]=pq.top();
    pq.pop();
    pq.push(a[i]);
  }

  while(!pq.empty()){
    a[index++]=pq.top();
    pq.pop();
  }
}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={9,8,7,18,19,17};
  sortK(v, 2);
  for(auto x:v){
    cout<<x<<" ";
  }
  return 0;
}