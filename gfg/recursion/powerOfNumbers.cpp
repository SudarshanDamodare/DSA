

long long rev(int n){
  long long rev_num = 0;
  while(n > 0){
    rev_num = rev_num*10 + n%10;
    n = n/10;
  }
}

long long power(int N, int R)
{
  //Your code here
  if (R == 0)
    return 1;
  // long long res = N * power(N, R - 1);
  // return (res%1000000007);
  return (N * power(N, R - 1)) % 1000000007;
}