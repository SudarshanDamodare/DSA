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


// Insert at End of LL
void insertAttail(node* &head, int x){
  node* n = new node(x);
  if(head == NULL){
    head = n;
    return;
  }
  node* temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;
}


// Insert at position 'pos' in LL
void insertAtPosition(node* &head, int pos, int x){
  node* n = new node(x);
  if(pos==1){
    n->next=head;
    head=n;
    return;
  }
  node* temp = head;
  for(int i=1;i<=pos-2 && temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp==NULL)
    return;
  n->next=temp->next;
  temp->next=n;
}


// Delete head of LL
void deleteHead(node* &head){
  if(head==NULL)
    return;
  node* todelete = head;
  head=head->next;
  delete todelete;
}


// Delete node with data=x from LL
void deleteNodeWithData(node* &head, int x){

  if(head==NULL)
    return;
  
  if(head->next==NULL){
    deleteHead(head);
    return;
  }

  node* temp = head;
  while(temp->next->data!=x){
    temp=temp->next;
  }
  node* toDelete=temp->next;
  temp->next=temp->next->next;
  delete toDelete;
}


// Delete node with given position
node *deleteKthNode(node *head, int pos){
  if(head==NULL)
    return head;
  if(pos==1){
    node *temp=head->next;
    delete head;
    return temp;
  }

  node *curr=head;
  for(int i=1;i<=pos-2 && curr!=NULL; i++){
    curr=curr->next;
  }
  //this check the curr pos and the req pos
  if(curr==NULL || curr->next==NULL)
    return head;
  
  node *temp=curr->next;
  curr->next=curr->next->next;
  delete temp;
  return head;
}


// Delete tail of LL
void deleteTail(node* &head){
  if(head==NULL)
    return;
  if(head->next==NULL){
    deleteHead(head);
    return;
  }

  node* temp = head;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  node* todelete = temp->next;
  temp->next=NULL;
  delete todelete;
}


//find middle of linked list
void printMiddle(node *head){
  if(head==NULL)
    return;
  
  node *slow=head,*fast=head;
  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<slow->data<<endl;
}


//print Nth node from end of LL
void printNthEnd(node *head, int n){
  if(head==NULL)
    return;
  node *first=head;
  for(int i=0;i<n;i++){
    if(first==NULL)
      return;
    first=first->next;
  }

  node *second=head;
  while(first!=NULL){
    second=second->next;
    first=first->next;
  }
  cout<<second->data<<endl;
}


// Insert the element in sorted order in LL
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


// reverse whole LL
node *reverseLL(node *head){
  node *curr=head,*prev=NULL,*next;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  delete next;
  delete curr;
  return prev;
}


// remove duplicates from the sorted LL
void removeDuplicates(node *head){
  node *curr=head;
  while(curr!=NULL && curr->next!=NULL){
    if(curr->data==curr->next->data){
      node *temp=curr->next;
      curr->next=curr->next->next;
      delete temp;
    }
    else
      curr=curr->next;
  }
}


//reverse LL in groups of k nodes
node *reverseInK(node *head, int k){
  node *curr=head, *prevFirst=NULL;
  bool isFirstPass=true;

  while(curr!=NULL){
    // cout<<"pass\n";
    node *first=curr, *prev=NULL;
    int count=0;

    while(curr!=NULL && count<k){
      // cout<<"reversing\t"<<curr->data<<endl;
      node *next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
      count++;
    }

    if(isFirstPass){
      head=prev;
      isFirstPass=false;
    }
    else{
      prevFirst->next=prev; //this is to join the list
      // cout<<prevFirst->next->data<<endl;
    }

    prevFirst=first;
  }
  return head;
}


// Pairwise swap nodes of LL
// 1. Swapping data
void pairSwap(node *head){
  node *curr=head;
  while(curr && curr->next){
    // swap 1st and second
   swap(curr->data, curr->next->data);

    curr=curr->next->next;
  }
}

// 2. Swapping pointers
node *pairSwap2(node *head){
  if(!head || !head->next)
    return NULL;
  
  node *curr=head->next->next;
  node *prev=head;
  head=head->next;
  head->next=prev;

  // this will swap other pairs after 1st pair
  while(curr && curr->next){
    // curr and curr->next will be swapped
    prev->next = curr->next;
    prev = curr;
    node *next = curr->next->next;
    curr->next->next = curr;
    curr = next;
  }
  prev->next=curr;
  return head;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head = NULL;
  head=sortedInsert(head,1);
  head=sortedInsert(head,2);
  head=sortedInsert(head,3);
  head=sortedInsert(head,4);
  head=sortedInsert(head,20);
  displayLL(head);
  // insertAtPosition(head,6,100);
  // head=deleteKthNode(head, 7);
  pairSwap(head);
  displayLL(head);
  return 0;
}