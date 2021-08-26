#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map


struct Item{
  int productId;
  int quantity;
  int price;
};

int solution(struct Item shoplist[], int m){
  if(m==0)
    return -1;
  int res=0;

  for(int i=0;i<m;i++){
    res+=(shoplist[i].quantity*shoplist[i].price);
  }
  return res;
}

int getSum(int a){
  int res=0;
  while(a){
    res+=a%10;
    a=a/10;
  }
  return res;
}

int getPrime(int a, int b, int n){
  int i,j,flag;
  int res=0;

  for(i=a;i<=b;i++){
    if(i==0 || i==1)
      continue;
    
    flag=1;

    for(j=2;j<=i/2;j++){
      if(i%j==0){
        flag=0;
        break;
      }
    }

    if(flag==1){
      if(getSum(i)%n==0)
        res++;
    }
  }

  return res;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  cout<<getPrime(1,15,2);
  return 0;
}