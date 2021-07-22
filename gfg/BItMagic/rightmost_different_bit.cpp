#include <bits/stdc++.h>

int posOfRightMostDiffBit(int m, int n)
{
    
    // Your code here
    if(m == n)
        return -1;
    int x = m ^ n; //get all the different bits in m and n
    x = x ^ (x & (x - 1)); //unset rightmost bit then xor with no. to get rightmost set bit
    return (log2(x) + 1); //returns the position of the only set bit
}