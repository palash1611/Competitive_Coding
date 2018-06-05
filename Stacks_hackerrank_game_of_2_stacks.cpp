#include <bits/stdc++.h>

using namespace std;
void show_stack(stack<int> st){

  stack <int> s=st;

  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}

stack<int> reverse_stack(stack<int> s)
{
  stack<int> t;
  while(!s.empty())
  {
    t.push(s.top());
    s.pop();
  }

  return t;

}
int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        stack<int> s11,s22,s1,s2;
        int v1,v2;

        for(int a_i = 0; a_i < n; a_i++){
           cin >> v1;
            s11.push(v1);
        }

        for(int b_i = 0; b_i < m; b_i++){
           cin >> v2;
            s22.push(v2);
        }
/*
        show_stack(s11);
        cout<<endl;
        show_stack(s22);
        cout<<endl;
*/
        s1=reverse_stack(s11);
        s2=reverse_stack(s22);

      /*  show_stack(s1);
        cout<<endl;
        show_stack(s2);
        cout<<endl;
        */
        int sum,count;
        sum=0;

        while(sum<=x)
        {
            if(s1.top()<=s2.top())
            {
                sum+=s1.top();
                count++;
                s1.pop();
            }
            else
            {
                sum+=s2.top();
                count++;
                s2.pop();
            }
        }

        cout<<count-1<<endl;

        // your code goes here
    }
    return 0;
}
