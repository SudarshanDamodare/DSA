#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back


// Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

// Return the power of the string.
// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

int maxPower(string s){
  int res = 1,count=1;
  for (int i = 1; i < s.size(); i++){
    if (s[i] == s[i - 1]){
      count++;
      res=max(res,count);
    }
    else
      count = 1;
  }
  return res;
}

int main()
{
  string s="leetcode";
  cout<<maxPower(s)<<endl;
  return 0;
}