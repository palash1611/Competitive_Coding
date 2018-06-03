//https://www.hackerrank.com/contests/bitsgintp1/challenges/diagonal-difference

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
int n;
// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> a,int n) {
    int sum1=0,sum2=0;



    rep(i,n)
    {
      //cout<<a[i][i]<<" ";
      sum1+=a[i][i];
    }
    //nl;
    rep(i,n)
    {
      //cout<<a[i][n-i-1]<<" ";
      sum2+=a[i][n-i-1];
    }
    //nl;
  //  cout<<abs(sum1-sum2);
    return abs(sum1-sum2);
}

int main()
{


    int n;
    cin >> n;


    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }


    int result = diagonalDifference(a,n);

    cout << result << "\n";



    return 0;
}
