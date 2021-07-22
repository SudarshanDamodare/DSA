// Print concentric rectangular pattern in a 2d matrix.
// Input: A = 4.
// Output:

// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<vector<int>> prettyPrint(int A){
  vector<vector<int>> res;
  vector<int> temp(2 * A - 1, A);
  // res.push_back(temp);
  for (int i = 0; i < A; i++){
    fill(temp.begin() + i, temp.end() - i, A - i);
    res.push_back(temp);
  }
  int k = A - 2;
  for (int i = A; i < 2 * A - 1; i++){
    res.push_back(res[k]);
    k--;
  }
  return res;
}

int main(){
  int A;
  cin>>A;
  vector<vector<int>> a = prettyPrint(A);
  for(auto row: a){
    for(auto col: row)
      cout<<col<<" ";
    cout<<"\n";
  }
  return 0;
}