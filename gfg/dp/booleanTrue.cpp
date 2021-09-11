#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define um unordered_map

// return no. of ways in which the given expression can be evaluated True

// recursive
int solve(string s, int l, int r, bool isTrue){

  if(l>r)
    return false;
  if(l==r){
    if(isTrue)
      return s[l]=='T';
    else
      return s[l]=='F';
  }

  int res=0;
  for(int k=l+1;k<r;k+=2){
    int lT=solve(s,l,k-1,1);
    int lF=solve(s,l,k-1,0);
    int rT=solve(s,k+1,r,1);
    int rF=solve(s,k+1,r,0);

    // cout<<lT<<" "<<lF<<" "<<rT<<" "<<rF<<endl;

    if(s[k]=='&'){
      if(isTrue)
        res+=lT*rT;
      else
        res+= lF*rT + lT*rF + lF*rF;
    }

    else if(s[k]=='|'){
      if(isTrue)
        res+= lF*rT + lT*rF + lT*rT;
      else
        res+=lF*rF;
    }

    else{
      if(isTrue)
        res+=lT*rF + lF*rT;
      else
        res+=lT*rT + lF*rF;
    }

  }

  return res;
}

int booleanTrue(string s){
  return solve(s, 0, s.size()-1, true);
}


// Memoisation 
um<string, int> m;

int trueRec(string s, int l, int r, bool isTrue){

  if(l>r)
    return false;
  if(l==r){
    if(isTrue)
      return s[l]=='T';
    else
      return s[l]=='F';
  }

  string key=to_string(l)+'*'+to_string(r)+'*'+to_string(isTrue);
  // cout<<key<<endl;

  if(m.find(key)!=m.end())
    return m[key];


  m[key]=0;
  for(int k=l+1;k<r;k+=2){
    // cout<<k<<endl;
    int lT=solve(s,l,k-1,1);
    int lF=solve(s,l,k-1,0);
    int rT=solve(s,k+1,r,1);
    int rF=solve(s,k+1,r,0);

    // cout<<lT<<" "<<lF<<" "<<rT<<" "<<rF<<endl;

    if(s[k]=='&'){
      if(isTrue)
        m[key]+=lT*rT;
      else
        m[key]+= lF*rT + lT*rF + lF*rF;
    }

    else if(s[k]=='|'){
      if(isTrue)
        m[key]+= lF*rT + lT*rF + lT*rT;
      else
        m[key]+=lF*rF;
    }

    else{
      if(isTrue)
        m[key]+=lT*rF + lF*rT;
      else
        m[key]+=lT*rT + lF*rF;
    }

  }

  return m[key];
}

int boolTrue(string s){
  m.clear();
  return trueRec(s, 0, s.size()-1, true);
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  string s="T^F&T";
  cout<<booleanTrue(s)<<endl;
  cout<<boolTrue(s)<<endl;
  // cout<<m.size()<<endl;
  
  return 0;
}