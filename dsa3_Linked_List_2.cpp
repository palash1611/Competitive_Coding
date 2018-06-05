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

  node* insertEnd(node* head, int n)
  {
  node *temp, *newNode;
  temp =head;
  newNode = new node;
  newNode->data=n;
  newNode->next=NULL;

  while(temp->next!=NULL)
  {
    temp=temp->next;
  }

  temp->next=newNode;

  return head;



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

  node *newhead2 = new (struct node);
  newhead2= newhead;
  while(t2!=NULL)
  {
    if(!isPresent(head1,t2->data))
      { int n = t2->data;
        insertBeg(newhead2,n);
        cout<<t2->data<<endl;
      }
    t2=t2->next;
  }

  return newhead2;

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

  node* sortUnion(node* head1, node* head2)
  {
    node *result,*t1,*t2;
    result=new node;
    result=NULL;
    t1=head1;
    t2=head2;

    while(t1->next != NULL && t2->next!=NULL)
    {
      if(t1->data > t2->data)
      {
        if(!isPresent(result,t2->data))
        {
          result=insertEnd(result,t2->data);
          t2=t2->next;
        }
      }
      else if(t1->data < t2->data)
      {
          if(!isPresent(result,t1->data))
          {
            result=insertEnd(result,t1->data);
            t1=t1->next;
          }
      }
      else
      {
        t2=t2->next;
        t1=t1->next;
      }

    }

    if(t1->next==NULL)
    {
      while(t2->next!=NULL)
      {
        if(!isPresent(result,t2->data))
        result=insertEnd(result,t2->data);
        t2=t2->next;
      }
    }
    else
    {
      while(t1->next!=NULL)
      {
        if(!isPresent(result,t1->data))
        result=insertEnd(result,t1->data);
        t1=t1->next;
      }
    }

    return result;
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

  node *unionhead = new node;
  unionhead=NULL;

  unionhead=unionlist(head1,head2);

  cout<<endl<<"UNION"<<endl;

  display(unionhead);

  node *interhead = new node;
  interhead=NULL;

  interhead=commonlist(head1,head2);
  cout<<endl<<"Intersection"<<endl;

  display(interhead);

  cout<<endl;

 /*unionhead=sortUnion(head1,head2);

 cout<<endl<<"UNIONsort"<<endl;

 display(unionhead);

*/


  return 0;
}
