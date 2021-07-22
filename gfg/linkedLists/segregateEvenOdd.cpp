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


// Segregate even and odd valued nodes
// Even nodes appear first followed by all odd
node *segregateEO(node* head){
  node *es=NULL,*os=NULL,*ee=NULL,*oe=NULL;
  for(node *curr=head; curr!=NULL; curr=curr->next){
    int x=curr->data;
    if(x%2==0){
      if(es==NULL){
        es=curr;
        ee=es;
      }
      else{
        ee->next=curr;
        ee=ee->next;
      }
    }
    else{
      if(os==NULL){
        os=curr;
        oe=os;
      }
      else{
        oe->next=curr;
        oe=oe->next;
      }
    }
  }

  if(os==NULL || es==NULL)
    return head;
  // cout<<es->data<<" "<<ee->data<<endl;
  // cout<<es->next->data<<" "<<es->next->data<<endl;
  // cout<<os->data<<" "<<oe->data<<endl;
  // cout<<os->next->data<<" "<<os->next->next->data<<endl;
  ee->next=os;
  oe->next=NULL;
  return es;
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head = NULL;
  insertAthead(head,1);
  insertAthead(head,2);
  insertAthead(head,3);
  insertAthead(head,4);
  insertAthead(head,5);
  insertAthead(head,6);
  insertAthead(head,7);
  displayLL(head);
  head=segregateEO(head);
  displayLL(head);

  return 0;
}