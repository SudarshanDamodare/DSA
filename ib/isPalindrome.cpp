#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int isPalindrome(int A){
  int divisor = 1;
  if (A < 0)
    return 0;
  while (A / divisor >= 10){
    divisor *= 10;
  }
  while (A != 0){
    int first = A / divisor, last = A % 10;
    if (first != last)
      return 0;
    A = (A % divisor) / 10;
    divisor /= 100;
  }
  return 1;
}

int main(){
  int a=12566521;
  isPalindrome(a) == 0 ? cout<<"not palindrome\n" : cout<<"is palindrome\n";
  return 0;
}