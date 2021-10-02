#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

/*
The schools in Berland have always been unorthodox and do not consider giving grades in the alphabetical order rather they believe in an ancient text written in the temples of Maluma. This text consists of 26 distinct lower case alphabets where each alphabet has higher priority than it’s successors in the string.
Mr. Garatskovich has always been very generous towards his hardworking students so he decided to give a present to the topper of the class but he is in a dilemma as he currently has no idea who has the best scores among all. Can you help Mr gary to find the apple of his eye.
The top scorer is decided on the basis of rounds where each student promotes one of his grades in any subject for that round, students  having highest ranked grade are considered for further rounds eliminating the rest. (A student can select a grade for 1 round only)
Input type-
First line: a string of length 26 describing the sacred ancient text
Second line: n, where n being the total number of students.
This is followed by n strings of arbitrary lengths where each character represents a grade in any one of the subjects that he opted for.
Output-
Print the index of the highest scorer
Ex-
marlfsudktzieyvowhcgxbpjnq

4
aap		aap
mmxyp		mmyxp
mmm		mmm
mma		mma
Answer-
3
 
 n<=1e5,
Sum[ modSi ]<=1e6=m


*/

string maxi="";
vector<int> m(26,0);

void setCount(string s, vector<int> &cc){
  for(int i=0;i<s.size();i++) {
    cc[s[i]-97]++;
  }
}

bool myComp(string s,vector<int> &cc, string rank){
  for(int i=0;i<26;i++){
    if(cc[rank[i]-97]==0 && m[rank[i]-97]==0) continue;
    else if(cc[rank[i]-97]==m[rank[i]-97])  continue;
    else if(cc[rank[i]-97]>m[rank[i]-97]) return true;
    else  return false;
  }

  return false;
}

int main(){

  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif


  string rank;  cin>>rank;


  int n; cin>>n;
  vector<string> students;

  for(int i=0;i<n;i++){
    string s; cin>>s;
    students.push_back(s);
  }

  maxi=students[0];
  setCount(maxi, m);
  
  for(int i=1;i<n;i++){
    vector<int> cc(26,0);
    setCount(students[i],cc);

    if(myComp(students[i],cc,rank)){
      maxi=students[i], m=cc;
    }
  }


  for(int i=0;i<n;i++){
    if(students[i]==maxi) {cout<<i+1<<endl; break;}
  }

  return 0;
}