//FLAMES

#include<bits/stdc++.h>
using namespace std;

int main()
{
  char n1[100],n2[100],sn[100],ln[100];

  cin>>n1>>n2;

  int l1=strlen(n1);
  int l2=strlen(n2);
  int l=0;

  int count=0;
  for(int i=0;i<l1;i++)
  {
    for(int j=l;j<l2;j++)
    {
      char c1=tolower(n1[i]);
      char c2=tolower(n2[j]);

      if(c1==c2)
      {count++;n2[j]='*';break;}
    }
  }

//  cout<<endl<<count;

  int iter = l1+l2-(2*count);

  cout<<l1<<","<<l2<<","<<iter;

  string s="flames";

  for(int i=0;i<iter-1;i++)
  {
    int l = s.length();
    while(l!=1)
    {
      int e=iter%l;
      s.erase(e);
      l--;

      cout<<endl<<s<<endl;
    }
  }

  cout<<s;
  return 0;
}
