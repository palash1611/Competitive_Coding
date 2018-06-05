#include <bits/stdc++.h>
#define li long long
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    li t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       stack<pair<char,li>>q;
       li maxi=0;
       q.push({'f',-1});
       for(li i=0;i<s.size();i++){
           if(s[i]=='('){
                q.push({'(',i});
              }
            else if(s[i]==')'){
                if(!q.empty()&&q.top().first=='('){
                    q.pop();
                    maxi=max(maxi,i-q.top().second);
                }
                else{
                    q.push({')',i});
                }
            }
       }
       cout<<maxi<<endl;


    }



}
