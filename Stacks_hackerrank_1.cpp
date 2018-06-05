#include<bits/stdc++.h>
#include<stack>
using namespace std;
/*
void find_max(stack<long long int> s)
{
  stack< long long int> st1,st2;
  st1=s;
  long long int max;
  st2.push(st1.top());
  st1.pop();
  while(!st1.empty())
  {
    if(st1.top()>st2.top())
      max=st1.top();
    else
      max=st2.top();

    st2.push(max);
    st1.pop();
  }

  cout<<st2.top()<<endl;

}

void show_stack(stack<long long int> st){

  stack <long long int> s=st;

  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}
*/
int main()
{
  stack<pair <long long int, long long int>> s;
  long long int n;
  int type;
  long long int value;
  long long int max;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>type;
    switch(type){

      case 1:{
                cin>>value;
                if(s.empty())
                    max=value;
                else if(s.top().second>value) max=s.top().second;
                else max=value;
                s.push(make_pair(value,max));
                break;

      }
      case 2: s.pop();
              break;
      case 3: pair<long long int,long long int> p=s.top();
              cout<<p.second<<endl;
              break;

    }

  }
  /*
  s.push(1);
  s.push(2);
  s.push(22);
  s.push(865);
  s.push(92);
  s.push(289);

  cout<<endl;
  show_stack(s);
  cout<<endl;
  find_max(s);*/
  return 0;
}
