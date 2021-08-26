#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


struct node{
  int u,v,wt;
  node(int first, int second, int weight){
    u=first;
    v=second;
    wt=weight;
  }
};

bool comp(node a, node b){
  return a.wt<b.wt;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  return 0;
}