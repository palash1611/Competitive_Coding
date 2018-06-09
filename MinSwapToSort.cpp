//https://www.hackerrank.com/challenges/lilys-homework/forum
//https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define V vector
typedef V<int> vi;
typedef V<lli> vli;
typedef pair<int, int> pii;
typedef V<pii > vpii;
#define nl cout<<endl;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,n) for(lli i=0;i<n;i++)
#define loop(i,m,n) for(int i=m;i<=n;i++)
#define fov(i,a) for(int i=0;i<a.size();i++)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

int countSwap(vpii arr, int n)
{
  vector<bool> vis;
  int res=0;
  rep(i,n)
  vis.pb(false);

  rep(i,n)
  {
    if(vis[i] || arr[i].sc==i)
    continue;

    int j=i;
    int size=0;
    while(vis[j]!=true)
    {
      vis[j]=true;
      j=arr[j].sc;
      size++;
    }

   res = res + size-1;
  }
  return res;
}

int main()
{
  int n;
  cin>>n;
  int res=0;
  int res2=0;
  vpii arr,arr2;
  rep(i,n)
  {
    int temp;
    cin>>temp;
    arr.pb(mp(temp,i));
    arr2.pb(mp(temp,i));
  }

  sort(arr.begin(),arr.end());
  sort(arr2.rbegin(),arr2.rend()); //sorting in dec order

  res=countSwap(arr,n);
  res2=countSwap(arr2,n);
  cout<<min(res,res2);nl;
  return 0;
}
