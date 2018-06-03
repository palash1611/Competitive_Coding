//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0#ExpectOP
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

void func(vector<int> arr, int N, int S)
{
  int l=-1,r=-1;
  int s=0,flag=0;

  rep(i,N)
  {
    l=i;
    //cout<<" l = "<<l;nl;
    s=arr[i];
  //  cout<<" ss = "<<s;nl;
    for(int j=i+1;j<N;j++)
    {
      s=s+arr[j];
      //cout<<" S = "<<s;nl;

      if(s==S)
      {
        r=j;
        flag=1;
        break;
      }


      if(s>S)
      break;
    }
    if(flag==1)
    break;
  }

  if(flag==0)
  cout<<-1<<endl;
  else
      cout<<l+1<<" "<<r+1<<endl;

}

int main()
{
  int T;
  cin >>T;

  rep(i,T)
  {
    int N,S;
    cin>>N>>S;

    vi arr;
    rep(j,N)
    {
      int temp;
      cin>>temp;
      arr.pb(temp);
    }

    func(arr,N,S);

  }


  return 0;
}
