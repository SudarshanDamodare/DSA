

int RecursivePower(int n, int p)
{
  //Your code here
  if (p == 0) //if power becomes 0 then return 1
    return 1;
  return (n * RecursivePower(n, p - 1)); //in every call reduce the power by 1 and multiply the number
}