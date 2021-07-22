#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

//Naive
// void setZero(vector<vector<int>> &A){
//   int m = A.size(), n = A[0].size();
//   // cout<<m<<" "<<n<<endl;
//   vector<vector<int>> track;
//   for (int i = 0; i < m; i++)
//   {
//     for(int j=0;j<n;j++){
//       // cout<<"done\n";
//       if(A[i][j]==0)
//         track.push_back({i,j});
//     }
//   }
  
//   for (int i = 0; i < track.size(); i++)
//   {
//     int row = track[i][0], col = track[i][1];
//     // set row 0
//     for (int i = 0; i < n; i++)
//       A[row][i] = 0;
//     // fill(A[track[i][0]], A[track[i][0]].begin(),A[track[i][0]].end(),0);

//     //set column 0
//     for (int i = 0; i < m; i++)
//       A[i][col] = 0;
//   }
// }

//Efficient
void setZero(vector<vector<int>> &A){
  int col0=1,m=A.size(),n=A[0].size();
    
  for(int i=0;i<m;i++){
    if(A[i][0]==0)
        col0=0;
    for(int j=1;j<n;j++){ //not including 1st column as it is done by col0 variable
      if(A[i][j]==0)
      A[i][0]=A[0][j]=0;
    }
  }
    
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=1;j--){
      if(A[i][0]==0 || A[0][j]==0)
        A[i][j]=0;
    }
    if(col0==0)
      A[i][0]=0;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  vector<vector<int>> A={{0,1},{1,1}};
  setZero(A);
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A[i].size();j++)
      cout<<A[i][j]<<" ";
    cout<<"\n";
  }

  return 0;
}