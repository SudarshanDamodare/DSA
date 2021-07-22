#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

const int CHAR = 256;

int fact(int n){ 
    return (n <= 1) ? 1 : n * fact(n - 1); 
}

int lexicographicRank(string& s){
  int n=s.size();
  int res=1,mul=fact(n);
  vector<int> count(CHAR,0);
  for(int i=0;i<n;i++)
    count[s[i]]++;

  for(int i=1;i<CHAR;i++)
    count[i]+=count[i-1];

  for(int i=0;i<n-1;i++){
    mul=mul/(n-i);
    res=res+count[s[i]-1]*mul;

    for(int j=s[i];j<CHAR;j++)
      count[j]--;
  }
  return res;
}

int lexRank(string &str){ 
    int res = 1;
    int n=str.length();
    int mul= fact(n);
    vector<int> count(CHAR,0);
    for(int i=0;i<n;i++)
        count[str[i]]++;
    for(int i=1;i<CHAR;i++)
        count[i]+=count[i-1];
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i);
        res=res+count[str[i]-1]*mul;
        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return res;
} 

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s;cin>>s;
  cout<<lexicographicRank(s)<<endl;
  cout<<lexRank(s)<<endl;
  return 0;
}