#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
  int qlen = queries.size();
  // cout<<"qlen: "<<qlen<<endl;
  int lastAns = 0;
  vector<int> res;
  vector<vector<int>> seqList(n);
  for (int i = 0; i < qlen; i++)
  {
    int k = (lastAns ^ queries[i][1])%n;
    
    if (queries[i][0] == 1)
    {
      seqList[k].push_back(queries[i][2]);
    }
    else if(queries[i][0] == 2)
    {
      int index = queries[i][2] % (seqList[k].size());
      lastAns = seqList[k][index];
      res.push_back(lastAns);
    }
  }
  for(int i=0; i<seqList.size(); i++){
    for(int j=0; j<seqList[i].size(); j++){
      cout<<seqList[i][j]<<" ";
    }
    cout<<endl;
  }
  return res;
}

int main()
{
  // vector<vector<int>> seq = {{1,2},{3,4},{5,6}};
  // seq[0].push_back(10);
  // for(int i=0; i<3; i++){
  //   for(int j=0; j<seq[i].size(); j++)
  //     cout<<seq[i][j]<<" ";
  //   cout<<endl;
  // }
  vector<vector<int>> queries = {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
  vector<int> res = dynamicArray(2, queries);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  return 0;
}