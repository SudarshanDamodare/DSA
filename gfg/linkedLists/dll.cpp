#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

// Doubly LinkedLists

class node{
  public:
  int data;
  node* next;
  node* prev;
  node(int val){
    data=val;
    next=prev=NULL;
  }
};

void displayLL(node* head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head=head->next;
  }
  cout<<"NULL"<<endl;
}

node* insertBegin(node* head, int data){
  node* temp = new node(data);
  temp->next=head;
  if(head!=NULL){
    head->prev=temp;
  }
  return temp;
}

node* insertEnd(node* head, int data){
  node* temp = new node(data);
  if(head==NULL)
    return temp;
  
  node* curr=head;
  while(curr->next!=NULL)
    curr=curr->next;
  
  curr->next=temp;
  temp->prev=curr;
  return head;
}

node* reversell(node* head){
  if(head==NULL || head->next==NULL)
    return head;
  node* curr=head;
  node* prev=NULL;
  while(curr!=NULL){
    prev=curr->prev;
    curr->prev=curr->next;
    curr->next=prev;
    curr=curr->prev;
  }
  return prev->prev;
}

node* deleteHead(node* head){
  if(head==NULL)
    return head;
  else if(head->next==NULL){
    delete head;
    return NULL;
  }
  else{
    node* temp = head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
  }
}

node* deleteLast(node* head){
  if(head==NULL)
    return head;
  if(head->next==NULL){
    delete head;
    return NULL;
  }
  node* curr = head;
  while(curr->next!=NULL)
    curr=curr->next;
  curr->prev->next=NULL;
  delete curr;
  return head;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head = NULL;
  head = insertBegin(head, 10);
  head = insertEnd(head,20);
  head = insertEnd(head,30);
  head = insertEnd(head,40);
  displayLL(head);
  head = deleteHead(head);
  head=deleteLast(head);
  displayLL(head);
  
  return 0;
}