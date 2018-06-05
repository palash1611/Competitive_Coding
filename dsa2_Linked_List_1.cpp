#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node* next;
} *head,*temp;

node* createNode(int n)
{
  node *newNode;
  newNode=new node;

  newNode->data=n;
  newNode->next = NULL;

  return newNode;
}

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

  bool isPresent (node* head, int data)
  {
      node *t =new node;
      t = head;
      while (t != NULL)
      {
          if (t->data == data)
              return true;
          t = t->next;
      }
      return false;
  }

  node* unionlist (node* head1,node* head2)
  {
    node *newhead = new (struct node);
    newhead= NULL;
    node *t1, *t2;
    t1=head1;
    t2=head2;

      while(t1!=NULL)
      {
        newhead=insertBeg(newhead,t1->data);
        t1=t1->next;
      }

      while(t2!=NULL)
      {
        if(!isPresent(head1,t2->data))
          insertBeg(newhead,t2->data);
        t2=t2->next;
      }

      return newhead;

  }


  node* commonlist (node* head1, node* head2)
  {
    node *newhead = new (struct node);
    newhead= NULL;
    node *t1, *t2;
    t1=head1;
    t2=head2;

    while(t1!=NULL)
    {
      if(isPresent(head2,t1->data))
        insertBeg(newhead,t1->data);
      t1=t1->next;
    }

    return newhead;
  }


int main()
{
  node *head1 = new (struct node);
  head1= NULL;
  node *head2 = new (struct node);
  head2= NULL;

  int n;
  cin>>n;
  while(n>0)
  {
    int n1;
    cin>>n1;
    head1 = insertBeg(head1,n1);
    n--;
  }
int n2;
  cin>>n2;

  while(n2>0)
  {
    int n3;
    cin>>n3;
    head2 = insertBeg(head2,n3);
    n2--;
  }

  display(head1);
  cout<<endl;
  display(head2);
  cout<<endl;
  if(isPresent(head1,3))
  cout<<"y";
  else cout<<"n";

  /*node *unionhead = new node;
  unionhead=NULL;

  unionhead=unionlist(head1,head2);

  cout<<endl;

  display(unionhead);

  node *interhead = new node;
  interhead=NULL;

  interhead=commonlist(head1,head2);
  cout<<endl;

  display(interhead);*/

  return 0;
}
