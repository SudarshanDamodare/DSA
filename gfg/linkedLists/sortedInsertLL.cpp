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


node *sortedInsert(node *head, int x){
  node *temp = new node(x);

  if(head==NULL)
    return temp;
  if(x<head->data){
    temp->next=head;
    return temp;
  }

  node *curr=head;
  while(curr->next!=NULL && curr->next->data<x)
    curr=curr->next;
  
  temp->next=curr->next;
  curr->next=temp;
  return head;
}

void displayLL(node* head){
  while(head!=NULL){
    cout<<head->data<<"->";
    head=head->next;
  }
  cout<<"NULL"<<endl;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node *head=NULL;
  head=sortedInsert(head,5);
  head=sortedInsert(head,1);
  head=sortedInsert(head,10);
  head=sortedInsert(head,5);
  displayLL(head);
  return 0;
}