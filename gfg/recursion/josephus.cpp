

int jos(int n, int k){
    if(n == 1)
        return 0;
    else
        return ((jos(n - 1, k) + k)%n); //this gets the position considering start from 0
}
int josephus(int n, int k)
{
   //Your code here
   return jos(n, k) + 1; //as 1st person start from 1 we need to add 1 to the result of above fun
}