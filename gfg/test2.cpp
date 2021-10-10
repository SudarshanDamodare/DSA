#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

char grid[31][31];
int vis[31][31], dist[31][31];
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int n;
int sx,sy,ex,ey;

bool isValid(int x, int y){
  if(x<1 || x>n || y<1 || y>n)  return 0;
  if(vis[x][y] || grid[x][y]=='T')  return 0;
  
  return 1;
}

void path(int sX, int sY){
  queue<pair<int,int>> q;
  vis[sX][sY]=1;
  dist[sX][sY]=0;
  q.push({sX,sY});
  
  while(!q.empty()){
    int currX=q.front().first, currY=q.front().second;
    q.pop();

    for(int i=0;i<4;i++){
      int newX=currX+dx[i], newY=currY+dy[i];
      if(isValid(newX,newY)){
        dist[newX][newY]=dist[currX][currY]+1;
        vis[newX][newY]=1;
        if(newX==ex && newY==ey)  break;
        q.push({newX,newY});
      }
    }
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cin>>n;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++){
    cin>>grid[i][j];
    if(grid[i][j]=='S') sx=i,sy=j;
    if(grid[i][j]=='E') ex=i,ey=j;
  }
  
  path(sx,sy);
  cout<<dist[ex][ey]<<endl;
  
  return 0;
}