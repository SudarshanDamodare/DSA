#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int reverseNumber(int A){
  bool negativeFlag = false;
  if (A < 0)
  {
    negativeFlag = true;
    A = -A;
  }

  int prev_rev_num = 0, rev_num = 0;
  while (A != 0)
  {
    int curr_digit = A % 10;

    if (rev_num > INT_MAX / 10 || (rev_num == INT_MAX / 10 && rev_num % 10 > INT_MAX % 10))
    {
      // cout << "WARNING OVERFLOWED!!!"
      //      << endl;
      return 0;
    }
    rev_num = (rev_num * 10) + curr_digit;

    // checking if the reverse overflowed or not.
    // The values of (rev_num - curr_digit)/10 and
    // prev_rev_num must be same if there was no
    // problem.

    prev_rev_num = rev_num;
    A = A / 10;
  }

  return (negativeFlag == true) ? -rev_num : rev_num;
}

int main(){
  cout<<reverseNumber(21474836470)<<"\n";
  return 0;
}