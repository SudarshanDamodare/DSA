#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set


string reverseWords(string& s){
  int start=0;
  for(int end=0;end<s.size();end++){
    if(s[end]==' '){
      // cout<<"end "<<end<<"start "<<start<<endl;
      reverse(s.begin()+start,s.begin()+end);
      start=end+1;
    }
  }
  reverse(s.begin()+start,s.end()); // for last word
  // cout<<s;
  reverse(s.begin(),s.end());
  // cout<<"Hello";
  return s;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s; 
  getline(cin,s);
  // cin>>s;
  // int x=0;cin>>x;cout<<x<<endl;
  // string b;cin>>b;
  // cout<<b;
  // cout<<s;
  string res = reverseWords(s);
  cout<<res;
  return 0;
}