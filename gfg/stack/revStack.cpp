#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


void insertAtBottom(stack<int> &st, int ele){

  if(st.empty()){
    st.push(ele);
    return;
  }

  int topEle=st.top();
  st.pop();
  insertAtBottom(st, ele);

  st.push(topEle);
}


void revStack(stack<int> &st){

  if(st.empty())
    return;

  int ele=st.top();
  st.pop();
  revStack(st);
  insertAtBottom(st, ele);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}