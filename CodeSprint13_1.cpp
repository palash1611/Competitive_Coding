//https://www.hackerrank.com/contests/world-codesprint-13/challenges/find-the-absent-students

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

//vector<string> split_string(string);

// Complete the findTheAbsentStudents function below.
void func(int n, vi a) {
// Return the list of student IDs of the missing students in increasing order.

  //int arr[n+1]={0};
  vi stu;
  rep(i,n+1)
  {
    stu.pb(0);
  }
  rep(i,n+1)
  {
    if(stu[a[i]]!=1)
    stu[a[i]]=1;
  }

  for(int i=1;i<n+1;i++)
  {
    if(stu[i]==0)
    cout<<i<<" ";
  }

}

int main()
{
  int n;
  cin>>n;
  vi a,ab;
  rep(i,n)
  {
    int temp;
    cin>>temp;
    a.pb(temp);
  }

  func(n,a);
  return 0;
}
