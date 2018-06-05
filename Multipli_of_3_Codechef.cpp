//https://www.codechef.com/problems/MULTHREE
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i,k) for(int i=0;i<k;i++)

string checkMultiple(lli k, int d0,int d1)
{
  vector<int> arr(k),brr(k);
  arr[0]=d0;
  arr[1]=d1;


  lli sum=d0+d1;
  for(lli i =2;i<k;i++)
  {
    arr[i]=(sum%10);
    sum=sum+arr[i];
  }
  if(sum%3==0)
  return "YES";
  else return "NO";
}

int main()
{
  int t;
  cin>>t;
  f(i,t)
  {
    lli k;
    int d0,d1;
    cin>>k>>d0>>d1;
    string result = checkMultiple(k,d0,d1);
    cout<<result<<endl;
  }


  return 0;
}
