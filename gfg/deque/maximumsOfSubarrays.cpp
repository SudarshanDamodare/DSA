#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// Print the maximum in all the subarrays of size K in a given array
void maximumsOfSubarrays(vector<int> a, int k){
  deque<int> dq;

  for(int i=0;i<k;i++){
    while(!dq.empty() && a[i]>=a[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);
  }

  for(int i=k;i<a.size();i++){
    cout<<a[dq.front()]<<" ";

    while(!dq.empty() && dq.front()<=i-k){
      dq.pop_front();
    }

    while(!dq.empty() && a[i]>=a[dq.back()])
      dq.pop_back();
    
    dq.push_back(i);
  }
  cout<<a[dq.front()]<<endl;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  maximumsOfSubarrays({20,40,30,10,60}, 3);
  return 0;
}