#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//minus 32 from lowercase AScII
void toUpperCase(string &s){
  for(int i=0;i<s.size();i++){
    if(s[i]>='a' && s[i]<='z')
      s[i]-=32;
  }
}

//add 32 in the lowercase chars
void toLowerCase(string &s){
  for(int i=0;i<s.size();i++){
    if(s[i]>='A' && s[i]<='Z')
      s[i]+=32;
  }
}

int main(){
  string s="SudArsHan";
  // toUpperCase(s);
  toLowerCase(s);
  cout<<s<<"\n";
  return 0;
}