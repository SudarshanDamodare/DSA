#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

vector<int> nextGreater(vector<int> a){
  int n=a.size();
  stack<int> st;
  vector<int> res;

  //this code prints in reverse order
  st.push(a[n-1]);
  // cout<<-1<<" ";
  res.pb(-1);

  for(int i=n-2;i>=0;i--){
    while(!st.empty() && st.top()<=a[i]){
      st.pop();
    }
    st.empty()?res.pb(-1):res.pb(st.top());
    st.push(a[i]);
  }
  reverse(res.begin(),res.end());
  return res;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={5,15,10,8,6,12,9,18};
  vector<int> res=nextGreater(a);
  for(auto x:res)
    cout<<x<<" ";
  cout<<endl; 
  return 0;
}
