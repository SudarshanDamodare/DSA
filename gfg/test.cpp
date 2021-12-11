#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define us unordered_set
#define um unordered_map

/*


*/

int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  string s;
  cin>>s;

  int n=s.size();

  int start=0, end=n-1;

  while(start<end){

    char temp=s[start];
    s[start]=s[end];
    s[end]=temp;

    start++, end--;
  }

  cout<<s<<endl;

  return 0;
}