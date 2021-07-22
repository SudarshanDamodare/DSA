#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set


struct MyStack{
  int *arr;
  int cap;
  int top; //here top is index of the array element and not pointer

  //constructor
  MyStack(int capacity){
    cap=capacity;
    arr = new int[cap];
    top=-1;
  }
  
  void push(int x){
    if(top==cap-1){
      cout<<"Stack overflow\n";
      return;
    }
    top++;
    arr[top]=x;
  }

  int pop(){
    if(top==-1){
      cout<<"Stack underflow\n";
      return INT_MIN;
    }
    int res=arr[top];
    top--;
    return res;
  }

  int peek(){
    if(top==-1){
      cout<<"Stack underflow\n";
      return INT_MIN;
    }
    return arr[top];
  }

  int size(){
    return top+1;
  }

  bool isEmpty(){
    return (top==-1);
  }
};


// Vector implementattion
struct StackVector{
  vector<int> v;

  void push(int x){
    v.pb(x);
  }

  int pop(){
    int res=v.back();
    v.pop_back();
    return res;
  }

  int size(){
    return v.size();
  }

  bool isEmpty(){
    return v.empty();
  }

  int peek(){
    return v.back();
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  

  return 0;
}