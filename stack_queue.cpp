#include<bits/stdc++.h>
using namespace std;

void show_stack(stack<int> st){

  stack <int> s=st;

  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}

void show_queue(queue<int> q){

  queue <int> s=q;

  while(!s.empty())
  {
    cout<<s.front()<<" ";
    s.pop();
  }
  cout<<endl;
}

int main()
{
  stack<int> st;
  queue<int> q;

  if(st.empty())
  cout<<"stack empty"<<endl;

  st.push(5);
  st.push(3);
  st.push(2);

  cout<<"printing stack"<<endl<<endl;
  show_stack(st);

  cout<<"top "<<st.top()<<endl;
  cout<<"poping"<<endl;
  st.pop();
  cout<<"top "<<st.top()<<endl;

  if(st.empty())
  cout<<"stack empty"<<endl;
  else cout<<"stack not empty"<<endl;
  cout<<"stack size "<<st.size()<<endl;

  cout<<"printing stack"<<endl<<endl;
  show_stack(st);

  cout<<endl;

  if(q.empty())
  cout<<"queue empty "<<endl;
  else cout<<" queue not empty"<<endl;

  q.push(1);
  q.push(2);
  q.push(3);

  show_queue(q);

  q.pop();
  q.pop();
  q.push(99);
  q.push(100);

  if(q.empty())
  cout<<"queue empty "<<endl;
  else cout<<" queue not empty"<<endl;

  show_queue(q);


  cout<<"queue front "<<q.front()<<endl;
  cout<<"queue back "<<q.back()<<endl;



  return 0;
}
