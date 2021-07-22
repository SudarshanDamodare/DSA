#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define us unordered_set

class node {
  public:
  int data;
  node* next;
  node(int val){
    data=val;
    next=NULL;
  }
};


// void displayLL(node* head){
//   if(head==NULL)
//     return;
//   cout<<head->data<<" ";
//   for(node* p=head->next; p!=head; p=p->next){
//     cout<<p->data<<" ";
//   }
//   cout<<"\n";
// }

void displayLL(node* head){
  if(head==NULL)
    return;
  node* p=head;
  do{
    cout<<p->data<<" ";
    p=p->next;
  }while(p!=head);
  cout<<endl;
}

node* insertBegin(node* head, int data){
  node* temp = new node(data);
  if(head==NULL){
    temp->next=temp;
    return temp;
  }
  else{
    temp->next=head->next;
    head->next=temp;
    int t=head->data;
    head->data=temp->data;
    temp->data=t;
    return head;
  }
}

node* insertEnd(node* head, int data){
  node* temp = new node(data);
  if(head==NULL){
    temp->next=temp;
    return temp;
  }
  else{
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    // head = head->next;
    // return head;
    return temp;
  }
}

node* deleteHead(node* head){
  if(head==NULL)
    return head;
  if(head->next==head){
    delete head;
    return NULL;
  }
  else{
    //copy head's next's data to head and then delete head's next
    node* temp = head->next;
    
    head->data=head->next->data;
    
    head->next=head->next->next;
    delete temp;
    return head;
  }
}

node *deleteKth(node *head, int k)
{
  if(head==NULL)
    return head;
    
  if(k==1){
    return deleteHead(head);
  }
  node *curr = head;
  for (int i = 0; i < k - 2; i++){
    curr = curr->next;
    //this condition checks if we are exceeding the length of list
    if(curr->next==head)
      return head;
  }
  

  // now curr is pointing the node before the required node i.e (k-1)th node
  node *temp = curr->next;
  curr->next = curr->next->next;
  delete temp;
  return head;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head=NULL;
  head=insertBegin(head,10);
  head=insertBegin(head,20);
  head=insertBegin(head,30);
  displayLL(head);
  head=insertBegin(head, 50);
  displayLL(head);
  head=insertEnd(head,100);
  displayLL(head);
  head=deleteHead(head);
  displayLL(head);
  head=deleteKth(head,20);
  displayLL(head);

  return 0;
}