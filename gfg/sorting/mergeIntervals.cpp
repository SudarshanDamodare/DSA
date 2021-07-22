#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

struct Interval{
  int start,end;
};

//comparison function to sort the struct in ascending order of start point
bool comp(Interval x, Interval y){
  if(x.start<=y.start)
    return 1;
  else
    return 0;
}

void merge(vector<Interval> a){
  int n = a.size();
  sort(a.begin(), a.end(), comp);
  // for(auto x:a){
  //   cout<<x.start<<" "<<x.end<<endl;
  // }
  // cout<<"sorting done\n";
  int res = 0;
  for(int i=1;i<n;i++){
    if(a[res].end>=a[i].start){
      a[res].end = max(a[res].end, a[i].end);
    }
    else{
      res++;
      a[res]=a[i];
    }
  }
  for(int i=0;i<=res; i++){
    cout<<a[i].start<<" "<<a[i].end<<endl;
  }
}

int main(){
  vector<Interval> a= {{5,10},{3,15},{18,30},{2,7}};
  merge(a);  //this won't change the original array as the copy of the array is passed and not the reference
  // cout<<"merge done\n";
  // for(auto x:a)
  //   cout<<x.start<<" "<<x.end<<endl;
  return 0;
}