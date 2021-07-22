#include <bits/stdc++.h>

bool isSparse(int n){
    
    // Your code
    bool result;
    result = ((n & (n >> 1)) != 0) ? false : true; //right shifting the number and then taking AND means if the consecutive bits are 1 then result is non-zero
    return result;
}