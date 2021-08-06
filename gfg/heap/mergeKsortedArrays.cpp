#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set
#define um unordered_map


struct Triplet{
  int val;
  int pos;
  int index;
  Triplet(int data, int position, int arrIndex){
    val=data;
    pos=position;
    index=arrIndex;
  }
};

struct MyComp{
  bool operator() (Triplet &t1, Triplet &t2){
    return t1.val>t2.val;
  }
};

// Merge k-sorted arrays
vector<int> mergeK(vector<vector<int>> &v){
  int k=v.size();
  vector<int> res;
  priority_queue<struct Triplet, vector< struct Triplet>, MyComp> pq;
  for(int i=0;i<k;i++){
    Triplet ob(v[i][0], i, 0);
    pq.push(ob);
  }
  // cout<<pq.top().val<<endl;

  while(!pq.empty()){
    auto curr=pq.top();
    pq.pop();
    int x=curr.val;
    int p=curr.pos;
    int i=curr.index;
    // cout<<x<<" "<<p<<" "<<i<<endl;

    res.push_back(x);
    if(i+1<v[p].size()){
      Triplet ob(v[p][i+1], p, i+1);
      pq.push(ob);
    }
  }

  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif


  vector<vector<int>> v={{5,10},{4,9},{6,50}};
  vector<int> res=mergeK(v);
  for(auto x:res){
    cout<<x<<" ";
  }
  return 0;
}