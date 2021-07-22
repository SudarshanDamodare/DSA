#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

void spiral(vector<vector<int>> a){
  int n=a.size(),m=a[0].size();
  int top=0,bottom=n-1,left=0,right=m-1;

  while(top<=bottom && left<=right){
    //for top
    for(int col=left;col<=right;col++){
      cout<<a[top][col]<<" ";
    }
    top++;

    //for right
    for(int row=top;row<=bottom;row++){
      cout<<a[row][right]<<" ";
    }
    right--;

    //for bottom
    if (top <= bottom){
      for (int col = right; col >= left; col--){
        cout << a[bottom][col] << " ";
      }
      bottom--;
    }
    //for left
    if(left<=right){
      for(int row=bottom;row>=top;row--){
        cout<<a[row][left]<<" ";
      }
    left++;
    }
  }
}

int main(){
  // int n,m;
  // cin>>n>>m;
  // vector<vector<int>> a(n,vector<int>(m));
  vector<vector<int>> a={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++)
  //     cin>>a[i][j];
  // }
  spiral(a);
  return 0;
}