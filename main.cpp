#include <iostream>
using namespace std;

class node{
  public:
    int data ;
    node* next ;

    node(){
      this->data=0;
      this->next=NULL;    
    }

    node(int data){
      this->data=data;
      this->next=NULL;
    }
};

void print(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

int len(node* head){
  node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}

void inseartathead(node* &head,node* &tail,int data){
  if(head==NULL){
      node* newnode=new node(data);
      head=newnode;
      tail=newnode;
      return;
  }
     node* newnode=new node(data);
     newnode->next=head;
     head=newnode;
}

void inseartattail(node* &head,node* &tail,int data){
  if(tail==NULL){
      node* newnode=new node(data);
      head=newnode;
      tail=newnode;
      return;
  }
  node* newnode=new node(data);
  tail->next=newnode;
  tail=newnode;
}

void inseartatposition(node* &head,node* &tail,int data,int position){
    if(tail==NULL){
      node* newnode=new node(data);
      head=newnode;
      tail=newnode;
      return;
  }
  if(position<=1){
    inseartathead(head,tail,data);
    return;
  }
  int length=len(head);
  if(position>=length){
    inseartattail(head,tail,data);
    return;
  }
  int i=1;
  node* prev=head;
  while(i<position){
    prev=prev->next;
    i++;
  }
  node* newnode=new node(data);
  newnode->next=prev->next;
  prev->next=newnode;
}

int main() {
  node* head=NULL;
  node* tail=NULL;
  inseartathead(head,tail,0);
  inseartattail(head,tail,1);
  inseartattail(head,tail,2);
  inseartattail(head,tail,3);
  inseartattail(head,tail,4);
  inseartattail(head,tail,5);
  inseartattail(head,tail,6);
  inseartatposition(head,tail,9,2);
  print(head);

}