#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  // You need to complete this function

  // avoid space at the starting of the string in "move disk....."
  long long toh(int N, int from, int to, int aux)
  {
    // Your code here
    if (N == 1)
    {
      cout << "move disk 1 from rod " << from << " to rod " << to << endl;
      return 1;
    }
    long long c1 = toh(N - 1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    long long c2 = toh(N - 1, aux, to, from);
    return c1 + c2 + 1;
  }
};

int main() {
  long long moves = 0;
  int N;
  cin>>N;
  Solution ob;
  moves = ob.toh(N, 1, 3, 2);
  cout<<moves<<endl;
}