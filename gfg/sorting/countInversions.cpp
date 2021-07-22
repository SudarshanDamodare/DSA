#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

ll merge(vector<int> &arr, int l, int mid, int r){
  ll inv=0;
  int n1=mid-l+1,n2=r-mid;
  vector<int> left(n1),right(n2);
  for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
  for(int i=0;i<n2;i++)
    right[i]=arr[mid+1+i];

  int i=0,j=0,k=l;
  while(i<n1 && j<n2){
    if(left[i]<=right[j]){
      arr[k]=left[i];
      k++;i++;
    }
    else{
      //left[i]>right[j]
      arr[k]=right[j];
      inv+=n1-i;
      k++;j++;
    }
  }
  while(i<n1){
    arr[k]=left[i];
    k++;i++;
  }
  while(j<n2){
    arr[k]=right[j];
    k++;j++;
  }
  return inv;
}

ll mergeSort(vector<int> &arr, int l, int r){
  ll inv=0;
  if(l<r){
    int mid=(l+r)/2;
    inv+=mergeSort(arr,l,mid);
    inv+=mergeSort(arr,mid+1,l);
    inv+=merge(arr,l,mid,r);
  }
  return inv;
}

int main(){
  vector<int> a={3,5,6,9,1,2,7,8};
  cout<<mergeSort(a,0,a.size()-1);
  return 0;
}