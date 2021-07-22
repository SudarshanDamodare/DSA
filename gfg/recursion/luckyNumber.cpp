

bool isLucky(int n, int &counter)
{
  // add code here
  if (counter > n)
    return 1;
  if (n % counter == 0)
    return 0;
  int temp = counter;
  counter++;
  return (isLucky(n - (n / temp), counter)); //as in every step n/counter numbers are removed
}