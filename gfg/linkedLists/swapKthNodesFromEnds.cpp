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


//here n is the length of LL
node *swapKth(node *head, int K, int n){

  //check valid k
    if(n<K){
        return head;
    }
    
    //check if kth node from start and kth from end are same
    if(2*K-1==n){
        return head;
    }
    
    //get kth node from start and its prev
    node *x=head, *x_prev=NULL;
    for(int i=1;i<K;i++){
        x_prev=x;
        x=x->next;
    }
    
    //get kth node from end and its prev
    node *y=head, *y_prev=NULL;
    for(int i=1;i<n-K+1;i++){
        y_prev=y;
        y=y->next;
    }
    
    // swapping prev pointer of x and y
    if(x_prev){
        x_prev->next=y;
    }
    if(y_prev){
        y_prev->next=x;
    }
    
    //swapping next of x and y
    node *temp=x->next;
    x->next=y->next;
    y->next=temp;
    
    //change head if K==1 or K==length
    if(K==1){
        head=y;
    }
    if(K==n){
        head=x;
    }
    
    return head;

  
}


int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  node* head = NULL;

  return 0;
}