#include <bits/stdc++.h>
using namespace std;

void printPowSet(string str){
  int n = str.length();
  int powSet = pow(2, n);
  for(int counter = 0; counter < powSet; counter++){
    for(int i = 0; i < n; i++){
      if((counter & (1 << i)) != 0)
        cout<<str[i];
    }
    cout<<"\n";
  }
}

int main(){
  printPowSet("abc");
  return 0;
}