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

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={13,15,12,14,16,8,6,4,10,30};
  printSpan(a);

  return 0;
}