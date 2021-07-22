#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map

void revSentence(string s){
  stack<string> st;

  for(int i=0;i<s.size();i++){
    string word="";
    while(s[i]!=' ' && i<s.size()){
      word+=s[i];
      i++;
    }
    st.push(word);

    //the below condition removes extra spaces
    while( s[i+1]==' ' && i<s.size()){
      i++;
    }
  }

  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s;
  getline(cin,s);
  // cout<<s;
  revSentence(s);

  return 0;
}