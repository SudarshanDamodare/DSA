#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

void printSpan(vector<int> a){
  int n=a.size();
  stack<int> st;
  st.push(0);

  cout<<1<<" ";

  for(int i=1;i<n;i++){
    while(!st.empty() && a[st.top()]<=a[i]){
      st.pop();
    }
    int span = st.empty() ? i + 1 : i - st.top();
    cout<<span<<" ";
    st.push(i);
  }
  cout<<endl;
}

void span(vector<int> a){
  int n=a.size();
  stack<int> st;  // stores index

  for(int i=0;i<n;i++){
    while(!st.empty() && a[st.top()]<=a[i]){
      st.pop();
    }

    int res=(st.empty())?i+1:i-st.top();
    cout<<res<<" ";
    st.push(i);
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={100,80,60,70,60,75,85};
  printSpan(a);
  // cout<<endl;
  span(a);

  return 0;
}