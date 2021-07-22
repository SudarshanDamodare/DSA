#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//to form the largest number from the numeric string

int main(){
  string num="4957812";
  sort(num.begin(),num.end(), greater<int>());
  cout<<num<<" ";
  return 0;
}