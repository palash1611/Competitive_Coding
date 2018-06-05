
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        //int t=0;
        int flag=0;
        int ans=0;
        int clap=0;
        int var=0;
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                k++;
                if(var)
                k=1;
                if(flag)
                {
                flag=0;
                clap=0;
                }
                var=1;
            }
            else
            {
                if(k>=1)
                {
                  //var=2+var;
                  k--;
                  flag=1;
                  clap=1;
                }
                if(clap)
                ans=ans+2;
                var=0;
            }
            cout<<s[i]<<" flag "<<flag<<" ans "<<ans<<" clap "<<clap<<" k "<<k<<" var "<<var<<endl;

        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      string s;
      cin>>s;
      int ans=0;
      int k=0;
      for(int i=0;i<s.length();i++)
      {
          if(s[i]=='(')
          {
              k++;
          }
          else
          {
              if(k>=1)
              {
                k--;
              ans=ans+2;
              }
          }
      }
      cout<<ans<<endl;
  }
  return 0;
}*/



/*
#include <bits/stdc++.h>

using namespace std;

char str[10000];
int i, cur, mx=0;
int main(){
	int t;
	cin>>t;
	stack <int> s;
	while(t--){
		cin>>str;
		for (i=0; i<strlen(str); i++){
			if (str[i] == '('){
				s.push(cur);
				cur=0;
			}
			if (str[i] == ')' && s.size()>0){
				cur = s.top() + 2;
				s.pop();
				mx = max(mx, cur);
			}
			if (str[i] == ')' && s.size()==0){
				cur = 0;
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}*/
