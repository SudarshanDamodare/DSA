#include <bits/stdc++.h>
using namespace std;

int maxOccured(int L[], int R[], int n, int maxx){

    //add 1 to the starting point of the range
    //subtract 1 from (end point + 1) of the range
    vector<int> temp(maxx + 2);
    // int maxi = -1;
    for(int i=0; i<n; i++){
        temp[L[i]] += 1;
        temp[R[i] + 1] -= 1;
    }
    
    //prefix sum of temp this will give freq of the elements
    int msum = temp[0], index;
    for(int i=1; i<maxx+1; i++){
        temp[i] += temp[i - 1];
        if(msum<temp[i]){
            msum = temp[i];
            index = i;
        }
    }
    return index;
}