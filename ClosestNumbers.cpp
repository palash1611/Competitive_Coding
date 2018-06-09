//https://www.hackerrank.com/challenges/closest-numbers/problem

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define V vector
typedef V<int> vi;
typedef V<lli> vli;
typedef pair<int, int> pii;
typedef V<pii> vpii;
#define nl cout<<endl;

#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,n) for(lli i=0;i<n;i++)
#define loop(i,m,n) for(int i=m;i<=n;i++)
#define fov(i,a) for(int i=0;i<a.size();i++)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second


int main()
{
  lli n;
  cin>>n;

  vli arr;
  repl(i,n)
  {
    lli temp;
    cin>>temp;
    arr.pb(temp);
  }

  sort(arr.begin(),arr.end());


  lli dif = abs(arr[1]-arr[0]);

  loop(i,1,n-1)
  {
    if(abs(arr[i+1]-arr[i])<dif)
    dif=abs(arr[i+1]-arr[i]);
    //cout<<" - "<<dif;nl;
  }
//  cout<<dif;nl;

  rep(i,n)
  {
    if(abs(arr[i+1]-arr[i])==dif)
    cout<<arr[i]<<" "<<arr[i+1]<<" ";
  }


  return 0;
}
