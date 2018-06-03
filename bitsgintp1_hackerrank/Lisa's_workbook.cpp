//https://www.hackerrank.com/contests/bitsgintp1/challenges/lisa-workbook
#include <bits/stdc++.h>

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

// Complete the workbook function below.
int workbook(int n, int k, vector<int> arr) {

  int page =0;
  int res=0;
  int temp=k;
  rep(i,n)
  {
    temp=k;
    page++;
    for(int j=1;j<=arr[i];j++)
    {
      if(temp==0)
      {
        temp=k;
        page++;
      }
      if(page==j)
      res++;
      temp--;

    }
  }
  //cout<<res;
  return res;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {


        cin>>arr[i];
    }

    int result = workbook(n, k, arr);

    cout << result << "\n";



    return 0;
}
