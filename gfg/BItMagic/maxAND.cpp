

int checkBits(int arr[], int n, int pattern) {
   int cnt = 0;
   for (int i = 0; i < n; i++) {
      if ((pattern & arr[i]) == pattern) {
         cnt++;
      }
   }
   return cnt;
}
int maxAND(int arr[], int n) {
   int result = 0;
   int count;
   for (int i = 31; i >= 0; i--) {
      count = checkBits(arr, n, (result | (1 << i)));
      if (count >= 2) {
         result |= (1 << i);
      }
   }
   return result;
}