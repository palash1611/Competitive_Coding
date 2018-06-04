//https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0
#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vll;
typedef V<LD> vld;
typedef V<pii> vpii;

#define rep(i,n) for(int i=0;i<n;i++)
#define fov(i,a) for(int i=0;i<a.size();i++)
#define nl cout<<endl;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

bool validString(string arr, int l, int r)
{
  //cout<<"checking "<<l<<" "<<r<<endl;
  stack<char> s;
  int flag=0;
  for(int i = l; i <=r ; i++)
  {
    if(arr[i]=='(')
    s.push(arr[i]);
    if(arr[i]==')')
    {
      if(s.empty())
      {
        flag=1;
        break;
      }
      else
      s.pop();
    }

  //  cout<<arr[i]<<" ";
  }
  //nl;

  if(s.empty() && arr[l]!=')' && flag==0)
  {
    //cout<<l<<" "<<r<<" valid"<<endl;
    return true;
  }
  else
  {//cout<<l<<" "<<r<<" not valid .."<<endl;
  return false;}
}

int main()
{

int T;
cin>>T;

while(T>0)
{
  string s;
  cin>>s;


  int n = s.length();

  int i,j;
  i=0;j=n-1;

  queue<pair<int, int > > q;
  q.push(mp(i,j));
  map< pair<int, int> , int > m;
  int flag=0;
  while(!q.empty())
  {

    int u = q.front().first;
		int v = q.front().second;
		q.pop();

    if(validString(s,u,v))
    {
      cout<<v-u+1<<endl;
      flag=1;
      break;
    }
  //  else cout<<u<<" "<<v<<" not valid"<<endl;
    if(v-u>0)
    {
      if(m[mp(u+1,v)]==0)
      {
        m[mp(u+1,v)]=1;
        q.push(mp(u+1,v));
      }
      if(m[mp(u,v-1)]==0)
      {
        m[mp(u,v-1)]=1;
        q.push(mp(u,v-1));
      }

    }


  }

  if(flag==0)
  cout<<0<<endl;

  T--;
}


  return 0;
}
