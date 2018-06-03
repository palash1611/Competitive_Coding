//https://www.codechef.com/JUNE18B/problems/NAICHEF
#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vll;
typedef V<double> vd;
typedef V<pii> vpii;

#define rep(i,a) for(int i=0; i<(a); ++i)
#define fov(i,a) rep(i,(a).size())
#define nl cout<<endl;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair


int main()
{
  int T;
  cin>>T;

  rep(i,T)
  {
    int N,A,B;
    cin>>N>>A>>B;
    vi arr;
    rep(j,N)
    {
      int temp;
      cin>>temp;
      arr.pb(temp);
    }

    int a=0;
    int b=0;
    rep(j,N)
    {
      if(arr[j]==A)
      a++;
      if(arr[j]==B)
      b++;
    }
    float res;
    res=(float)((float)(a*b)/(float)(N*N));
    cout<<res;nl
  }

  return 0;
}
