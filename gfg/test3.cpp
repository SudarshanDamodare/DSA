#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map


int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int cnt=0;

bool isValid(int x, int y){
  if(x>0 && x<=8 && y>0 && y<=8)  return true;
  return false;
}

void bfs(int n, int start[][2], vector<vector<int>> &vis){
  queue<pair<int,int>> q;
  for(int i=0;i<n;i++){
    q.push({start[i][0],start[i][1]});
    vis[start[i][0]][start[i][1]]=1;
    // cnt++;
  }

  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    cnt++;

    for(int i=0;i<4;i++){
      int nx=x+dx[i], ny=y+dy[i];
      if(isValid(nx,ny) && !vis[nx][ny]){
        q.push({nx,ny});
        vis[nx][ny]=1;
        // cnt++;
      }
    }
  }
}

int solve(int n, int start[][2]){
  vector<vector<int>> vis(9,vector<int>(9,0));
  bfs(n,start,vis);

  return cnt;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  int n;
  cin>>n;
  int start[n][2];
  for(int i=0;i<n;i++){
    cin>>start[i][0];
    cin>>start[i][1];
  }

  cout<<solve(n,start);

  return 0;
}