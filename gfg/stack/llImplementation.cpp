#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

class node{
  public:
  int data;
  node* next;

  node(int x){
    data=x;
    next=NULL;
  }
};

// Print LL
void displayLL(node* head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head=head->next;
  }
  cout<<"NULL"<<endl;
}

// Insert at head of LL
void insertAthead(node* &head, int x){
  node* temp = new node(x);
  temp->next=head;
  head=temp;
}

// Delete head of LL
int deleteHead(node* &head){
  if(head==NULL)
    return INT_MIN;
  node* todelete = head;
  int res=head->data;
  head=head->next;
  delete todelete;
  return res;
}

struct MyStack{
  node *head;
  int count;


  MyStack(){
    head=NULL;
    count=0;
    // displayLL(head);
  }

  void push(int x){
    insertAthead(head, x);
    count++;
    // displayLL(head);
  }

  int pop(){
    int res=deleteHead(head);
    count--;
    // displayLL(head);
    return res;
  }

  int size(){
    return count;
  }

  bool isEmpty(){
    // displayLL(head);
    return (head==NULL);
  }

  int peek(){
    // displayLL(head);
    if(!head)
      return INT_MIN;

    return head->data;
  }
};


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  MyStack s;
  s.push(5);
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  
  cout<<s.size()<<endl;
  cout<<s.pop()<<" ";
  cout<<s.pop()<<" ";
  cout<<s.pop()<<" ";
  cout<<s.pop()<<" ";
  cout<<s.pop()<<endl;
  cout<<s.size()<<endl;
  cout<<s.isEmpty()<<endl;
  cout<<s.peek()<<endl;
  return 0;
}