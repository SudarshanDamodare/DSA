#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// here we do the opposite we check from each lake max where the water can reach

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

bool isValid(int x, int y, int n, int m){
  if(x<0 || y<0 || x>=n || y>=m)  return false;
  return true;
}

void dfs(int x, int y, vector<vector<int> > &A, vector<vector<int> > &vis){
  vis[x][y]=1;

  for(int i=0;i<4;i++){
    int nx=x+dx[i], ny=y+dy[i];

    if(isValid(nx,ny,A.size(),A[0].size())){
      if(A[nx][ny]>=A[x][y] && !vis[nx][ny])  dfs(nx,ny,A,vis);
    }
  }
}

int solve(vector<vector<int> > &A){
  int n=A.size(), m=A[0].size();
  cout<<n<<" "<<m<<endl;
  vector<vector<int>> red(n,vector<int>(m,0)), blue(n,vector<int>(m,0));
  
  for(int i=0;i<m;i++){
    if(!red[0][i])  {dfs(0,i,A,red);}
    if(!blue[n-1][i]) dfs(n-1,i,A,blue);
  }
  for(int j=0;j<n;j++){
    if(!red[j][0])  dfs(j,0,A,red);
    if(!blue[j][m-1]) dfs(j,m-1,A,blue);
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)  cout<<red[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)  cout<<blue[i][j]<<" ";
    cout<<endl;
  }

  int cnt=0;
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)  if(red[i][j]==1 && blue[i][j]==1) cnt++;

  return cnt;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  int n,m;
  cin>>n>>m;

  vector<vector<int> > A(n,vector<int>(m));
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)  cin>>A[i][j];

  cout<<solve(A)<<endl;

  return 0;
}