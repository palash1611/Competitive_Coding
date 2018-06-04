#include<bits/stdc++.h>
using namespace std;

int main()
{
  string arr="(()()(";
  stack<char> s;
  int l,r;
  cin>>l>>r;
  cout<<arr[0]<<endl;
  cout<<arr[1]<<endl;
  cout<<arr[2]<<endl;
  cout<<arr[3]<<endl;
  cout<<arr[4]<<endl;
  cout<<arr[5]<<endl;
  for(int i = l; i <=r ; i++)
  {

    if(arr[i]=='(')
    s.push(arr[i]);

    if(arr[i]==')' && !s.empty())
    s.pop();
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  if(s.empty())
  {
    cout<<l<<" "<<r<<" valid"<<endl;

  }
  else
  {cout<<l<<" "<<r<<" not valid hui hui"<<endl;
  }

  return 0;
}
