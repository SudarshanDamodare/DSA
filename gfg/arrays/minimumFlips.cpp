#include <bits/stdc++.h>
using namespace std;

void printGrps(bool arr[], int n){
  for(int i = 1; i<n; i++){
    if(arr[i] != arr[i-1]){
      if(arr[i] != 0){
        cout<<"From "<<i<<" to ";
      }else
      {
        cout<<(i-1)<<endl;
      }
      
    }
  }
  if(arr[n-1] != arr[0])
    cout<<n-1<<endl;
}

int main(){
  bool arr[] = {0,0,1,1,0,0,1,1,0,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  printGrps(arr, size);
  return 0;
}