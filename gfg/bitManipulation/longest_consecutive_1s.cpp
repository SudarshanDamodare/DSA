

int maxConsecutiveOnes(int n)
{
    int res = 0;
    // Your code here
    while(n > 0){
        n = (n & (n >> 1)); //right shift and AND with the number eliminates the rightmost 1 from the consecutive 1s
        res++;
    }
    return (res);
}