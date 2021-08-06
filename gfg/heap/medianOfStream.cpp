#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// Print median of a stream of data
void printMedian(vector<int> v){
  priority_queue<int> s; // this stores smaller elements
  priority_queue<int, vector<int>, greater<int>> g; //this stores greater elements

  s.push(v[0]);
  cout<<v[0]<<endl;

  for(int i=1;i<v.size();i++){
    int x=v[i];
    // cout<<x<<" /"<<endl;
    if(s.size()>g.size()){
      if(s.top()>x){
        g.push(s.top());
        s.pop();
        s.push(x);
      }
      else
        g.push(x);
      // cout<<s.top()<<" "<<g.top()<<" ";
      cout<<(s.top()+g.top())/2.0<<endl;
    }
    else{
      if(x<=s.top()){
        s.push(x);
      }
      else{
        s.push(g.top());
        g.pop();
        g.push(x);
      }
      cout<<s.top()<<endl;
    }
  }

}



int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  vector<int> v={12,15,10,5,8,7,16};
  printMedian(v);
  return 0;
}