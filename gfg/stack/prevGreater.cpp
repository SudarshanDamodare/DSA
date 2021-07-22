#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

void prevGreater(vector<int> a){
  int n=a.size();
  stack<int> st;
  st.push(a[0]);
  cout<<-1<<" ";

  for(int i=1;i<n;i++){
    while(!st.empty() && st.top()<=a[i]){
      st.pop();
    }
    st.empty()?cout<<-1<<" ":cout<<st.top()<<" ";
    st.push(a[i]);
  }
  cout<<endl;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={18,9,12,6,8,10,15,5};
  prevGreater(a);
  return 0;
}