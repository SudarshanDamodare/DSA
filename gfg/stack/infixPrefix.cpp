#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


int precedence(char c){
  if(c=='^')
    return 3;
  else if(c=='*' || c=='/')
    return 2;
  else if(c=='+' || c=='-')
    return 1;
  else
    return -1;
}

// Infix to prefix conversion
string toPrefix(string s){
  reverse(s.begin(),s.end());
  // instead of changing ( to ) and ) to ( in reversed string we'll change the conditions
  string res="";

  stack<char> st;

  for(int i=0;i<s.size();i++){
    if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
      res+=s[i];
    }
    else if(s[i]==')'){
      st.push(s[i]);
    }
    else if(s[i]=='('){
      while(!st.empty() && st.top()!=')'){
        res+=st.top();
        st.pop();
      }
      if(!st.empty())
        st.pop(); //this is to pop the opening bracket
    }
    else{
      // here the second condition is important as associativity of ^ is right to left
      while(!st.empty() && ((s[i]=='^')?precedence(st.top())>=precedence(s[i]):precedence(st.top())>precedence(s[i]))){
        res+=st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }

  while(!st.empty()){
    res+=st.top();
    st.pop();
  }

  reverse(res.begin(),res.end());
  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  // cout<<toPrefix("a^b^c")<<endl;
  // cout<<toPrefix("a+b/c+d*e")<<endl;
  // cout<<toPrefix("(a-b/c)*(a/k-l)")<<endl;
  // cout<<toPrefix("x+y*z")<<endl;
  cout<<toPrefix("(x+y)*z")<<endl;
  // cout<<toPrefix("(x+y)*(z+w)")<<endl;
  cout<<toPrefix("x+y*(z-w)")<<endl;
  cout<<toPrefix("x+y*z/w+u")<<endl;
  return 0;
}