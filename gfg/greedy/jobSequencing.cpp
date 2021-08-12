#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


struct Job{
  int id,dead,profit;
  Job(int i,int d,int p){
    id=i;
    dead=d;
    profit=p;
  }
};

bool myComp(struct Job a, struct Job b){
  return a.profit>b.profit;
}

int maxProfit(vector<struct Job> v){
  int n=v.size();

  sort(v.begin(), v.end(), myComp);

  int m=v[0].dead;
  for(int i=1;i<n;i++){
    m=max(m,v[i].dead);
  }

  vector<int> slot(m+1, -1);

  int countJobs=0, maxProfit=0;

  for(int i=0;i<n;i++){
    for(int j=v[i].dead;j>0;j--){
      if(slot[j]==-1){
        slot[j]=i;
        countJobs++;
        maxProfit+=v[i].profit;
        break;
      }
    }
  }

  return maxProfit;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  return 0;
}