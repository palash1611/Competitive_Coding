#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node* next;
};


node* insertBeg(node* head,int n)
{

  node *newNode;
  newNode=new node;

  newNode->data=n;
  newNode->next = NULL;

  if(head==NULL)
  {
    head=newNode;
  }
  else
  {
    newNode->next=head;
    head=newNode;
  }
    return newNode;

}

node* insertend(node* head,int n)
{
  node *newNode;
  newNode=new node;

  newNode->data=n;
  newNode->next = NULL;

  node *temp=new node;
  temp=head;
  while(temp->next!=NULL)
  {
    //cout<<temp->data<<"\t";
    temp=temp->next;
  }

  temp->next=newNode;

  return head;

}

node* reverse(node* head)
{
  node *prev, *temp,*cur;

  prev=NULL;
  cur=head;
  while(cur!=NULL)
  {
    temp=cur->next;
    cur->next=prev;
    prev=cur;
    cur=temp;
  }
//  cur->next=prev;
  return prev;
}


void display(node* head)
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }


int main()
{

node *head =new (struct node);
head=NULL;

head = insertBeg(head,1);
head = insertBeg(head,2);
head = insertBeg(head,3);

head = insertend(head,10);
//cout<<head->next->data;
display(head);

head = reverse(head);
cout<<endl;
display(head);

  return 0;

}
