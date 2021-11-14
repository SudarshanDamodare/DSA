#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

// infix to postfix
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

// Infix to postfix conversion
string toPostfix(string s){
  string res="";

  stack<char> st;

  for(int i=0;i<s.size();i++){
    if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z')){
      res+=s[i];
    }
    else if(s[i]=='('){
      st.push(s[i]);
    }
    else if(s[i]==')'){
      while(!st.empty() && st.top()!='('){
        res+=st.top();
        st.pop();
      }
      if(!st.empty())
        st.pop(); //this is to pop the opening bracket
    }
    else{
      // here the second condition is important as associativity of ^ is right to left
      // for ^ operator we didn't need to pop the previous ^ in the stack
      while(!st.empty() && ((s[i]=='^')?precedence(st.top())>precedence(s[i]):precedence(st.top())>=precedence(s[i]))){
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

  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  cout<<toPostfix("8+(7-9)*2")<<endl;
  // cout<<toPostfix("a+b/c+d*e")<<endl;
  return 0;
}