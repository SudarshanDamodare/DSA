#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int columnNumber(string A){
  int res=0;
  for(char s : A){
    int d = s-'A'+1;
    res=res*26+d;
  }
  return res;
}

int main(){

  return 0;
}