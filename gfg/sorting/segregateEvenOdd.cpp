#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//Segregate even and odd numbers in an array

//using hoare's partition
void sort(vector<int> &arr)
{
  int n = arr.size();
  int i = -1, j = n;
  while (true)
  {
    do
    {
      i++;
    } while (arr[i] % 2 == 0);
    do
    {
      j--;
    } while (arr[j] % 2 != 0);
    if (i >= j)
      return;
    swap(arr[i], arr[j]);
  }
}

int main()
{
  vector<int> arr = {15, 14, 13, 12};
  // int n=sizeof(arr)/sizeof(arr[0]);

  sort(arr);

  for (int x : arr)
    cout << x << " ";
}