//https://practice.geeksforgeeks.org/problems/jumping-numbers/0

#include<bits/stdc++.h>

using namespace std;

#define V vector
typedef long long LL;
typedef pair<int,int> pii;
typedef V<int> vi;
typedef V<pii> vpii;
#define rep(i,a) for(int i=0; i<(a); ++i)
#define loop(i,n,m) for(int i=n;i<=m;i++)
#define fov(i,a) rep(i,(a).size())
#define nl cout<<endl;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair


void func(int N)
{
  cout<<0<<" ";
  queue<int> q;
  loop(i,1,9)
  {
    q.push(i);

    while(!q.empty())
    {
      int temp = q.front();
      q.pop();
      if(temp<N)
      {
        cout<<temp<<" ";
        int right = temp%10;

        if(right == 0)
        {
          q.push(temp*10 + right+1);
        }

        if(right == 9)
        {
          q.push(temp*10 + right-1);
        }

        if(right>0 && right <9)
        {
            q.push(temp*10 + right-1);
            q.push(temp*10 + right+1);
        }

      }
    }
  }

}

int main()
{
  int T;
  cin>>T;

  while(T--)
  {
    int N;
    cin>>N;

      func(N);
  }

  return 0;
}
