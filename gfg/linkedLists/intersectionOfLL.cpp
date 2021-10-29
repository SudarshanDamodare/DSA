#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define us unordered_set
#define nn(x) new Node(x)

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

// find the intersection of two LL

// method 1
node* getNode(node *head1, node* head2){
  node *curr1=head1, *curr2=head2;
  int c1=0, c2=0;
  while(curr1 || curr2){
    if(curr1){
      c1++, curr1=curr1->next;
    }
    if(curr2){
      c2++, curr2=curr2->next;
    }
  }

  curr1=head1, curr2=head2;
  if(c1>c2){
    for(int i=0;i<c1-c2;i++)  curr1=curr1->next;
  }
  if(c2>c1)
    for(int i=0;i<c2-c2;i++)  curr2=curr2->next;

  while(curr1 != curr2){
    curr1=curr1->next, curr2=curr2->next;
  }

  return curr1;
}


// method 2
node* getIntersection(node *head1, node *head2){
  if(!head1 || !head2)  return NULL;
  node *d1=head1, *d2=head2;

  while(d1 != d2){
    d1 = (d1==NULL) ? head2 : d1->next;
    d2 = (d2==NULL) ? head1 : d2->next;
  }

  return d1;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
  #endif

  
  
  return 0;
}