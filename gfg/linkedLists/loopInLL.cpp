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

void insertAthead(node* &head, int x){
  node* temp = new node(x);
  temp->next=head;
  head=temp;
}

void insertAttail(node* &head, int x){
  node* n = new node(x);
  n->next=head->next; //this is to add loop
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


// Detect Loop in LL
void detectLoop(node *head){
  us <node*> h;
  node *curr=head;
  while(curr!=NULL){
    if(h.find(curr)!=h.end()){
      cout<<"YES\n";
      // cout<<*h.find(curr->next);
      return;
    }
    h.insert(curr);
    curr=curr->next;
  }
  cout<<"NO\n";
}


// Floyd's Cycle Detection
bool floydsCycle(node *head){
  node *slow=head, *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
      return true;
  }
  return false;
}


// Dtetct and remove Loop
void detectAndRemove(node *head){
  node *slow=head, *fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)
      break;
  }
  if(slow!=fast)
    return;
  
  slow=head;
  //This condition is used when slow and fast meet at head of LL
  if(slow==fast){
    while(fast->next!=slow)
      fast=fast->next;
    fast->next=NULL;
    return;
  }
  while(slow->next!=fast->next){
    slow=slow->next;
    fast=fast->next;
  }
  fast->next=NULL;
}


// Find the length of the Loop
int lengthOfLoop(node *head){
  node *slow = head, *fast = head;
  while (fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  if (slow != fast)
    return 0;

  int count = 0;
  do{
    count++;
    slow = slow->next;
  } while (slow != fast);
  return count;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node *head=NULL;
  // insertAthead(head,5);
  // insertAthead(head,4);
  // insertAthead(head,3);
  insertAthead(head,2);
  insertAthead(head,1);
  insertAttail(head,10);
  cout<<head->next<<endl;
  // cout<<head->data<<" "<<head->next->data<<" "<<head->next->next;
  // detectLoop(head);
  (floydsCycle(head)) ? cout<<"YES\n" : cout<<"NO\n";
  // detectAndRemove(head);
  // (floydsCycle(head)) ? cout<<"YES\n" : cout<<"NO\n";
  // displayLL(head);
  cout<<lengthOfLoop(head);
  return 0;
}