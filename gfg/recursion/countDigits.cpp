#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
   //Your code here
   if(n < 10) //using base case n == 0 gives output 0 if number entered is 0
    return 1;
   
   int count = 1 + countDigits(n/10);
   return count;
}