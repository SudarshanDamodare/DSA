#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

void reverse1(queue<int> &q){
  stack<int> st;
  while(!q.empty()){
    st.push(q.front());
    q.pop();
  }
  while(!st.empty()){
    q.push(st.top());
    st.pop();
  }
}

void reverse2(queue<int> &q){
  if(q.empty())
    return;
  int x=q.front();
  q.pop();
  reverse2(q);
  q.push(x);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}