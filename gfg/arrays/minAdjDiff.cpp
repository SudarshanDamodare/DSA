#include <bits/stdc++.h>
using namespace std;

//min adjacent diff in circular array
int minAdjDiff(int arr[], int n){    
    // Your code here
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        res = min(abs(arr[i] - arr[(i+1)%n]), res);
    }
    return res;
}