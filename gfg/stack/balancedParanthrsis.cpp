#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

bool matching(char a, char b){
  // cout<<a<<" "<<b<<endl;
  return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
}

bool balanced(string str){
  stack<char> s;
  for(char x:str){
    if(x=='[' || x=='{' || x=='('){
      s.push(x);
    }
    else{
      if(s.empty())
        return false;
      if(matching(s.top(),x)==false)
        return false;
      else
        s.pop();
    }
  }
  return (s.empty()==true);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string str;
  cin>>str;
  stack<char> s;

  (balanced(str))?cout<<"YES\n":cout<<"NO\n";
  // cout<<matching('(',')');
  return 0;
}