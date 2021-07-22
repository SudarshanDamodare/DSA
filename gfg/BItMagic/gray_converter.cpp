

int greyConverter(int n)
{
    
  // Your code here
  return (n ^ (n >> 1)); //the leftmost bit will be preserved and the consecutive bits will be the xor of the current bit and prev bit
}