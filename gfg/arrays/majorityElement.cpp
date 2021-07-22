//Implementing moore's algorithm

#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n){
  //code from here finds the candidate
  int maj_index = 0, count = 1;
  for(int i = 1; i<n; i++){
    if(arr[maj_index] == arr[i])
      count++;
    else
      count--;
    if(count == 0){
      maj_index = i;
      count = 1;
    }
  }
  //code from here checks if the candidate found is a majority element or not
  count = 0;
  for(int i = 0; i<n; i++){
    if(arr[maj_index] == arr[i])
      count++;
  }
  if(count <= n/2){
    maj_index = -1;
  }
  return maj_index;
}

int main()
{
  int arr[] = {2,3,6,3,3};
  int index = majorityElement(arr, 5);
  if(index >= 0)
    cout<<arr[index];
  else
    cout<<-1;
  return 0;
}