#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

string mergeAlternately(string word1, string word2)
{
  string res = "";
  int n1 = word1.size(), n2 = word2.size();
  int i=0,j=0;
  while(i<n1 && j<n2){
    res+=word1[i];i++;
    res+=word2[j];j++;
  }
  while(i<n1){
    res+=word1[i];
    i++;
  }
  while(j<n2){
    res+=word2[j];j++;
  }

  
  return res;
}

int main()
{
  string a="ab",b="pqrs";
  cout<<mergeAlternately(a,b)<<endl;
  return 0;
}