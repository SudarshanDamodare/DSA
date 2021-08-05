#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

int kthLargest(vector<int> v, int k){
  int n=v.size();
  priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.begin()+k);

  for(int i=k;i<n;i++){
    if(v[i]>pq.top()){
      pq.pop();
      pq.push(v[i]);
    }
  }

  return pq.top();
}

int kthSmallest(vector<int> v, int k){
  int n=v.size();
  priority_queue<int> pq(v.begin(), v.begin()+k);

  for(int i=k;i<n;i++){
    if(v[i]<pq.top()){
      pq.pop();
      pq.push(v[i]);
    }
  }
  return pq.top();
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={4, 3, 7, 6, 5};
  cout<<kthLargest(v, 5);
  return 0;
}