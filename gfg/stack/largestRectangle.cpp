#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

int largestRectangle(vector<int> a){
  int n=a.size();
  stack<int> st;
  int maxArea=0;

  for(int i=0;i<n;i++){
    while(!st.empty() && a[st.top()]>=a[i]){
      //this is the pop conditioin
      int top=st.top();
      st.pop();

      int currArea;
      if(st.empty()){
        currArea=a[top]*(i);
      }else{
        currArea=a[top]*(i-st.top()-1);
      }
      maxArea=max(maxArea,currArea);
    }
    st.push(i);
  }

  //this is to handle the items left in stack
  while(!st.empty()){
    int top=st.top();
    st.pop();
    int currArea;
    if(st.empty()){
      currArea=a[top]*(n);
    }else{
      currArea=a[top]*(n-st.top()-1);
    }
    maxArea=max(maxArea,currArea);
  }
  return maxArea;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> a={1,2,3,4,5};
  cout<<largestRectangle(a)<<endl;
  return 0;
}