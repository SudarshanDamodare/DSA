

unsigned int swapBits(unsigned int n)
{
	
	// Your code here
	unsigned int even_bits, odd_bits;
	even_bits = n & 0xAAAAAAAA; //this gets all the even bits 0xAAAAAAAA this is a 32 bit no. with all even bits 1 and odd bits 0
	odd_bits = n & 0x55555555; //this get all the odd bits
	return ((even_bits >> 1) | (odd_bits << 1));
}