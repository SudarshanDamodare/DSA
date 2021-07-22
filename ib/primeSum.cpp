#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

// Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
// If there are more than one solutions possible, return the lexicographically smaller solution.
vector<int> primeSum(int A){
  vector<int> res;
  //implementing Sieve of Eratosthenes
  vector<bool> isPrime(A + 1, true);
  for (int i = 2; i * i <= A; i++){
    if (isPrime[i]){
      for (int j = i * i; j <= A; j += i)
        isPrime[j] = false;
    }
  }
  for (int i = 2; i <= A / 2; i++){
    if (isPrime[i] && isPrime[A - i]){
      res.push_back(i);
      res.push_back(A - i);
      break;
    }
  }
  return res;
}


int main(){
  int A=9990;
  vector<int> res = primeSum(A);
  cout<<res[0]<<" "<<res[1]<<"\n";
  return 0;
}