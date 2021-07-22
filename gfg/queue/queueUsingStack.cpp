#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

struct StackQueue{
  stack<int> s1, s2;

  void push(int x){
    s1.push(x);
  }

  int pop(){
    if(s2.empty()){
      if(s1.empty()){
        return -1;
      }
      else{
        while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
        }
      }
    }
    int res=s2.top();
    s2.pop();
    return res;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}