#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

//lomuto partition
int partition(int arr[], int l, int r){
  int pivot=arr[r];
  int i=l-1;
  for(int j=l;j<r;j++){
    if(arr[j]<pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  // cout<<i+1<<" i"<<endl;
  return i+1;
}


//this function returns the index of kth smallest element but with reference to the partially or fully(depending on the k) sorted array and not initial array
int kthSmallest(int arr[], int k){
  int n=7,l=0;
  // cout<<n<<endl;
  int r=n-1;
  // cout<<"r "<<r<<endl;
  while(l<=r){
    int p=partition(arr,l,r);
    // cout<<"p "<<p<<endl;;
    if(p == (k-1))
      return p;
    else if(p>k-1)
      r=p-1;
    else
      l=p+1;
    // cout<<"loop end\n";
  }
  return -1;
}

int main(){
  // vector<int> a={10,4,5,8,11,6,26};
  int a[] ={10,4,5,8,11,26,6};
  // cout<<partition(a,0,6)<<endl;
  // for(int i=0;i<7;i++)
    // cout<<a[i]<<" ";
  int x=kthSmallest(a,2);
  if(x!=-1)
    (cout<<a[x]<<endl);
  else
    cout<<x<<"\nNot Found\n";
  return 0;
}