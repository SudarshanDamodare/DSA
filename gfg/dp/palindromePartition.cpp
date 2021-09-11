#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


bool isPalindrome(string s, int l, int r){
  int i=l,j=r;

  while(i<j){
    if(s[i]!=s[j])
      return false;
    i++,j--;
  }

  return true;
}


int solve(string s, int l, int r){
  if(l>=r)
    return 0;
  
  if(isPalindrome(s, l ,r))
    return 0;

  int res=INT_MAX;

  for(int k=l;k<r;k++){
    int temp = 1 + solve(s,l,k) + solve(s, k+1, r);
    res=min(res, temp);
  }

  return res;
}

int partition(string s){
  return solve(s,0,s.size()-1);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  // cout<<isPalindrome("iti", 0, 2)<<endl;
  string s="abcb";
  cout<<solve(s, 0, s.size()-1)<<endl;
  // cout<<solve("niti", 1, 3)<<endl;
  return 0;
}