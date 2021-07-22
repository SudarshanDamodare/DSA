#include <bits/stdc++.h>
using namespace std;

//in case if array is passed instead of vector no need to pass reference
void rev(vector<int> &arr, int x, int y){
  while(x < y){
    swap(arr[x], arr[y]);
    x++;
    y--;
  }
}

vector<int> leftRotate(int d, vector<int> arr){
  rev(arr, 0, d-1);
  rev(arr, d, 4);
  rev(arr, 0, 4);
  return arr;
}

int main(){
  vector<int> arr = {1,2,3,4,5};
  vector<int> res = leftRotate(4, arr);
  // rev(arr, 0, 4);
  for(int i=0; i<5; i++){
    cout<<res[i]<<" ";
  }
  return 0;
}