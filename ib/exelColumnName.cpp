#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

string columnName(int A){
  string res = "";
  while (A > 0){
    char d;
    // if (A % 26 != 0){
      d = (A-1) % 26 + 'A';
      // A = A / 26;
    // }
    // else{
      // d = 'Z';
      // A = (A - 1) / 26;
    // }
    // res.insert(0, 1, d);
    res=d+res;
    A=(A-1)/26;
  }
  return res;
}

int main(){
  string demo = columnName(27);
  cout<<demo;
  return 0;
}