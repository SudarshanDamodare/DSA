#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


int postfixEval(string s){
  stack<int> st;

  for(int i=0;i<s.size();i++){
    if(s[i]>='0' && s[i]<='9'){
      st.push(s[i]-'0');
    }
    else{
      int op2=st.top();
      st.pop();
      int op1=st.top();
      st.pop();

      switch (s[i])
      {
      case '+':
        st.push(op1+op2);
        break;
      case '-':
        st.push(op1-op2);
        break;
      case '*':
        st.push(op1*op2);
        break;
      case '/':
        st.push(op1/op2);
        break;
      case '^':
        st.push(pow(op1,op2));
        break;
      }
    }
  }
  return st.top();
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s; cin>>s;
  cout<<postfixEval("523^^")<<endl;
  return 0;
}