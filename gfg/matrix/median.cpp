#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

int matrixMedian(vector<vector<int>>& a){
  int r=a.size(),c=a[0].size();
  int min=a[0][0],max=a[0][c-1];

  for(int i=0;i<r;i++){
    if(a[i][0]<min){min=a[i][0];}
    if(a[i][c-1]>max){max=a[i][c-1];}
  }

  int medPos=(r*c+1)/2;
  while(min<max){
    int mid=(min+max)/2;
    int midPos=0;
    for(int i=0;i<r;i++){
      midPos+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin(); //this gives the position of element just greater than mid
    }

    if(midPos<medPos)
      min=mid+1;
    else
      max=mid;
  }
  return min;
}

int main(){
  vector<vector<int>> a={{5,10,20,30,40},{1,2,3,4,6},{11,13,15,17,19}};
  cout<<matrixMedian(a)<<"\n";
  return 0;
}