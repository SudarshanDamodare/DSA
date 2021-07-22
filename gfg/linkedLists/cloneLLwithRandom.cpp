#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

class node{
  public:
  int data;
  node* next;
  node *arb;

  node(int x){
    data=x;
    next=NULL;
    arb=NULL;
  }
};

void insertAthead(node* &head, int x){
  node* temp = new node(x);
  temp->next=head;
  head=temp;
}

void insertAttail(node* head, int x){
  node* n = new node(x);
  if(head == NULL){
    insertAthead(head, x);
    return;
  }
  while(head->next!=NULL){
    head=head->next;
  }
  head->next=n;
}

void displayLL(node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

void deleteHead(node* &head){
  if(head==NULL)
    return;
  head=head->next;
}

void deleteTail(node* head){
  while(head->next->next!=NULL){
    head=head->next;
  }
  head->next=NULL;
}

node *copyList(node *head) {
    
    node *curr=head;
    while(curr){
        node *next=curr->next;
        curr->next=new node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    for(curr=head; curr!=NULL; curr=curr->next->next){
        curr->next->arb=(curr->arb)?curr->arb->next:NULL;
    }
    node *original=head,*copy=head->next,*newHead;
    newHead=copy;
    while(original && copy){
        original->next=(original->next)?original->next->next:original->next;
        copy->next=(copy->next)?copy->next->next:copy->next;
        original=original->next;
        copy=copy->next;
    }
    return newHead;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head = NULL;

  return 0;
}