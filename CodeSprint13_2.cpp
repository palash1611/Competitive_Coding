//https://www.hackerrank.com/contests/world-codesprint-13/challenges/watsons-love-for-arrays
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
#define ll long long
#define rep(i,a) for(int i=0; i<(a); ++i)
#define fov(i,a) rep(i,(a).size())
#define nl cout<<endl;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair

using namespace std;



// Complete the howManyGoodSubarrays function below.
long howManyGoodSubarrays(vll A, int m, int k) {
    // Return the number of good subarrays of A.
    long res=0;
    int temp;
    for(ll i=0;i<A.size();i++)
    {
      temp=A[i];
      if(temp%m==k)res++;

      for(int j=i+1;j<A.size();j++)
      {
        temp*=A[j];
        if(temp%m==k)res++;
      }
    }
    return res;
}

int main()
{

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ll n,m,k;
        cin>>n>>m>>k;

        vll arr;
        rep(i,n)
        {
          ll temp;
          cin>>temp;
          arr.pb(temp);
        }

        long result = howManyGoodSubarrays(arr, m, k);

        cout << result << "\n";

    }
    return 0;
}
