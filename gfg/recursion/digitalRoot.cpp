

int digitalRoot(int n)
{
  //Your code here
  if (n < 10)
    return n;
  int sum = digitalRoot(n / 10) + n % 10;
  if (sum < 10)
    return sum;
  else
    return digitalRoot(sum);
}